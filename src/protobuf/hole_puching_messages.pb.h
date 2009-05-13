// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_hole_5fpuching_5fmessages_2eproto__INCLUDED
#define PROTOBUF_hole_5fpuching_5fmessages_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2000003
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2000003 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>

namespace transport {

// Internal implementation detail -- do not call these.
void  protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto();
void protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto_AssignGlobalDescriptors(
    ::google::protobuf::FileDescriptor* file);

class HolePunchingMsg;

enum msg_type {
  FORWARD_REQ = 0,
  FORWARD_MSG = 1
};
const ::google::protobuf::EnumDescriptor* msg_type_descriptor();
bool msg_type_IsValid(int value);
const msg_type msg_type_MIN = FORWARD_REQ;
const msg_type msg_type_MAX = FORWARD_MSG;

// ===================================================================

class HolePunchingMsg : public ::google::protobuf::Message {
 public:
  HolePunchingMsg();
  virtual ~HolePunchingMsg();
  
  HolePunchingMsg(const HolePunchingMsg& from);
  
  inline HolePunchingMsg& operator=(const HolePunchingMsg& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const HolePunchingMsg& default_instance();
  void Swap(HolePunchingMsg* other);
  
  // implements Message ----------------------------------------------
  
  HolePunchingMsg* New() const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  const ::google::protobuf::Descriptor* GetDescriptor() const;
  const ::google::protobuf::Reflection* GetReflection() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bytes ip = 1;
  inline bool has_ip() const;
  inline void clear_ip();
  inline const ::std::string& ip() const;
  inline void set_ip(const ::std::string& value);
  inline void set_ip(const char* value);
  inline void set_ip(const void* value, size_t size);
  inline ::std::string* mutable_ip();
  
  // required int32 port = 2;
  inline bool has_port() const;
  inline void clear_port();
  inline ::google::protobuf::int32 port() const;
  inline void set_port(::google::protobuf::int32 value);
  
  // required .transport.msg_type type = 3;
  inline bool has_type() const;
  inline void clear_type();
  inline transport::msg_type type() const;
  inline void set_type(transport::msg_type value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::std::string* ip_;
  static const ::std::string _default_ip_;
  ::google::protobuf::int32 port_;
  int type_;
  friend void protobuf_BuildDesc_hole_5fpuching_5fmessages_2eproto_AssignGlobalDescriptors(
      const ::google::protobuf::FileDescriptor* file);
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static HolePunchingMsg* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// HolePunchingMsg

// required bytes ip = 1;
inline bool HolePunchingMsg::has_ip() const {
  return _has_bit(0);
}
inline void HolePunchingMsg::clear_ip() {
  if (ip_ != &_default_ip_) {
    ip_->clear();
  }
  _clear_bit(0);
}
inline const ::std::string& HolePunchingMsg::ip() const {
  return *ip_;
}
inline void HolePunchingMsg::set_ip(const ::std::string& value) {
  _set_bit(0);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void HolePunchingMsg::set_ip(const char* value) {
  _set_bit(0);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void HolePunchingMsg::set_ip(const void* value, size_t size) {
  _set_bit(0);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* HolePunchingMsg::mutable_ip() {
  _set_bit(0);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  return ip_;
}

// required int32 port = 2;
inline bool HolePunchingMsg::has_port() const {
  return _has_bit(1);
}
inline void HolePunchingMsg::clear_port() {
  port_ = 0;
  _clear_bit(1);
}
inline ::google::protobuf::int32 HolePunchingMsg::port() const {
  return port_;
}
inline void HolePunchingMsg::set_port(::google::protobuf::int32 value) {
  _set_bit(1);
  port_ = value;
}

// required .transport.msg_type type = 3;
inline bool HolePunchingMsg::has_type() const {
  return _has_bit(2);
}
inline void HolePunchingMsg::clear_type() {
  type_ = 0;
  _clear_bit(2);
}
inline transport::msg_type HolePunchingMsg::type() const {
  return static_cast< transport::msg_type >(type_);
}
inline void HolePunchingMsg::set_type(transport::msg_type value) {
  GOOGLE_DCHECK(transport::msg_type_IsValid(value));
  _set_bit(2);
  type_ = value;
}


}  // namespace transport
#endif  // PROTOBUF_hole_5fpuching_5fmessages_2eproto__INCLUDED
