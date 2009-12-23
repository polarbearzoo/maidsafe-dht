// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_kademlia_5fservice_2eproto__INCLUDED
#define PROTOBUF_kademlia_5fservice_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/service.h>
#include "kademlia_service_messages.pb.h"

namespace kad {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_kademlia_5fservice_2eproto();
void protobuf_AssignDesc_kademlia_5fservice_2eproto();
void protobuf_ShutdownFile_kademlia_5fservice_2eproto();


// ===================================================================


// ===================================================================

class KademliaService_Stub;

class KademliaService : public ::google::protobuf::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline KademliaService() {};
 public:
  virtual ~KademliaService();
  
  typedef KademliaService_Stub Stub;
  
  static const ::google::protobuf::ServiceDescriptor* descriptor();
  
  virtual void Ping(::google::protobuf::RpcController* controller,
                       const ::kad::PingRequest* request,
                       ::kad::PingResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void FindValue(::google::protobuf::RpcController* controller,
                       const ::kad::FindRequest* request,
                       ::kad::FindResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void FindNode(::google::protobuf::RpcController* controller,
                       const ::kad::FindRequest* request,
                       ::kad::FindResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void Store(::google::protobuf::RpcController* controller,
                       const ::kad::StoreRequest* request,
                       ::kad::StoreResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void Downlist(::google::protobuf::RpcController* controller,
                       const ::kad::DownlistRequest* request,
                       ::kad::DownlistResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void NatDetection(::google::protobuf::RpcController* controller,
                       const ::kad::NatDetectionRequest* request,
                       ::kad::NatDetectionResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void NatDetectionPing(::google::protobuf::RpcController* controller,
                       const ::kad::NatDetectionPingRequest* request,
                       ::kad::NatDetectionPingResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void Bootstrap(::google::protobuf::RpcController* controller,
                       const ::kad::BootstrapRequest* request,
                       ::kad::BootstrapResponse* response,
                       ::google::protobuf::Closure* done);
  virtual void Delete(::google::protobuf::RpcController* controller,
                       const ::kad::DeleteRequest* request,
                       ::kad::DeleteResponse* response,
                       ::google::protobuf::Closure* done);
  
  // implements Service ----------------------------------------------
  
  const ::google::protobuf::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::google::protobuf::MethodDescriptor* method,
                  ::google::protobuf::RpcController* controller,
                  const ::google::protobuf::Message* request,
                  ::google::protobuf::Message* response,
                  ::google::protobuf::Closure* done);
  const ::google::protobuf::Message& GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const;
  const ::google::protobuf::Message& GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(KademliaService);
};

class KademliaService_Stub : public KademliaService {
 public:
  KademliaService_Stub(::google::protobuf::RpcChannel* channel);
  KademliaService_Stub(::google::protobuf::RpcChannel* channel,
                   ::google::protobuf::Service::ChannelOwnership ownership);
  ~KademliaService_Stub();
  
  inline ::google::protobuf::RpcChannel* channel() { return channel_; }
  
  // implements KademliaService ------------------------------------------
  
  void Ping(::google::protobuf::RpcController* controller,
                       const ::kad::PingRequest* request,
                       ::kad::PingResponse* response,
                       ::google::protobuf::Closure* done);
  void FindValue(::google::protobuf::RpcController* controller,
                       const ::kad::FindRequest* request,
                       ::kad::FindResponse* response,
                       ::google::protobuf::Closure* done);
  void FindNode(::google::protobuf::RpcController* controller,
                       const ::kad::FindRequest* request,
                       ::kad::FindResponse* response,
                       ::google::protobuf::Closure* done);
  void Store(::google::protobuf::RpcController* controller,
                       const ::kad::StoreRequest* request,
                       ::kad::StoreResponse* response,
                       ::google::protobuf::Closure* done);
  void Downlist(::google::protobuf::RpcController* controller,
                       const ::kad::DownlistRequest* request,
                       ::kad::DownlistResponse* response,
                       ::google::protobuf::Closure* done);
  void NatDetection(::google::protobuf::RpcController* controller,
                       const ::kad::NatDetectionRequest* request,
                       ::kad::NatDetectionResponse* response,
                       ::google::protobuf::Closure* done);
  void NatDetectionPing(::google::protobuf::RpcController* controller,
                       const ::kad::NatDetectionPingRequest* request,
                       ::kad::NatDetectionPingResponse* response,
                       ::google::protobuf::Closure* done);
  void Bootstrap(::google::protobuf::RpcController* controller,
                       const ::kad::BootstrapRequest* request,
                       ::kad::BootstrapResponse* response,
                       ::google::protobuf::Closure* done);
  void Delete(::google::protobuf::RpcController* controller,
                       const ::kad::DeleteRequest* request,
                       ::kad::DeleteResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::google::protobuf::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(KademliaService_Stub);
};


// ===================================================================


// ===================================================================


}  // namespace kad
#endif  // PROTOBUF_kademlia_5fservice_2eproto__INCLUDED
