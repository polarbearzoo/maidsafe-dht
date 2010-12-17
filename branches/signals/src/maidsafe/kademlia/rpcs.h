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

#ifndef MAIDSAFE_KADEMLIA_KADRPC_H_
#define MAIDSAFE_KADEMLIA_KADRPC_H_

#include <boost/cstdint.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "maidsafe/maidsafe-dht_config.h"
#include "maidsafe/kademlia/config.h"
#include "maidsafe/protobuf/transport_message.pb.h"
#include "maidsafe/protobuf/kademlia.pb.h"
#include "maidsafe/kademlia/rpcs.pb.h"
#include <string>
#include <vector>

namespace transport {
class Transport;
}  // namespace transport

namespace kademlia {
class NodeId;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> FindNodesFunctor;
// Need to update arguments
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> FindValueFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> PingFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> StoreFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> StoreSigFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> DownlistFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> BootStrapFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> DeleteFunctor;
typedef boost::function<void(bool, std::vector<protobuf::Contact>)> UpdateFunctor;
// Need to update

class Rpcs {
 public:
  Rpcs() {}
 
  void FindNodes(const NodeId &key,
                 const Endpoint &ep,
                 FindNodesFunctor callback);
  void FindValue(const NodeId &key,
                 const Endpoint &ep,
                 FindValueFunctor callback);
  void Ping(const Endpoint &ep,
            PingFunctor callback);
  void Store(const NodeId &key,
             const protobuf::SignedValue &value,
             const protobuf::SignedRequest &sig_req,
             const Endpoint &ep,
             const boost::int32_t &ttl,
             const bool &publish,
             StoreSigFunctor callback );
  void Store(const NodeId &key,
             const std::string &value,
             const Endpoint &ep,
             const boost::int32_t &ttl,
             const bool &publish,
             StoreFunctor callback);
  void Downlist(const std::vector<std::string> downlist,
                const Endpoint &ep,
                DownlistFunctor callback);
  void Bootstrap(const NodeId &local_id,
                 const Endpoint &ep,
                 const NodeType &type,
                 BootStrapFunctor callback);
  void Delete(const NodeId &key,
              const protobuf::SignedValue &value,
              const protobuf::SignedRequest &sig_req,
              const Endpoint &ep,
              DeleteFunctor callback);
  void Update(const NodeId &key,
              const protobuf::SignedValue &new_value,
              const protobuf::SignedValue &old_value,
              const boost::int32_t &ttl,
              const protobuf::SignedRequest &sig_req,
              const Endpoint &ep,
              UpdateFunctor callback);
  inline void set_info(const ContactInfo &info) { info_ = info; }
 private:
  Rpcs(const Rpcs&);
  Rpcs& operator=(const Rpcs&);
  protobuf::Contact info_;
};

}  // namespace kademlia

#endif  // MAIDSAFE_KADEMLIA_KADRPC_H_
