/* Copyright (c) 2010 maidsafe.net limited
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    * Neither the name of the maidsafe.net limited nor the names of its
    contributors may be used to endorse or promote products derived from this
    software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <boost/asio/ip/address.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/signals2/signal.hpp>
#include <boost/cstdint.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>
#include <gtest/gtest.h>
#include <list>
#include <set>
#include <string>
#include "maidsafe/protobuf/transport_message.pb.h"
#include "maidsafe/protobuf/kademlia_service_messages.pb.h"
#include "maidsafe/tests/transport/messagehandler.h"
#include "maidsafe/tests/transport/udttestshelpers.h"
#include "maidsafe/transport/transport.h"
#include "maidsafe/transport/transportsignals.h"
#include "maidsafe/transport/udtconnection.h"
#include "maidsafe/transport/udttransport.h"
#include "maidsafe/base/log.h"
#include "maidsafe/base/routingtable.h"
#include "maidsafe/base/utils.h"
#include "maidsafe/udt/api.h"


namespace transport {

namespace test {

TransportMessage MakeDummyTransportMessage(bool is_request) {
  TransportMessage transport_message;
  if (is_request)
    transport_message.set_type(TransportMessage::kRequest);
  else
    transport_message.set_type(TransportMessage::kResponse);
  rpcprotocol::RpcMessage *rpc_message =
      transport_message.mutable_data()->mutable_rpc_message();
  rpc_message->set_rpc_id(base::RandomUint32());
  rpc_message->set_method("Method");
  rpcprotocol::RpcMessage::Detail *payload = rpc_message->mutable_detail();
  kad::NatDetectionPingRequest *request = payload->MutableExtension(
      kad::NatDetectionPingRequest::nat_detection_ping_request);
  request->set_ping(base::RandomString(256 * 1024));
  rpc_message->set_service("Service");
  return transport_message;
}

class UdtTransportTest: public testing::Test {
 protected:
  UdtTransportTest() : listening_node_(),
                       listening_message_handler_(listening_node_.signals(),
                                                  "Listening", false),
                       listening_port_(0),
                       loopback_ip_("127.0.0.1") {}
  void SetUp() {
    listening_port_ = listening_node_.StartListening("", 0, NULL);
    ASSERT_TRUE(ValidPort(listening_port_));
  }
  UdtTransport listening_node_;
  MessageHandler listening_message_handler_;
  Port listening_port_;
  IP loopback_ip_;
};

TEST_F(UdtTransportTest, BEH_TRANS_UdtSendOneMessageFromOneToAnother) {
  // Set up sending node and message
  UdtTransport sending_node;
  MessageHandler sending_message_handler(sending_node.signals(), "Send", false);
  TransportMessage request = MakeDummyTransportMessage(true);
  const std::string kSentRpcRequest =
      request.data().rpc_message().SerializeAsString();

  // Send message
  UdtSocketId sending_socket_id =
      sending_node.Send(request, loopback_ip_, listening_port_, 10000);
  ASSERT_GT(sending_socket_id, 0);
  const int kTimeout(10000);
  int count(0);
  while (count < kTimeout &&
         listening_message_handler_.rpc_requests().empty()) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }

  // Assess results and get receiving socket's ID
  ASSERT_EQ(1U, sending_message_handler.sent_results().size());
  boost::tuple<SocketId, TransportCondition> signalled_sent_result =
      sending_message_handler.sent_results().back();
  EXPECT_EQ(sending_socket_id, signalled_sent_result.get<0>());
  EXPECT_EQ(kSuccess, signalled_sent_result.get<1>());
  ASSERT_EQ(1U, listening_message_handler_.rpc_requests().size());
  boost::tuple<rpcprotocol::RpcMessage, SocketId, float> signalled_rpc_message =
      listening_message_handler_.rpc_requests().back();
  EXPECT_EQ(kSentRpcRequest,
            signalled_rpc_message.get<0>().SerializeAsString());
  UdtSocketId receiving_socket_id = signalled_rpc_message.get<1>();

  // Send reply
  TransportMessage response = MakeDummyTransportMessage(false);
  const std::string kSentRpcResponse =
      response.data().rpc_message().SerializeAsString();
  listening_node_.SendResponse(response, receiving_socket_id);
  count = 0;
  while (count < kTimeout &&
         sending_message_handler.rpc_responses().empty()) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }

  // Assess results
  ASSERT_EQ(1U, listening_message_handler_.sent_results().size());
  signalled_sent_result = listening_message_handler_.sent_results().back();
  EXPECT_EQ(receiving_socket_id, signalled_sent_result.get<0>());
  EXPECT_EQ(kSuccess, signalled_sent_result.get<1>());
  ASSERT_EQ(1U, sending_message_handler.rpc_responses().size());
  signalled_rpc_message = sending_message_handler.rpc_responses().back();
  EXPECT_EQ(kSentRpcResponse,
            signalled_rpc_message.get<0>().SerializeAsString());
  EXPECT_EQ(sending_socket_id, signalled_rpc_message.get<1>());
  EXPECT_FALSE(SocketAlive(sending_socket_id));
  EXPECT_FALSE(SocketAlive(receiving_socket_id));
}

TEST_F(UdtTransportTest, BEH_TRANS_UdtMultipleListeningPorts) {
  // Start listening ports
  const boost::uint16_t kNumberOfListeningPorts = 12;
  std::vector<Port> listening_ports;
  listening_ports.push_back(listening_port_);
  for (int i = 0; i < kNumberOfListeningPorts - 1 ; ++i) {
    Port listening_port = listening_node_.StartListening("", 0, NULL);
    EXPECT_TRUE(ValidPort(listening_port));
    listening_ports.push_back(listening_port);
  }
  EXPECT_EQ(kNumberOfListeningPorts, listening_node_.listening_ports().size());

  // Send a message to each
  TransportMessage transport_message = MakeDummyTransportMessage(true);
  for (int i = 0; i < kNumberOfListeningPorts ; ++i) {
    listening_node_.Send(transport_message, loopback_ip_, listening_ports.at(i),
                         0);
  }
  const int kTimeout(10000);
  int count(0);
  while (count < kTimeout &&
         listening_message_handler_.rpc_requests().size() !=
         kNumberOfListeningPorts) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(30));
    count += 30;
  }
  EXPECT_EQ(kNumberOfListeningPorts,
            listening_message_handler_.rpc_requests().size());
  EXPECT_EQ(listening_message_handler_.rpc_requests().size(),
            listening_message_handler_.sent_results().size());
  EXPECT_TRUE(listening_node_.StopAllListening());
}

TEST_F(UdtTransportTest, BEH_TRANS_UdtSendMessagesFromManyToOne) {
  UdtTransport node1;
  UdtTransport node[20];
  MessageHandler message_handler4(node1.signals(), "Node 1", false);
  Port lp_node4 = node1.StartListening("", 0, NULL);
  TransportMessage transport_message;
  transport_message.set_type(TransportMessage::kRequest);
  rpcprotocol::RpcMessage *rpc_message =
  transport_message.mutable_data()->mutable_rpc_message();
  rpc_message->set_rpc_id(2000);
  rpc_message->set_method("Test");
  rpcprotocol::RpcMessage::Detail *payload = rpc_message->mutable_detail();
  kad::NatDetectionPingRequest *request = payload->MutableExtension(
      kad::NatDetectionPingRequest::nat_detection_ping_request);
  const std::string args = base::RandomString(256 * 1024);
  request->set_ping(args);
  rpc_message->set_service("Service");
  std::string sent_message;
  rpc_message->SerializeToString(&sent_message);
//  sent_messages.push_back(sent_message);
  for (int i =0; i < 20 ; ++i) {
    node[i].Send(transport_message, loopback_ip_, lp_node4, 0);
  }
  node1.StopAllListening();
  for (int i =0; i < 20 ; ++i) {
    node[i].StopAllListening();
  }
}

TEST_F(UdtTransportTest, BEH_TRANS_UdtManyBigMessages) {
/*
  TransportMessage sent_message;
  std::string *sent_raw_message =
      sent_message.mutable_data()->mutable_raw_message();
  try {
    sent_raw_message->assign(base::RandomString(kMaxTransportMessageSize - 12));
  }
  catch(const std::exception &e) {
    FAIL() << e.what() << std::endl;
  }
  sent_message.set_type(TransportMessage::kResponse);
  UdtConnection udt_connection(loopback_ip_, listening_port_, "", 0);
  UdtSocketId sending_socket_id = udt_connection.udt_socket_id();
  ASSERT_GT(sending_socket_id, 0);
  MessageHandler message_handler(udt_connection.signals(), "BigSend", false);
  udt_connection.Send(sent_message, -1);
  const int kTimeout(10000);
  UdtSocketId receiving_socket_id;

  //EXPECT_TRUE(WaitForRawMessage(kTimeout, *sent_raw_message, 1,
  //            &listening_message_handler_, &receiving_socket_id));
  ASSERT_EQ(1U, message_handler.sent_results().size());
  boost::tuple<SocketId, TransportCondition> signalled_message_result =
      message_handler.sent_results().back();
  EXPECT_EQ(sending_socket_id, signalled_message_result.get<0>());
  EXPECT_EQ(kSuccess, signalled_message_result.get<1>());
  EXPECT_FALSE(SocketAlive(sending_socket_id));
  EXPECT_FALSE(SocketAlive(receiving_socket_id));  */
}

