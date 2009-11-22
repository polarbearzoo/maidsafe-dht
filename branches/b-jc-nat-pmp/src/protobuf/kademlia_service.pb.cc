// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "kademlia_service.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>

namespace kad {

namespace {

const ::google::protobuf::ServiceDescriptor* KademliaService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_kademlia_5fservice_2eproto() {
  protobuf_AddDesc_kademlia_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "kademlia_service.proto");
  GOOGLE_CHECK(file != NULL);
  KademliaService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_kademlia_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_kademlia_5fservice_2eproto() {
}

void protobuf_AddDesc_kademlia_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::kad::protobuf_AddDesc_kademlia_5fservice_5fmessages_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026kademlia_service.proto\022\003kad\032\037kademlia_"
    "service_messages.proto2\334\003\n\017KademliaServi"
    "ce\022+\n\004Ping\022\020.kad.PingRequest\032\021.kad.PingR"
    "esponse\0220\n\tFindValue\022\020.kad.FindRequest\032\021"
    ".kad.FindResponse\022/\n\010FindNode\022\020.kad.Find"
    "Request\032\021.kad.FindResponse\022.\n\005Store\022\021.ka"
    "d.StoreRequest\032\022.kad.StoreResponse\0227\n\010Do"
    "wnlist\022\024.kad.DownlistRequest\032\025.kad.Downl"
    "istResponse\022C\n\014NatDetection\022\030.kad.NatDet"
    "ectionRequest\032\031.kad.NatDetectionResponse"
    "\022O\n\020NatDetectionPing\022\034.kad.NatDetectionP"
    "ingRequest\032\035.kad.NatDetectionPingRespons"
    "e\022:\n\tBootstrap\022\025.kad.BootstrapRequest\032\026."
    "kad.BootstrapResponse", 541);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "kademlia_service.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_kademlia_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_kademlia_5fservice_2eproto {
  StaticDescriptorInitializer_kademlia_5fservice_2eproto() {
    protobuf_AddDesc_kademlia_5fservice_2eproto();
  }
} static_descriptor_initializer_kademlia_5fservice_2eproto_;


// ===================================================================

KademliaService::~KademliaService() {}

const ::google::protobuf::ServiceDescriptor* KademliaService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return KademliaService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* KademliaService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return KademliaService_descriptor_;
}

void KademliaService::Ping(::google::protobuf::RpcController* controller,
                         const ::kad::PingRequest*,
                         ::kad::PingResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Ping() not implemented.");
  done->Run();
}

void KademliaService::FindValue(::google::protobuf::RpcController* controller,
                         const ::kad::FindRequest*,
                         ::kad::FindResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method FindValue() not implemented.");
  done->Run();
}

void KademliaService::FindNode(::google::protobuf::RpcController* controller,
                         const ::kad::FindRequest*,
                         ::kad::FindResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method FindNode() not implemented.");
  done->Run();
}

void KademliaService::Store(::google::protobuf::RpcController* controller,
                         const ::kad::StoreRequest*,
                         ::kad::StoreResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Store() not implemented.");
  done->Run();
}

void KademliaService::Downlist(::google::protobuf::RpcController* controller,
                         const ::kad::DownlistRequest*,
                         ::kad::DownlistResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Downlist() not implemented.");
  done->Run();
}

void KademliaService::NatDetection(::google::protobuf::RpcController* controller,
                         const ::kad::NatDetectionRequest*,
                         ::kad::NatDetectionResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method NatDetection() not implemented.");
  done->Run();
}

void KademliaService::NatDetectionPing(::google::protobuf::RpcController* controller,
                         const ::kad::NatDetectionPingRequest*,
                         ::kad::NatDetectionPingResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method NatDetectionPing() not implemented.");
  done->Run();
}

void KademliaService::Bootstrap(::google::protobuf::RpcController* controller,
                         const ::kad::BootstrapRequest*,
                         ::kad::BootstrapResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Bootstrap() not implemented.");
  done->Run();
}

