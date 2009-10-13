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

/*******************************************************************************
 * This is the API for maidsafe-dht and is the only program access for         *
 * developers.  The maidsafe-dht_config.h file included is where configuration *
 * may be saved.  You MUST link the maidsafe-dht library.                      *
 *                                                                             *
 * NOTE: These APIs may be amended or deleted in future releases until this    *
 * notice is removed.                                                          *
 ******************************************************************************/

#ifndef MAIDSAFE_CHANNEL_H_
#define MAIDSAFE_CHANNEL_H_

#include <string>
#include "maidsafe/maidsafe-dht_config.h"

#if MAIDSAFE_DHT_VERSION < 12
#error This API is not compatible with the installed library.
#error Please update the maidsafe-dht library.
#endif

// RPC
namespace rpcprotocol {

class Controller : public google::protobuf::RpcController {
 public:
  Controller();
  ~Controller();
  void SetFailed(const std::string &failure);
  void Reset();
  bool Failed() const;
  std::string ErrorText() const;
  void StartCancel();
  bool IsCanceled() const;
  void NotifyOnCancel(google::protobuf::Closure*);
  void set_timeout(const int &seconds);
  void set_rtt(const float &rtt);
  void set_req_id(const boost::uint32_t &id);
  int timeout() const;
  float rtt() const;
  boost::uint32_t req_id() const;
 private:
  boost::shared_ptr<ControllerImpl> controller_pimpl_;
};

class Channel : public google::protobuf::RpcChannel {
 public:
  explicit Channel(rpcprotocol::ChannelManager *channelmanager);
  Channel(rpcprotocol::ChannelManager *channelmanager,
      const std::string &remote_ip, const boost::uint16_t &remote_port,
      const std::string &local_ip, const boost::uint16_t &local_port,
      const std::string &rv_ip, const boost::uint16_t &rv_port);
  ~Channel();
  void CallMethod(const google::protobuf::MethodDescriptor *method,
      google::protobuf::RpcController *controller,
      const google::protobuf::Message *request,
      google::protobuf::Message *response, google::protobuf::Closure *done);
  void SetService(google::protobuf::Service* service);
  void HandleRequest(const RpcMessage &request,
      const boost::uint32_t &connection_id, const float &rtt);
 private:
  boost::shared_ptr<ChannelImpl> pimpl_;
};
}  // namespace rpcprotocol

#endif  // MAIDSAFE_CHANNEL_H_
