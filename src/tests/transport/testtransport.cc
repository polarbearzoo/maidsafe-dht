/* Copyright (c) 2009 maidsafe.net limited
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

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/progress.hpp>
#include <boost/cstdint.hpp>
#include <gtest/gtest.h>
#include <list>
#include <string>
#include "maidsafe/maidsafe-dht_config.h"
#include "transport/transportapi.h"

void send_string(transport::Transport* node,
                 int port,
                 int repeat,
                 std::string msg,
                 bool keep_conn) {
  boost::uint32_t id;
  boost::asio::ip::address local_address;
  std::string ip;
  if (base::get_local_address(&local_address)) {
    ip = local_address.to_string();
  } else {
    ip = std::string("127.0.0.1");
  }
  int sent = 0;
  for (int i = 0; i < repeat; ++i) {
    if (node->Send(ip, port, "", 0, msg,
        transport::Transport::STRING, &id, keep_conn) != 0)
      printf("fail to send\n");
    else sent++;
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
  printf("thread finished sending %i messages\n", sent);
}

class MessageHandler {
 public:
  MessageHandler(): msgs(), ids(), dead_server_(true), server_ip_(),
    server_port_(0) {}
  void OnMessage(const std::string &message, const boost::uint32_t conn_id) {
    msgs.push_back(message);
    ids.push_back(conn_id);
    printf("message %i arrived\n", msgs.size());
  }
  void OnDeadRendezvousServer(const bool &dead_server, const std::string &ip,
    const boost::uint16_t &port) {
    dead_server_ = dead_server;
    server_ip_ = ip;
    server_port_ = port;
  }
  std::list<std::string> msgs;
  std::list<boost::uint32_t> ids;
  bool dead_server_;
  std::string server_ip_;
  boost::uint16_t server_port_;
};

class MessageHandlerEchoReq {
 public:
  MessageHandlerEchoReq(transport::Transport *node) : node_(node), msgs(), ids(),
    dead_server_(true), server_ip_(), server_port_(0) {}
   void OnMessage(const std::string &message, const boost::uint32_t conn_id) {
    msgs.push_back(message);
    ids.push_back(conn_id);
    printf("message %i arrived\n", msgs.size());
    // replying same msg
    if (msgs.size() < 10)
      node_->Send(conn_id, message, transport::Transport::STRING);
  }
  void OnDeadRendezvousServer(const bool &dead_server, const std::string &ip,
    const boost::uint16_t &port) {
    dead_server_ = dead_server;
    server_ip_ = ip;
    server_port_ = port;
  }
  transport::Transport *node_;
  std::list<std::string> msgs;
  std::list<boost::uint32_t> ids;
  bool dead_server_;
  std::string server_ip_;
  boost::uint16_t server_port_;
};

class MessageHandlerEchoResp {
 public:
  MessageHandlerEchoResp(transport::Transport *node) : node_(node), msgs(), ids(),
    dead_server_(true), server_ip_(), server_port_(0) {}
   void OnMessage(const std::string &message, const boost::uint32_t conn_id) {
    msgs.push_back(message);
    ids.push_back(conn_id);
    printf("message %i arrived\n", msgs.size());
    // replying same msg
    node_->CloseConnection(conn_id);
  }
  void OnDeadRendezvousServer(const bool &dead_server, const std::string &ip,
    const boost::uint16_t &port) {
    dead_server_ = dead_server;
    server_ip_ = ip;
    server_port_ = port;
  }
  transport::Transport *node_;
  std::list<std::string> msgs;
  std::list<boost::uint32_t> ids;
  bool dead_server_;
  std::string server_ip_;
  boost::uint16_t server_port_;
};

class TransportTest: public testing::Test {
 protected:
  TransportTest() {
  }
  virtual ~TransportTest() {
    UDT::cleanup();
  }
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

TEST_F(TransportTest, BEH_TRANS_SendOneMessageFromOneToAnother) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  std::string sent_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, false));
  while (msg_handler[1].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  printf("stopping nodes\n");
  node1.Stop();
  node2.Stop();
  ASSERT_TRUE(msg_handler[0].msgs.empty());
  ASSERT_FALSE(msg_handler[1].msgs.empty());
  ASSERT_EQ(sent_msg, msg_handler[1].msgs.front());
}

TEST_F(TransportTest, BEH_TRANS_SendMessagesFromManyToOne) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  transport::Transport node3;
  transport::Transport node4;
  MessageHandler msg_handler[4];
  node1.Start(52000,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3));
  node2.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3));
  node3.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[2], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[2],
                _1, _2, _3));
  node4.Start(52003,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[3], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[3],
                _1, _2, _3));
  std::list<std::string> sent_msgs;
  sent_msgs.push_back(base::RandomString(64*1024));
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52003, "", 0, sent_msgs.back(),
      transport::Transport::STRING, &id, false));
  sent_msgs.push_back(base::RandomString(64*1024));
  ASSERT_EQ(0, node2.Send("127.0.0.1", 52003, "", 0, sent_msgs.back(),
      transport::Transport::STRING, &id, false));
  sent_msgs.push_back(base::RandomString(64*1024));
  ASSERT_EQ(0, node3.Send("127.0.0.1", 52003, "", 0, sent_msgs.back(),
      transport::Transport::STRING, &id, false));
  printf("messages sent correctly\n");
  boost::uint32_t now = base::get_epoch_time();
  bool msgs_received = false;
  boost::mutex mutex;
  while (!msgs_received && base::get_epoch_time() - now < 15) {
    {
      boost::mutex::scoped_lock guard(mutex);
      if (msg_handler[3].msgs.size() >= 3)
        msgs_received = true;
    }
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  }
  node1.Stop();
  node2.Stop();
  node3.Stop();
  node4.Stop();
  for (int i = 0; i < 3; i++) {
    ASSERT_TRUE(msg_handler[i].msgs.empty());
  }
  ASSERT_FALSE(msg_handler[3].msgs.empty());
  ASSERT_EQ(msg_handler[3].msgs.size(), static_cast<unsigned int>(3));
  msg_handler[3].msgs.sort();
  sent_msgs.sort();
  for (int i = 0; i < 3; i++) {
    ASSERT_EQ(msg_handler[3].msgs.front(), sent_msgs.front());
    msg_handler[3].msgs.pop_front();
    sent_msgs.pop_front();
  }
}

TEST_F(TransportTest, BEH_TRANS_SendMessagesFromManyToMany) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  transport::Transport node3;
  transport::Transport node4;
  transport::Transport node5;
  transport::Transport node6;
  MessageHandler msg_handler[6];
  ASSERT_EQ(0, node1.Start(52000,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  ASSERT_EQ(0, node3.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[2], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[2],
                _1, _2, _3)));
  ASSERT_EQ(0, node4.Start(52003,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[3], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[3],
                _1, _2, _3)));
  ASSERT_EQ(0, node5.Start(52004,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[4], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[4],
                _1, _2, _3)));
  ASSERT_EQ(0, node6.Start(52005,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[5], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[5],
                _1, _2, _3)));
  std::string sent_msgs[3];
  sent_msgs[0] = base::RandomString(64*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52003, "", 0, sent_msgs[0],
    transport::Transport::STRING, &id, false));
  sent_msgs[1] = base::RandomString(64*1024);
  ASSERT_EQ(0, node2.Send("127.0.0.1", 52004, "", 0, sent_msgs[1],
    transport::Transport::STRING, &id, false));
  sent_msgs[2] = base::RandomString(64*1024);
  ASSERT_EQ(0, node3.Send("127.0.0.1", 52005, "", 0, sent_msgs[2],
    transport::Transport::STRING, &id, false));
  boost::uint32_t now = base::get_epoch_time();
  bool msgs_received[3] = {false, false, false};
  boost::mutex mutex1;
  boost::mutex mutex2;
  boost::mutex mutex3;
  while ((!msgs_received[0] || !msgs_received[1] || !msgs_received[2]) &&
          base::get_epoch_time() - now < 15) {
    {
      boost::mutex::scoped_lock guard(mutex1);
      if (msg_handler[3].msgs.size() >= 1)
        msgs_received[0] = true;
    }
    {
      boost::mutex::scoped_lock guard(mutex2);
      if (msg_handler[4].msgs.size() >= 1)
        msgs_received[1] = true;
    }
    {
      boost::mutex::scoped_lock guard(mutex3);
      if (msg_handler[5].msgs.size() >= 1)
        msgs_received[2] = true;
    }
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  }
  node1.Stop();
  node2.Stop();
  node3.Stop();
  node4.Stop();
  node5.Stop();
  node6.Stop();
  for (int i = 0; i < 3; i++) {
    ASSERT_TRUE(msg_handler[i].msgs.empty());
  }
  for (int i = 3; i < 6; i++) {
    ASSERT_EQ(static_cast<unsigned int>(1), msg_handler[i].msgs.size());
    ASSERT_EQ(msg_handler[i].msgs.front(), sent_msgs[i-3]);
  }
}

TEST_F(TransportTest, BEH_TRANS_SendMessagesFromOneToMany) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  transport::Transport node3;
  transport::Transport node4;
  MessageHandler msg_handler[4];
  ASSERT_EQ(0, node1.Start(52000,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  ASSERT_EQ(0, node3.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[2], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[2],
                _1, _2, _3)));
  ASSERT_EQ(0, node4.Start(52003,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[3], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[3],
                _1, _2, _3)));
  std::string sent_msgs[3];
  sent_msgs[0] = base::RandomString(64*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52001, "", 0, sent_msgs[0],
    transport::Transport::STRING, &id, false));
  sent_msgs[1] = base::RandomString(64*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msgs[1],
    transport::Transport::STRING, &id, false));
  sent_msgs[2] = base::RandomString(64*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52003, "", 0, sent_msgs[2],
    transport::Transport::STRING, &id, false));

  boost::uint32_t now = base::get_epoch_time();
  bool msgs_received[3] = {false, false, false};
  boost::mutex mutex1;
  boost::mutex mutex2;
  boost::mutex mutex3;
  while ((!msgs_received[0] || !msgs_received[1] || !msgs_received[2]) &&
          base::get_epoch_time() - now < 15) {
    {
      boost::mutex::scoped_lock guard(mutex1);
      if (msg_handler[1].msgs.size() >= 1)
        msgs_received[0] = true;
    }
    {
      boost::mutex::scoped_lock guard(mutex2);
      if (msg_handler[2].msgs.size() >= 1)
        msgs_received[1] = true;
    }
    {
      boost::mutex::scoped_lock guard(mutex3);
      if (msg_handler[3].msgs.size() >= 1)
        msgs_received[2] = true;
    }
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  }
  node1.Stop();
  node2.Stop();
  node3.Stop();
  node4.Stop();
  ASSERT_TRUE(msg_handler[0].msgs.empty());
  for (int i = 0; i < 3; i++) {
    ASSERT_EQ(static_cast<unsigned int>(1), msg_handler[i+1].msgs.size());
    ASSERT_EQ(msg_handler[i+1].msgs.front(), sent_msgs[i]);
  }
}

TEST_F(TransportTest, BEH_TRANS_TimeoutForSendingToAWrongPeer) {
  boost::uint32_t id;
  transport::Transport node1;
  MessageHandler msg_handler[1];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  std::string sent_msg = base::RandomString(64*1024);
  ASSERT_EQ(1, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, false));
  boost::this_thread::sleep(boost::posix_time::seconds(1));
  node1.Stop();
}

TEST_F(TransportTest, BEH_TRANS_Send100Files) {
  const int kNumNodes = 11;
  const int kRepeatSend = 10;  // No. of times to repeat the send message.
  ASSERT_LT(2, kNumNodes);  // ensure enough nodes for test
  EXPECT_LT(1, kRepeatSend);  // ensure enough repeats to make test worthwhile
  const int kFirstPort = 52000;
  MessageHandler msg_handler[kNumNodes];
  transport::Transport* nodes[kNumNodes];
  boost::thread_group thr_grp;
  boost::thread *thrd;
  std::string sent_msg = base::RandomString(256*1024);
  for (int i = 0; i < kNumNodes; ++i) {
    transport::Transport *trans = new transport::Transport;
    ASSERT_EQ(0, trans->Start(kFirstPort+i,
      boost::bind(&MessageHandler::OnMessage, &msg_handler[i], _1, _2),
      boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[i],
                  _1, _2, _3)));
    if (i != 0) {
      thrd = new boost::thread(boost::bind(&send_string, trans,
                                           kFirstPort, kRepeatSend, sent_msg,
                                           false));
      thr_grp.add_thread(thrd);
      boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    }
    nodes[i] = trans;
  }

  thr_grp.join_all();
  unsigned int messages_size = (kNumNodes - 1) * kRepeatSend;
  printf("messages_size = %i\n", messages_size);

  bool finished = false;
  boost::progress_timer t;
  while (!finished && t.elapsed() < 3) {
      if (msg_handler[0].msgs.size() >= messages_size) {
        finished = true;
        continue;
      }
    boost::this_thread::sleep(boost::posix_time::seconds(5));
  }

  for (int k = 0; k < kNumNodes; ++k)
    nodes[k]->Stop();
  ASSERT_EQ(messages_size, msg_handler[0].msgs.size());
  while (!msg_handler[0].msgs.empty()) {
    std::string msg = msg_handler[0].msgs.back();
    EXPECT_EQ(sent_msg, msg);
    msg_handler[0].msgs.pop_back();
  }
  for (int k = 0; k < kNumNodes; ++k)
    delete nodes[k];
}

TEST_F(TransportTest, BEH_TRANS_GetRemotePeerAddress) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  std::string sent_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, false));
  boost::this_thread::sleep(boost::posix_time::seconds(1));
  struct sockaddr peer_addr = node2.peer_address();
  std::string peer_ip(inet_ntoa(((struct sockaddr_in *)&peer_addr)->sin_addr));
  boost::uint16_t peer_port =
    ntohs(((struct sockaddr_in *)&peer_addr)->sin_port);
  ASSERT_EQ("127.0.0.1", peer_ip);
  ASSERT_EQ(52001, peer_port);
  node1.Stop();
  node2.Stop();
}

TEST_F(TransportTest, BEH_TRANS_SendOneMessageFromOneToAnotherBidirectional) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  std::string sent_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, true));
  while (msg_handler[1].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  // replying on same channel
  ASSERT_FALSE(msg_handler[1].msgs.empty());
  ASSERT_FALSE(msg_handler[1].ids.empty());
  std::string reply_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node2.Send(msg_handler[1].ids.front(), reply_msg,
    transport::Transport::STRING));
  while (msg_handler[0].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  // Closing the connection
  node1.CloseConnection(msg_handler[0].ids.front());
  node2.CloseConnection(msg_handler[1].ids.front());
  node1.Stop();
  node2.Stop();
  ASSERT_FALSE(msg_handler[0].msgs.empty());
  ASSERT_EQ(sent_msg, msg_handler[1].msgs.front());
  ASSERT_EQ(reply_msg, msg_handler[0].msgs.front());
}

TEST_F(TransportTest, FUNC_TRANS_SendMessagesFromManyToOneBidirectional) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  transport::Transport node3;
  transport::Transport node4;
  MessageHandler msg_handler[4];
  node1.Start(52000,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3));
  node2.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3));
  node3.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[2], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[2],
                _1, _2, _3));
  node4.Start(52003,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[3], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[3],
                _1, _2, _3));
  std::list<std::string> sent_msgs;
  sent_msgs.push_back(base::RandomString(64*1024));
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52003, "", 0, sent_msgs.back(),
      transport::Transport::STRING, &id, true));
  sent_msgs.push_back(base::RandomString(64*1024));
  ASSERT_EQ(0, node2.Send("127.0.0.1", 52003, "", 0, sent_msgs.back(),
      transport::Transport::STRING, &id, true));
  sent_msgs.push_back(base::RandomString(64*1024));
  ASSERT_EQ(0, node3.Send("127.0.0.1", 52003, "", 0, sent_msgs.back(),
      transport::Transport::STRING, &id, true));
  // waiting for all messages to be delivered
  while (msg_handler[3].msgs.size() != 3)
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  // node4 responding to all nodes
  std::list<boost::uint32_t>::iterator it;
  std::string reply_str = base::RandomString(64*1024);
  for (it = msg_handler[3].ids.begin(); it != msg_handler[3].ids.end(); it++) {
    ASSERT_EQ(0, node4.Send(*it, reply_str, transport::Transport::STRING));
  }
  // waiting for all replies to arrive
  while (msg_handler[0].msgs.empty() || msg_handler[1].msgs.empty() ||
         msg_handler[2].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));

  for (it = msg_handler[0].ids.begin(); it != msg_handler[0].ids.end(); it++)
    node1.CloseConnection(*it);
  for (it = msg_handler[1].ids.begin(); it != msg_handler[1].ids.end(); it++)
    node2.CloseConnection(*it);
  for (it = msg_handler[2].ids.begin(); it != msg_handler[2].ids.end(); it++)
    node3.CloseConnection(*it);
  for (it = msg_handler[3].ids.begin(); it != msg_handler[3].ids.end(); it++)
    node3.CloseConnection(*it);

  node1.Stop();
  node2.Stop();
  node3.Stop();
  node4.Stop();
  for (int i = 0; i < 4; i++) {
    ASSERT_FALSE(msg_handler[i].msgs.empty());
  }
  ASSERT_FALSE(msg_handler[3].msgs.empty());
  ASSERT_EQ(msg_handler[3].msgs.size(), static_cast<unsigned int>(3));
  msg_handler[3].msgs.sort();
  sent_msgs.sort();
  for (int i = 0; i < 3; i++) {
    ASSERT_EQ(msg_handler[3].msgs.front(), sent_msgs.front());
    msg_handler[3].msgs.pop_front();
    sent_msgs.pop_front();
    ASSERT_EQ(static_cast<unsigned int>(1), msg_handler[i].msgs.size());
    ASSERT_EQ(reply_str, msg_handler[i].msgs.front());
  }
}

TEST_F(TransportTest, BEH_TRANS_SendOneMessageCloseAConnection) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  std::string sent_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, true));
  while (msg_handler[1].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  // replying on same channel
  ASSERT_FALSE(msg_handler[1].msgs.empty());
  ASSERT_FALSE(msg_handler[1].ids.empty());
  std::string reply_msg = base::RandomString(256*1024);
  node1.CloseConnection(id);
  boost::this_thread::sleep(boost::posix_time::seconds(1));
  ASSERT_EQ(1, node2.Send(msg_handler[1].ids.front(), reply_msg,
    transport::Transport::STRING));
  boost::this_thread::sleep(boost::posix_time::seconds(1));
  // Closing the connection
  node1.Stop();
  node2.Stop();
  ASSERT_TRUE(msg_handler[0].msgs.empty());
  ASSERT_EQ(sent_msg, msg_handler[1].msgs.front());
}

TEST_F(TransportTest, FUNC_TRANS_PingRendezvousServer) {
  transport::Transport node1;
  transport::Transport rendezvous_node;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, rendezvous_node.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  node1.StartPingRendezvous(false, "127.0.0.1", 52002);
  boost::this_thread::sleep(boost::posix_time::seconds(20));
  node1.Stop();
  ASSERT_FALSE(msg_handler[0].dead_server_);
  ASSERT_EQ(std::string(""), msg_handler[0].server_ip_);
  ASSERT_EQ(0, msg_handler[0].server_port_);
  rendezvous_node.Stop();
}

TEST_F(TransportTest, FUNC_TRANS_PingDeadRendezvousServer) {
  transport::Transport node1;
  transport::Transport rendezvous_node;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, rendezvous_node.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  node1.StartPingRendezvous(false, "127.0.0.1", 52002);
  boost::this_thread::sleep(boost::posix_time::seconds(9));
  ASSERT_FALSE(msg_handler[0].dead_server_);
  ASSERT_EQ(std::string(""), msg_handler[0].server_ip_);
  ASSERT_EQ(0, msg_handler[0].server_port_);
  rendezvous_node.Stop();
  boost::this_thread::sleep(boost::posix_time::seconds(15));
  node1.Stop();
  ASSERT_TRUE(msg_handler[0].dead_server_);
  ASSERT_EQ(std::string("127.0.0.1"), msg_handler[0].server_ip_);
  ASSERT_EQ(52002, msg_handler[0].server_port_);
}

TEST_F(TransportTest, FUNC_TRANS_ReconnectToDifferentServer) {
  transport::Transport node1;
  transport::Transport rendezvous_node1;
  transport::Transport rendezvous_node2;
  MessageHandler msg_handler[3];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, rendezvous_node1.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  ASSERT_EQ(0, rendezvous_node2.Start(52003,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[2], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[2],
                _1, _2, _3)));
  node1.StartPingRendezvous(false, "127.0.0.1", 52002);
  boost::this_thread::sleep(boost::posix_time::seconds(9));
  ASSERT_FALSE(msg_handler[0].dead_server_);
  ASSERT_EQ(std::string(""), msg_handler[0].server_ip_);
  ASSERT_EQ(0, msg_handler[0].server_port_);
  rendezvous_node1.Stop();
  boost::this_thread::sleep(boost::posix_time::seconds(17));
  ASSERT_TRUE(msg_handler[0].dead_server_);
  ASSERT_EQ(std::string("127.0.0.1"), msg_handler[0].server_ip_);
  ASSERT_EQ(52002, msg_handler[0].server_port_);
  node1.StartPingRendezvous(false, "127.0.0.1", 52003);
  boost::this_thread::sleep(boost::posix_time::seconds(9));
  ASSERT_FALSE(msg_handler[0].dead_server_);
  ASSERT_EQ(std::string(""), msg_handler[0].server_ip_);
  ASSERT_EQ(0, msg_handler[0].server_port_);
  node1.Stop();
  rendezvous_node2.Stop();
}

TEST_F(TransportTest, BEH_TRANS_StartStopTransport) {
  boost::uint32_t id;
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler[2];
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[0], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[0],
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                _1, _2, _3)));
  std::string sent_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, false));
  while (msg_handler[1].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  ASSERT_FALSE(msg_handler[1].msgs.empty());
  ASSERT_EQ(sent_msg, msg_handler[1].msgs.front());
  msg_handler[1].msgs.clear();
  // A message was received by node2, now start and stop it 5 times
  for (int i = 0 ; i < 5; i++) {
    node2.Stop();
    ASSERT_EQ(0, node2.Start(52002,
      boost::bind(&MessageHandler::OnMessage, &msg_handler[1], _1, _2),
      boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler[1],
                  _1, _2, _3)));
    // Sending another message
    sent_msg = base::RandomString(256*1024);
    ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
      transport::Transport::STRING, &id, false));
    while (msg_handler[1].msgs.empty())
      boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    ASSERT_FALSE(msg_handler[1].msgs.empty());
    ASSERT_EQ(sent_msg, msg_handler[1].msgs.front());
    msg_handler[1].msgs.clear();

    sent_msg = base::RandomString(256*1024);
    ASSERT_EQ(0, node2.Send("127.0.0.1", 52001, "", 0, sent_msg,
      transport::Transport::STRING, &id, false));
    while (msg_handler[0].msgs.empty())
      boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    ASSERT_FALSE(msg_handler[0].msgs.empty());
    ASSERT_EQ(sent_msg, msg_handler[0].msgs.front());
    msg_handler[0].msgs.clear();

    boost::this_thread::sleep(boost::posix_time::seconds(2));
  }
  // Sending another message
  sent_msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send("127.0.0.1", 52002, "", 0, sent_msg,
    transport::Transport::STRING, &id, false));
  while (msg_handler[1].msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  ASSERT_FALSE(msg_handler[1].msgs.empty());
  ASSERT_EQ(sent_msg, msg_handler[1].msgs.front());

  node1.Stop();
  node2.Stop();
}

TEST_F(TransportTest, BEH_TRANS_SendRespond) {
  transport::Transport node1;
  transport::Transport node2;
  MessageHandlerEchoReq msg_handler1(&node1);
  MessageHandlerEchoResp msg_handler2(&node2);
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandlerEchoReq::OnMessage, &msg_handler1, _1, _2),
    boost::bind(&MessageHandlerEchoReq::OnDeadRendezvousServer, &msg_handler1,
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandlerEchoResp::OnMessage, &msg_handler2, _1, _2),
    boost::bind(&MessageHandlerEchoResp::OnDeadRendezvousServer, &msg_handler2,
                _1, _2, _3)));
  std::vector<std::string> msgs;
  unsigned int msgs_sent = 12;
  boost::uint32_t id;
  boost::asio::ip::address local_address;
  std::string ip;
  if (base::get_local_address(&local_address)) {
    ip = local_address.to_string();
  } else {
    ip = std::string("127.0.0.1");
  }
  for (unsigned int i = 0; i < msgs_sent; i++) {
    msgs.push_back(base::RandomString(256*1024));
    ASSERT_EQ(0, node2.Send(ip, 52001, "", 0, msgs[i],
      transport::Transport::STRING, &id, true));
  }
  bool finished = false;
  boost::progress_timer t;
  while (!finished && t.elapsed() < 5) {
      if (msg_handler1.msgs.size() == msgs_sent &&
          msg_handler2.msgs.size() == 9) {
        finished = true;
        continue;
      }
    boost::this_thread::sleep(boost::posix_time::seconds(1));
  }
  node1.Stop();
  node2.Stop();
  ASSERT_EQ(msgs_sent, msg_handler1.msgs.size());
  for (unsigned int i = 0; i < msgs_sent; i++) {
    for (unsigned int j = 0; j < msgs_sent; j++) {
      if (msgs[j] == msg_handler1.msgs.front()) {
        msg_handler1.msgs.pop_front();
        break;
      }
    }
  }
  ASSERT_TRUE(msg_handler1.msgs.empty());
  ASSERT_EQ(9, msg_handler2.msgs.size());
  for (int i = 0; i < 9; i++) {
    for (unsigned int j = 0; j < msgs_sent; j++) {
      if(msgs[j] == msg_handler2.msgs.front()) {
        msg_handler2.msgs.pop_front();
        break;
      }
    }
  }
  ASSERT_TRUE(msg_handler2.msgs.empty());
}

TEST_F(TransportTest, BEH_TRANS_FailStartUsedport) {
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler1, msg_handler2;
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler1, _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler1,
                _1, _2, _3)));
  ASSERT_EQ(1, node2.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler2, _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler2,
                _1, _2, _3)));
  node1.Stop();
}

TEST_F(TransportTest, BEH_TRANS_SendMultipleMsgsSameConnection) {
  transport::Transport node1;
  transport::Transport node2;
  MessageHandler msg_handler1, msg_handler2;
  ASSERT_EQ(0, node1.Start(52001,
    boost::bind(&MessageHandler::OnMessage, &msg_handler1, _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler1,
                _1, _2, _3)));
  ASSERT_EQ(0, node2.Start(52002,
    boost::bind(&MessageHandler::OnMessage, &msg_handler2, _1, _2),
    boost::bind(&MessageHandler::OnDeadRendezvousServer, &msg_handler2,
                _1, _2, _3)));
  boost::uint32_t id;
  boost::asio::ip::address local_address;
  std::string ip;
  if (base::get_local_address(&local_address)) {
    ip = local_address.to_string();
  } else {
    ip = std::string("127.0.0.1");
  }
  std::string msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send(ip, 52002, "", 0, msg,
      transport::Transport::STRING, &id, true));
  while (msg_handler2.msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  ASSERT_FALSE(msg_handler2.msgs.empty());
  ASSERT_EQ(msg, msg_handler2.msgs.front());
  msg_handler2.msgs.clear();

  msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send(id, msg, transport::Transport::STRING));
  while (msg_handler2.msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  ASSERT_FALSE(msg_handler2.msgs.empty());
  ASSERT_EQ(msg, msg_handler2.msgs.front());
  msg_handler2.msgs.clear();

  msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send(id, msg, transport::Transport::STRING));
  while (msg_handler2.msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  ASSERT_FALSE(msg_handler2.msgs.empty());
  ASSERT_EQ(msg, msg_handler2.msgs.front());
  msg_handler2.msgs.clear();

  msg = base::RandomString(256*1024);
  ASSERT_EQ(0, node1.Send(id, msg, transport::Transport::STRING));
  while (msg_handler2.msgs.empty())
    boost::this_thread::sleep(boost::posix_time::milliseconds(10));
  ASSERT_FALSE(msg_handler2.msgs.empty());
  ASSERT_EQ(msg, msg_handler2.msgs.front());
  msg_handler2.msgs.clear();

  node1.Stop();
  node2.Stop();
}