void KademliaService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), KademliaService_descriptor_);
  switch(method->index()) {
    case 0:
      Ping(controller,
             ::google::protobuf::down_cast<const ::kad::PingRequest*>(request),
             ::google::protobuf::down_cast< ::kad::PingResponse*>(response),
             done);
      break;
    case 1:
      FindValue(controller,
             ::google::protobuf::down_cast<const ::kad::FindRequest*>(request),
             ::google::protobuf::down_cast< ::kad::FindResponse*>(response),
             done);
      break;
    case 2:
      FindNode(controller,
             ::google::protobuf::down_cast<const ::kad::FindRequest*>(request),
             ::google::protobuf::down_cast< ::kad::FindResponse*>(response),
             done);
      break;
    case 3:
      Store(controller,
             ::google::protobuf::down_cast<const ::kad::StoreRequest*>(request),
             ::google::protobuf::down_cast< ::kad::StoreResponse*>(response),
             done);
      break;
    case 4:
      Downlist(controller,
             ::google::protobuf::down_cast<const ::kad::DownlistRequest*>(request),
             ::google::protobuf::down_cast< ::kad::DownlistResponse*>(response),
             done);
      break;
    case 5:
      NatDetection(controller,
             ::google::protobuf::down_cast<const ::kad::NatDetectionRequest*>(request),
             ::google::protobuf::down_cast< ::kad::NatDetectionResponse*>(response),
             done);
      break;
    case 6:
      NatDetectionPing(controller,
             ::google::protobuf::down_cast<const ::kad::NatDetectionPingRequest*>(request),
             ::google::protobuf::down_cast< ::kad::NatDetectionPingResponse*>(response),
             done);
      break;
    case 7:
      Bootstrap(controller,
             ::google::protobuf::down_cast<const ::kad::BootstrapRequest*>(request),
             ::google::protobuf::down_cast< ::kad::BootstrapResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& KademliaService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::kad::PingRequest::default_instance();
    case 1:
      return ::kad::FindRequest::default_instance();
    case 2:
      return ::kad::FindRequest::default_instance();
    case 3:
      return ::kad::StoreRequest::default_instance();
    case 4:
      return ::kad::DownlistRequest::default_instance();
    case 5:
      return ::kad::NatDetectionRequest::default_instance();
    case 6:
      return ::kad::NatDetectionPingRequest::default_instance();
    case 7:
      return ::kad::BootstrapRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& KademliaService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::kad::PingResponse::default_instance();
    case 1:
      return ::kad::FindResponse::default_instance();
    case 2:
      return ::kad::FindResponse::default_instance();
    case 3:
      return ::kad::StoreResponse::default_instance();
    case 4:
      return ::kad::DownlistResponse::default_instance();
    case 5:
      return ::kad::NatDetectionResponse::default_instance();
    case 6:
      return ::kad::NatDetectionPingResponse::default_instance();
    case 7:
      return ::kad::BootstrapResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

KademliaService_Stub::KademliaService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
KademliaService_Stub::KademliaService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
KademliaService_Stub::~KademliaService_Stub() {
  if (owns_channel_) delete channel_;
}

void KademliaService_Stub::Ping(::google::protobuf::RpcController* controller,
                              const ::kad::PingRequest* request,
                              ::kad::PingResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void KademliaService_Stub::FindValue(::google::protobuf::RpcController* controller,
                              const ::kad::FindRequest* request,
                              ::kad::FindResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void KademliaService_Stub::FindNode(::google::protobuf::RpcController* controller,
                              const ::kad::FindRequest* request,
                              ::kad::FindResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}
void KademliaService_Stub::Store(::google::protobuf::RpcController* controller,
                              const ::kad::StoreRequest* request,
                              ::kad::StoreResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(3),
                       controller, request, response, done);
}
void KademliaService_Stub::Downlist(::google::protobuf::RpcController* controller,
                              const ::kad::DownlistRequest* request,
                              ::kad::DownlistResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(4),
                       controller, request, response, done);
}
void KademliaService_Stub::NatDetection(::google::protobuf::RpcController* controller,
                              const ::kad::NatDetectionRequest* request,
                              ::kad::NatDetectionResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(5),
                       controller, request, response, done);
}
void KademliaService_Stub::NatDetectionPing(::google::protobuf::RpcController* controller,
                              const ::kad::NatDetectionPingRequest* request,
                              ::kad::NatDetectionPingResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(6),
                       controller, request, response, done);
}
void KademliaService_Stub::Bootstrap(::google::protobuf::RpcController* controller,
                              const ::kad::BootstrapRequest* request,
                              ::kad::BootstrapResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(7),
                       controller, request, response, done);
}

}  // namespace kad