TEST_F(UdtTransportTest, BEH_TRANS_UdtAddRemoveManagedEndpoints) {
  UdtTransport node1, node2, node3, node4, node5;
  MessageHandler message_handler1(node1.signals(), "Node 1", false);
  MessageHandler message_handler3(node3.signals(), "Node 3", false);
  Port node1_port = node1.StartListening("", 0, NULL);
  Port node2_port = node2.StartListening("", 0, NULL);
  Port node3_port = node3.StartListening("", 0, NULL);
  Port node4_port = node4.StartListening("", 0, NULL);
  Port node5_port = node5.StartListening("", 0, NULL);
  ManagedEndpointId node1_end1 =
    node1.AddManagedEndpoint(loopback_ip_, node2_port, "", 0, "Node1", 0, 0, 0);
  EXPECT_EQ(1, node1.managed_endpoint_sockets_.size());
  ManagedEndpointId node1_end2 =
    node1.AddManagedEndpoint(loopback_ip_, node3_port, "", 0, "Node1", 0, 0, 0);
  EXPECT_EQ(2, node1.managed_endpoint_sockets_.size());
  EXPECT_TRUE(node1.RemoveManagedEndpoint(node1_end2));
  const int kTimeout(10000);
  int count(0);
  while (count < kTimeout &&
         message_handler3.lost_managed_endpoint_ids().empty()) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }
  EXPECT_EQ(size_t(1), message_handler3.lost_managed_endpoint_ids().size());
  EXPECT_EQ(1, node1.managed_endpoint_sockets_.size());
  node1_end2 =
    node1.AddManagedEndpoint(loopback_ip_, node3_port, "", 0, "Node1", 0, 0, 0);
  EXPECT_EQ(2, node1.managed_endpoint_sockets_.size());
  ManagedEndpointId node1_end3 =
    node1.AddManagedEndpoint(loopback_ip_, node4_port, "", 0, "Node1", 0, 0, 0);
  EXPECT_EQ(3, node1.managed_endpoint_sockets_.size());
  ManagedEndpointId node1_end4 =
    node1.AddManagedEndpoint(loopback_ip_, node5_port, "", 0, "Node1", 0, 0, 0);
  EXPECT_EQ(4, node1.managed_endpoint_sockets_.size());
  EXPECT_TRUE(SocketAlive(node1_end1));
  node1.StopManagedConnections();
  ASSERT_TRUE(node1.stop_managed_connections_);
  EXPECT_FALSE(SocketAlive(node1_end1));
  EXPECT_FALSE(SocketAlive(node1_end2));
  EXPECT_FALSE(SocketAlive(node1_end3));
  EXPECT_FALSE(SocketAlive(node1_end4));
  count = 0;
  while (count < kTimeout && !node1.managed_endpoint_sockets_.empty()) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }
  EXPECT_EQ(0, node1.managed_endpoint_sockets_.size());
}

