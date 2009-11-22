// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "contact_info.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>

namespace kad {

namespace {

const ::google::protobuf::Descriptor* ContactInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ContactInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_contact_5finfo_2eproto() {
  protobuf_AddDesc_contact_5finfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "contact_info.proto");
  GOOGLE_CHECK(file != NULL);
  ContactInfo_descriptor_ = file->message_type(0);
  static const int ContactInfo_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, node_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, local_ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, local_port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, rv_ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, rv_port_),
  };
  ContactInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ContactInfo_descriptor_,
      ContactInfo::default_instance_,
      ContactInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ContactInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ContactInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_contact_5finfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ContactInfo_descriptor_, &ContactInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_contact_5finfo_2eproto() {
  delete ContactInfo::default_instance_;
  delete ContactInfo_reflection_;
}

void protobuf_AddDesc_contact_5finfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022contact_info.proto\022\003kad\"~\n\013ContactInfo"
    "\022\017\n\007node_id\030\001 \002(\014\022\n\n\002ip\030\002 \002(\014\022\014\n\004port\030\003 "
    "\002(\005\022\020\n\010local_ip\030\004 \001(\014\022\022\n\nlocal_port\030\005 \001("
    "\005\022\r\n\005rv_ip\030\006 \001(\014\022\017\n\007rv_port\030\007 \001(\005", 153);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "contact_info.proto", &protobuf_RegisterTypes);
  ContactInfo::default_instance_ = new ContactInfo();
  ContactInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_contact_5finfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_contact_5finfo_2eproto {
  StaticDescriptorInitializer_contact_5finfo_2eproto() {
    protobuf_AddDesc_contact_5finfo_2eproto();
  }
} static_descriptor_initializer_contact_5finfo_2eproto_;


// ===================================================================

const ::std::string ContactInfo::_default_node_id_;
const ::std::string ContactInfo::_default_ip_;
const ::std::string ContactInfo::_default_local_ip_;
const ::std::string ContactInfo::_default_rv_ip_;
#ifndef _MSC_VER
const int ContactInfo::kNodeIdFieldNumber;
const int ContactInfo::kIpFieldNumber;
const int ContactInfo::kPortFieldNumber;
const int ContactInfo::kLocalIpFieldNumber;
const int ContactInfo::kLocalPortFieldNumber;
const int ContactInfo::kRvIpFieldNumber;
const int ContactInfo::kRvPortFieldNumber;
#endif  // !_MSC_VER

ContactInfo::ContactInfo() {
  SharedCtor();
}

void ContactInfo::InitAsDefaultInstance() {
}

ContactInfo::ContactInfo(const ContactInfo& from) {
  SharedCtor();
  MergeFrom(from);
}

