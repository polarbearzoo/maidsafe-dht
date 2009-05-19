// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "hole_puching_messages.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace transport {

namespace {

const ::google::protobuf::Descriptor* HolePunchingMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HolePunchingMsg_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* msg_type_descriptor_ = NULL;

}  // namespace


void protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto_AssignGlobalDescriptors(const ::google::protobuf::FileDescriptor* file) {
  HolePunchingMsg_descriptor_ = file->message_type(0);
  HolePunchingMsg::default_instance_ = new HolePunchingMsg();
  static const int HolePunchingMsg_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HolePunchingMsg, ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HolePunchingMsg, port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HolePunchingMsg, type_),
  };
  HolePunchingMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HolePunchingMsg_descriptor_,
      HolePunchingMsg::default_instance_,
      HolePunchingMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HolePunchingMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HolePunchingMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(HolePunchingMsg));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HolePunchingMsg_descriptor_, HolePunchingMsg::default_instance_);
  msg_type_descriptor_ = file->enum_type(0);
  HolePunchingMsg::default_instance_->InitAsDefaultInstance();
}

void protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ::google::protobuf::DescriptorPool* pool =
    ::google::protobuf::DescriptorPool::internal_generated_pool();

  pool->InternalBuildGeneratedFile(
    "\n\033hole_puching_messages.proto\022\ttransport"
    "\"N\n\017HolePunchingMsg\022\n\n\002ip\030\001 \002(\014\022\014\n\004port\030"
    "\002 \002(\005\022!\n\004type\030\003 \002(\0162\023.transport.msg_type"
    "*,\n\010msg_type\022\017\n\013FORWARD_REQ\020\000\022\017\n\013FORWARD"
    "_MSG\020\001", 166,
  &protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto_AssignGlobalDescriptors);
}

// Force BuildDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_hole_5fpuching_5fmessages_2eproto {
  StaticDescriptorInitializer_hole_5fpuching_5fmessages_2eproto() {
    protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto();
  }
} static_descriptor_initializer_hole_5fpuching_5fmessages_2eproto_;

const ::google::protobuf::EnumDescriptor* msg_type_descriptor() {
  if (msg_type_descriptor_ == NULL) protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto();
  return msg_type_descriptor_;
}
bool msg_type_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

const ::std::string HolePunchingMsg::_default_ip_;


HolePunchingMsg::HolePunchingMsg()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    ip_(const_cast< ::std::string*>(&_default_ip_)),
    port_(0),
    type_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void HolePunchingMsg::InitAsDefaultInstance() {}

HolePunchingMsg::HolePunchingMsg(const HolePunchingMsg& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    ip_(const_cast< ::std::string*>(&_default_ip_)),
    port_(0),
    type_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

HolePunchingMsg::~HolePunchingMsg() {
  if (ip_ != &_default_ip_) {
    delete ip_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* HolePunchingMsg::descriptor() {
  if (HolePunchingMsg_descriptor_ == NULL) protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto();
  return HolePunchingMsg_descriptor_;
}

const HolePunchingMsg& HolePunchingMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto();
  return *default_instance_;
}

HolePunchingMsg* HolePunchingMsg::default_instance_ = NULL;

HolePunchingMsg* HolePunchingMsg::New() const {
  return new HolePunchingMsg;
}

const ::google::protobuf::Descriptor* HolePunchingMsg::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* HolePunchingMsg::GetReflection() const {
  if (HolePunchingMsg_reflection_ == NULL) protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto();
  return HolePunchingMsg_reflection_;
}

}  // namespace transport