TEST_F(UdtTransportTest, BEH_TRANS_UdtCrashManagedEndpoints) {
  // Setup managed connections between three nodes.
  boost::shared_ptr<UdtTransport> node1_ptr(new UdtTransport());
  UdtTransport node2, node3;
  MessageHandler message_handler2(node2.signals(), "Node 2", false);
  MessageHandler message_handler3(node3.signals(), "Node 3", false);
  Port node1_port = node1_ptr->StartListening("", 0, NULL);
  Port node2_port = node2.StartListening("", 0, NULL);
  Port node3_port = node3.StartListening("", 0, NULL);
  ManagedEndpointId node1_to_node2 = node1_ptr->AddManagedEndpoint(loopback_ip_,
      node2_port, "", 0, "Node1", 0, 0, 0);
  ASSERT_LT(0, node1_to_node2);
  ManagedEndpointId node2_to_node3 = node2.AddManagedEndpoint(loopback_ip_,
      node3_port, "", 0, "Node2", 0, 0, 0);
  ASSERT_LT(0, node2_to_node3);
  ManagedEndpointId node3_to_node1 = node3.AddManagedEndpoint(loopback_ip_,
      node1_port, "", 0, "Node3", 0, 0, 0);
  ASSERT_LT(0, node3_to_node1);

  // Stop Node 1's managed connections - Nodes 2 & 3 should each detect a lost
  // connection.
  node1_ptr->StopManagedConnections();
  const int kTimeout(kAddManagedConnectionTimeout * 2);
  int count(0);
  while (count < kTimeout &&
         message_handler2.lost_managed_endpoint_ids().empty()) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }
  EXPECT_EQ(size_t(1), message_handler2.lost_managed_endpoint_ids().size());
  count = 0;
  while (count < kTimeout &&
         message_handler3.lost_managed_endpoint_ids().empty()) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }
  EXPECT_EQ(size_t(1), message_handler3.lost_managed_endpoint_ids().size());

  // Stop Node 2's managed connections - Node 3 should detect a lost connection.
  node2.StopManagedConnections();
  count = 0;
  while (count < kTimeout &&
         message_handler3.lost_managed_endpoint_ids().size() != size_t(2)) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }
  EXPECT_EQ(size_t(1), message_handler2.lost_managed_endpoint_ids().size());
  EXPECT_EQ(size_t(2), message_handler3.lost_managed_endpoint_ids().size());

  // Try to reconnect to Node 2 - should fail.
  node1_to_node2 = node1_ptr->AddManagedEndpoint(loopback_ip_, node2_port, "",
                                                 0, "Node1", 0, 0, 0);
  ASSERT_GE(0, node1_to_node2);

  // Re-enable managed connections on Node 2 & try to reconnect - should pass.
  node2.ReAllowIncomingManagedConnections();
  node1_to_node2 = node1_ptr->AddManagedEndpoint(loopback_ip_, node2_port, "",
                                                 0, "Node1", 0, 0, 0);
  ASSERT_LT(0, node1_to_node2);

  // Destroy Node 1 - Node 2 should detect a lost connection.
  node1_ptr.reset();
  count = 0;
  while (count < kTimeout &&
         message_handler2.lost_managed_endpoint_ids().size() != size_t(2)) {
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    count += 10;
  }
  EXPECT_EQ(size_t(2), message_handler2.lost_managed_endpoint_ids().size());
}

}  // namespace test

}  // namespace transport