void ContactInfo::SharedCtor() {
  _cached_size_ = 0;
  node_id_ = const_cast< ::std::string*>(&_default_node_id_);
  ip_ = const_cast< ::std::string*>(&_default_ip_);
  port_ = 0;
  local_ip_ = const_cast< ::std::string*>(&_default_local_ip_);
  local_port_ = 0;
  rv_ip_ = const_cast< ::std::string*>(&_default_rv_ip_);
  rv_port_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ContactInfo::~ContactInfo() {
  SharedDtor();
}

void ContactInfo::SharedDtor() {
  if (node_id_ != &_default_node_id_) {
    delete node_id_;
  }
  if (ip_ != &_default_ip_) {
    delete ip_;
  }
  if (local_ip_ != &_default_local_ip_) {
    delete local_ip_;
  }
  if (rv_ip_ != &_default_rv_ip_) {
    delete rv_ip_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* ContactInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ContactInfo_descriptor_;
}

const ContactInfo& ContactInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_contact_5finfo_2eproto();  return *default_instance_;
}

ContactInfo* ContactInfo::default_instance_ = NULL;

ContactInfo* ContactInfo::New() const {
  return new ContactInfo;
}

void ContactInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (_has_bit(0)) {
      if (node_id_ != &_default_node_id_) {
        node_id_->clear();
      }
    }
    if (_has_bit(1)) {
      if (ip_ != &_default_ip_) {
        ip_->clear();
      }
    }
    port_ = 0;
    if (_has_bit(3)) {
      if (local_ip_ != &_default_local_ip_) {
        local_ip_->clear();
      }
    }
    local_port_ = 0;
    if (_has_bit(5)) {
      if (rv_ip_ != &_default_rv_ip_) {
        rv_ip_->clear();
      }
    }
    rv_port_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ContactInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes node_id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          goto handle_uninterpreted;
        }
        DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
              input, this->mutable_node_id()));
        if (input->ExpectTag(18)) goto parse_ip;
        break;
      }
      
      // required bytes ip = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          goto handle_uninterpreted;
        }
       parse_ip:
        DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
              input, this->mutable_ip()));
        if (input->ExpectTag(24)) goto parse_port;
        break;
      }
      
      // required int32 port = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          goto handle_uninterpreted;
        }
       parse_port:
        DO_(::google::protobuf::internal::WireFormatLite::ReadInt32(
              input, &port_));
        _set_bit(2);
        if (input->ExpectTag(34)) goto parse_local_ip;
        break;
      }
      
      // optional bytes local_ip = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          goto handle_uninterpreted;
        }
       parse_local_ip:
        DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
              input, this->mutable_local_ip()));
        if (input->ExpectTag(40)) goto parse_local_port;
        break;
      }
      
      // optional int32 local_port = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          goto handle_uninterpreted;
        }
       parse_local_port:
        DO_(::google::protobuf::internal::WireFormatLite::ReadInt32(
              input, &local_port_));
        _set_bit(4);
        if (input->ExpectTag(50)) goto parse_rv_ip;
        break;
      }
      
      // optional bytes rv_ip = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          goto handle_uninterpreted;
        }
       parse_rv_ip:
        DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
              input, this->mutable_rv_ip()));
        if (input->ExpectTag(56)) goto parse_rv_port;
        break;
      }
      
      // optional int32 rv_port = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) !=
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          goto handle_uninterpreted;
        }
       parse_rv_port:
        DO_(::google::protobuf::internal::WireFormatLite::ReadInt32(
              input, &rv_port_));
        _set_bit(6);
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ContactInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  ::google::protobuf::uint8* raw_buffer = output->GetDirectBufferForNBytesAndAdvance(_cached_size_);
  if (raw_buffer != NULL) {
    ContactInfo::SerializeWithCachedSizesToArray(raw_buffer);
    return;
  }
  
  // required bytes node_id = 1;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      1, this->node_id(), output);
  }
  
  // required bytes ip = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->ip(), output);
  }
  
  // required int32 port = 3;
  if (_has_bit(2)) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->port(), output);
  }
  
  // optional bytes local_ip = 4;
  if (_has_bit(3)) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->local_ip(), output);
  }
  
  // optional int32 local_port = 5;
  if (_has_bit(4)) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->local_port(), output);
  }
  
  // optional bytes rv_ip = 6;
  if (_has_bit(5)) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->rv_ip(), output);
  }
  
  // optional int32 rv_port = 7;
  if (_has_bit(6)) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->rv_port(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ContactInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required bytes node_id = 1;
  if (_has_bit(0)) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->node_id(), target);
  }
  
  // required bytes ip = 2;
  if (_has_bit(1)) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->ip(), target);
  }
  
  // required int32 port = 3;
  if (_has_bit(2)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->port(), target);
  }
  
  // optional bytes local_ip = 4;
  if (_has_bit(3)) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->local_ip(), target);
  }
  
  // optional int32 local_port = 5;
  if (_has_bit(4)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->local_port(), target);
  }
  
  // optional bytes rv_ip = 6;
  if (_has_bit(5)) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->rv_ip(), target);
  }
  
  // optional int32 rv_port = 7;
  if (_has_bit(6)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->rv_port(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ContactInfo::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required bytes node_id = 1;
    if (has_node_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->node_id());
    }
    
    // required bytes ip = 2;
    if (has_ip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->ip());
    }
    
    // required int32 port = 3;
    if (has_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->port());
    }
    
    // optional bytes local_ip = 4;
    if (has_local_ip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->local_ip());
    }
    
    // optional int32 local_port = 5;
    if (has_local_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->local_port());
    }
    
    // optional bytes rv_ip = 6;
    if (has_rv_ip()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->rv_ip());
    }
    
    // optional int32 rv_port = 7;
    if (has_rv_port()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->rv_port());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  _cached_size_ = total_size;
  return total_size;
}

void ContactInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ContactInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ContactInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ContactInfo::MergeFrom(const ContactInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from._has_bit(0)) {
      set_node_id(from.node_id());
    }
    if (from._has_bit(1)) {
      set_ip(from.ip());
    }
    if (from._has_bit(2)) {
      set_port(from.port());
    }
    if (from._has_bit(3)) {
      set_local_ip(from.local_ip());
    }
    if (from._has_bit(4)) {
      set_local_port(from.local_port());
    }
    if (from._has_bit(5)) {
      set_rv_ip(from.rv_ip());
    }
    if (from._has_bit(6)) {
      set_rv_port(from.rv_port());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ContactInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ContactInfo::CopyFrom(const ContactInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ContactInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void ContactInfo::Swap(ContactInfo* other) {
  if (other != this) {
    std::swap(node_id_, other->node_id_);
    std::swap(ip_, other->ip_);
    std::swap(port_, other->port_);
    std::swap(local_ip_, other->local_ip_);
    std::swap(local_port_, other->local_port_);
    std::swap(rv_ip_, other->rv_ip_);
    std::swap(rv_port_, other->rv_port_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ContactInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ContactInfo_descriptor_;
  metadata.reflection = ContactInfo_reflection_;
  return metadata;
}


}  // namespace kad
