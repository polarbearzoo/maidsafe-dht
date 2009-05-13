// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_callback_5fmessages_2eproto__INCLUDED
#define PROTOBUF_callback_5fmessages_2eproto__INCLUDED

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

namespace net {

// Internal implementation detail -- do not call these.
void  protobuf_BuildDesc_callback_5fmessages_2eproto();
void protobuf_BuildDesc_callback_5fmessages_2eproto_AssignGlobalDescriptors(
    ::google::protobuf::FileDescriptor* file);

class NetStartResult;

// ===================================================================

class NetStartResult : public ::google::protobuf::Message {
 public:
  NetStartResult();
  virtual ~NetStartResult();
  
  NetStartResult(const NetStartResult& from);
  
  inline NetStartResult& operator=(const NetStartResult& from) {
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
  static const NetStartResult& default_instance();
  void Swap(NetStartResult* other);
  
  // implements Message ----------------------------------------------
  
  NetStartResult* New() const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  const ::google::protobuf::Descriptor* GetDescriptor() const;
  const ::google::protobuf::Reflection* GetReflection() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bytes result = 1;
  inline bool has_result() const;
  inline void clear_result();
  inline const ::std::string& result() const;
  inline void set_result(const ::std::string& value);
  inline void set_result(const char* value);
  inline void set_result(const void* value, size_t size);
  inline ::std::string* mutable_result();
  
  // optional bytes ip = 2;
  inline bool has_ip() const;
  inline void clear_ip();
  inline const ::std::string& ip() const;
  inline void set_ip(const ::std::string& value);
  inline void set_ip(const char* value);
  inline void set_ip(const void* value, size_t size);
  inline ::std::string* mutable_ip();
  
  // optional int32 port = 3;
  inline bool has_port() const;
  inline void clear_port();
  inline ::google::protobuf::int32 port() const;
  inline void set_port(::google::protobuf::int32 value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::std::string* result_;
  static const ::std::string _default_result_;
  ::std::string* ip_;
  static const ::std::string _default_ip_;
  ::google::protobuf::int32 port_;
  friend void protobuf_BuildDesc_callback_5fmessages_2eproto_AssignGlobalDescriptors(
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
  static NetStartResult* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// NetStartResult

// required bytes result = 1;
inline bool NetStartResult::has_result() const {
  return _has_bit(0);
}
inline void NetStartResult::clear_result() {
  if (result_ != &_default_result_) {
    result_->clear();
  }
  _clear_bit(0);
}
inline const ::std::string& NetStartResult::result() const {
  return *result_;
}
inline void NetStartResult::set_result(const ::std::string& value) {
  _set_bit(0);
  if (result_ == &_default_result_) {
    result_ = new ::std::string;
  }
  result_->assign(value);
}
inline void NetStartResult::set_result(const char* value) {
  _set_bit(0);
  if (result_ == &_default_result_) {
    result_ = new ::std::string;
  }
  result_->assign(value);
}
inline void NetStartResult::set_result(const void* value, size_t size) {
  _set_bit(0);
  if (result_ == &_default_result_) {
    result_ = new ::std::string;
  }
  result_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* NetStartResult::mutable_result() {
  _set_bit(0);
  if (result_ == &_default_result_) {
    result_ = new ::std::string;
  }
  return result_;
}

// optional bytes ip = 2;
inline bool NetStartResult::has_ip() const {
  return _has_bit(1);
}
inline void NetStartResult::clear_ip() {
  if (ip_ != &_default_ip_) {
    ip_->clear();
  }
  _clear_bit(1);
}
inline const ::std::string& NetStartResult::ip() const {
  return *ip_;
}
inline void NetStartResult::set_ip(const ::std::string& value) {
  _set_bit(1);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void NetStartResult::set_ip(const char* value) {
  _set_bit(1);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  ip_->assign(value);
}
inline void NetStartResult::set_ip(const void* value, size_t size) {
  _set_bit(1);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  ip_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* NetStartResult::mutable_ip() {
  _set_bit(1);
  if (ip_ == &_default_ip_) {
    ip_ = new ::std::string;
  }
  return ip_;
}

// optional int32 port = 3;
inline bool NetStartResult::has_port() const {
  return _has_bit(2);
}
inline void NetStartResult::clear_port() {
  port_ = 0;
  _clear_bit(2);
}
inline ::google::protobuf::int32 NetStartResult::port() const {
  return port_;
}
inline void NetStartResult::set_port(::google::protobuf::int32 value) {
  _set_bit(2);
  port_ = value;
}


}  // namespace net
#endif  // PROTOBUF_callback_5fmessages_2eproto__INCLUDED
