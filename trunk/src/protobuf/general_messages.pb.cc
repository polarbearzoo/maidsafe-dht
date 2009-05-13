// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "general_messages.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace base {

namespace {

const ::google::protobuf::Descriptor* GeneralResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GeneralResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* VaultConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  VaultConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* KadConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  KadConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* KadConfig_Contact_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  KadConfig_Contact_reflection_ = NULL;

}  // namespace


void protobuf_BuildDesc_general_5fmessages_2eproto_AssignGlobalDescriptors(const ::google::protobuf::FileDescriptor* file) {
  GeneralResponse_descriptor_ = file->message_type(0);
  GeneralResponse::default_instance_ = new GeneralResponse();
  static const int GeneralResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GeneralResponse, result_),
  };
  GeneralResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GeneralResponse_descriptor_,
      GeneralResponse::default_instance_,
      GeneralResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GeneralResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GeneralResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GeneralResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GeneralResponse_descriptor_, GeneralResponse::default_instance_);
  VaultConfig_descriptor_ = file->message_type(1);
  VaultConfig::default_instance_ = new VaultConfig();
  static const int VaultConfig_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, pmid_public_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, pmid_private_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, signed_pmid_public_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, chunkstore_dir_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, datastore_dir_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, port_),
  };
  VaultConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      VaultConfig_descriptor_,
      VaultConfig::default_instance_,
      VaultConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(VaultConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(VaultConfig));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    VaultConfig_descriptor_, VaultConfig::default_instance_);
  KadConfig_descriptor_ = file->message_type(2);
  KadConfig::default_instance_ = new KadConfig();
  static const int KadConfig_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig, port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig, contact_),
  };
  KadConfig_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      KadConfig_descriptor_,
      KadConfig::default_instance_,
      KadConfig_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(KadConfig));
  KadConfig_Contact_descriptor_ = KadConfig_descriptor_->nested_type(0);
  KadConfig_Contact::default_instance_ = new KadConfig_Contact();
  static const int KadConfig_Contact_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, node_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, local_ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, local_port_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, rendezvouz_ip_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, rendezvouz_port_),
  };
  KadConfig_Contact_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      KadConfig_Contact_descriptor_,
      KadConfig_Contact::default_instance_,
      KadConfig_Contact_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(KadConfig_Contact, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(KadConfig_Contact));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    KadConfig_Contact_descriptor_, KadConfig_Contact::default_instance_);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    KadConfig_descriptor_, KadConfig::default_instance_);
  GeneralResponse::default_instance_->InitAsDefaultInstance();
  VaultConfig::default_instance_->InitAsDefaultInstance();
  KadConfig::default_instance_->InitAsDefaultInstance();
  KadConfig_Contact::default_instance_->InitAsDefaultInstance();
}

void protobuf_BuildDesc_general_5fmessages_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ::google::protobuf::DescriptorPool* pool =
    ::google::protobuf::DescriptorPool::internal_generated_pool();

  pool->InternalBuildGeneratedFile(
    "\n\026general_messages.proto\022\004base\"!\n\017Genera"
    "lResponse\022\016\n\006result\030\001 \002(\014\"\221\001\n\013VaultConfi"
    "g\022\023\n\013pmid_public\030\001 \002(\014\022\024\n\014pmid_private\030\002"
    " \002(\014\022\032\n\022signed_pmid_public\030\003 \002(\014\022\026\n\016chun"
    "kstore_dir\030\004 \001(\014\022\025\n\rdatastore_dir\030\005 \001(\014\022"
    "\014\n\004port\030\006 \001(\005\"\320\001\n\tKadConfig\022\014\n\004port\030\001 \001("
    "\005\022(\n\007contact\030\002 \003(\0132\027.base.KadConfig.Cont"
    "act\032\212\001\n\007Contact\022\017\n\007node_id\030\001 \002(\014\022\n\n\002ip\030\002"
    " \002(\014\022\014\n\004port\030\003 \002(\005\022\020\n\010local_ip\030\004 \001(\014\022\022\n\n"
    "local_port\030\005 \001(\005\022\025\n\rrendezvouz_ip\030\006 \001(\014\022"
    "\027\n\017rendezvouz_port\030\007 \001(\005", 424,
  &protobuf_BuildDesc_general_5fmessages_2eproto_AssignGlobalDescriptors);
}

// Force BuildDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_general_5fmessages_2eproto {
  StaticDescriptorInitializer_general_5fmessages_2eproto() {
    protobuf_BuildDesc_general_5fmessages_2eproto();
  }
} static_descriptor_initializer_general_5fmessages_2eproto_;


// ===================================================================

const ::std::string GeneralResponse::_default_result_;
GeneralResponse::GeneralResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    result_(const_cast< ::std::string*>(&_default_result_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GeneralResponse::InitAsDefaultInstance() {}

GeneralResponse::GeneralResponse(const GeneralResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    result_(const_cast< ::std::string*>(&_default_result_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GeneralResponse::~GeneralResponse() {
  if (result_ != &_default_result_) {
    delete result_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GeneralResponse::descriptor() {
  if (GeneralResponse_descriptor_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return GeneralResponse_descriptor_;
}

const GeneralResponse& GeneralResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return *default_instance_;
}

GeneralResponse* GeneralResponse::default_instance_ = NULL;

GeneralResponse* GeneralResponse::New() const {
  return new GeneralResponse;
}

const ::google::protobuf::Descriptor* GeneralResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GeneralResponse::GetReflection() const {
  if (GeneralResponse_reflection_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return GeneralResponse_reflection_;
}

// ===================================================================

const ::std::string VaultConfig::_default_pmid_public_;
const ::std::string VaultConfig::_default_pmid_private_;
const ::std::string VaultConfig::_default_signed_pmid_public_;
const ::std::string VaultConfig::_default_chunkstore_dir_;
const ::std::string VaultConfig::_default_datastore_dir_;

VaultConfig::VaultConfig()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    pmid_public_(const_cast< ::std::string*>(&_default_pmid_public_)),
    pmid_private_(const_cast< ::std::string*>(&_default_pmid_private_)),
    signed_pmid_public_(const_cast< ::std::string*>(&_default_signed_pmid_public_)),
    chunkstore_dir_(const_cast< ::std::string*>(&_default_chunkstore_dir_)),
    datastore_dir_(const_cast< ::std::string*>(&_default_datastore_dir_)),
    port_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void VaultConfig::InitAsDefaultInstance() {}

VaultConfig::VaultConfig(const VaultConfig& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    pmid_public_(const_cast< ::std::string*>(&_default_pmid_public_)),
    pmid_private_(const_cast< ::std::string*>(&_default_pmid_private_)),
    signed_pmid_public_(const_cast< ::std::string*>(&_default_signed_pmid_public_)),
    chunkstore_dir_(const_cast< ::std::string*>(&_default_chunkstore_dir_)),
    datastore_dir_(const_cast< ::std::string*>(&_default_datastore_dir_)),
    port_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

VaultConfig::~VaultConfig() {
  if (pmid_public_ != &_default_pmid_public_) {
    delete pmid_public_;
  }
  if (pmid_private_ != &_default_pmid_private_) {
    delete pmid_private_;
  }
  if (signed_pmid_public_ != &_default_signed_pmid_public_) {
    delete signed_pmid_public_;
  }
  if (chunkstore_dir_ != &_default_chunkstore_dir_) {
    delete chunkstore_dir_;
  }
  if (datastore_dir_ != &_default_datastore_dir_) {
    delete datastore_dir_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* VaultConfig::descriptor() {
  if (VaultConfig_descriptor_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return VaultConfig_descriptor_;
}

const VaultConfig& VaultConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return *default_instance_;
}

VaultConfig* VaultConfig::default_instance_ = NULL;

VaultConfig* VaultConfig::New() const {
  return new VaultConfig;
}

const ::google::protobuf::Descriptor* VaultConfig::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* VaultConfig::GetReflection() const {
  if (VaultConfig_reflection_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return VaultConfig_reflection_;
}

// ===================================================================

const ::std::string KadConfig_Contact::_default_node_id_;
const ::std::string KadConfig_Contact::_default_ip_;

const ::std::string KadConfig_Contact::_default_local_ip_;

const ::std::string KadConfig_Contact::_default_rendezvouz_ip_;

KadConfig_Contact::KadConfig_Contact()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    node_id_(const_cast< ::std::string*>(&_default_node_id_)),
    ip_(const_cast< ::std::string*>(&_default_ip_)),
    port_(0),
    local_ip_(const_cast< ::std::string*>(&_default_local_ip_)),
    local_port_(0),
    rendezvouz_ip_(const_cast< ::std::string*>(&_default_rendezvouz_ip_)),
    rendezvouz_port_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void KadConfig_Contact::InitAsDefaultInstance() {}

KadConfig_Contact::KadConfig_Contact(const KadConfig_Contact& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    node_id_(const_cast< ::std::string*>(&_default_node_id_)),
    ip_(const_cast< ::std::string*>(&_default_ip_)),
    port_(0),
    local_ip_(const_cast< ::std::string*>(&_default_local_ip_)),
    local_port_(0),
    rendezvouz_ip_(const_cast< ::std::string*>(&_default_rendezvouz_ip_)),
    rendezvouz_port_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

KadConfig_Contact::~KadConfig_Contact() {
  if (node_id_ != &_default_node_id_) {
    delete node_id_;
  }
  if (ip_ != &_default_ip_) {
    delete ip_;
  }
  if (local_ip_ != &_default_local_ip_) {
    delete local_ip_;
  }
  if (rendezvouz_ip_ != &_default_rendezvouz_ip_) {
    delete rendezvouz_ip_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* KadConfig_Contact::descriptor() {
  if (KadConfig_Contact_descriptor_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return KadConfig_Contact_descriptor_;
}

const KadConfig_Contact& KadConfig_Contact::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return *default_instance_;
}

KadConfig_Contact* KadConfig_Contact::default_instance_ = NULL;

KadConfig_Contact* KadConfig_Contact::New() const {
  return new KadConfig_Contact;
}

const ::google::protobuf::Descriptor* KadConfig_Contact::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* KadConfig_Contact::GetReflection() const {
  if (KadConfig_Contact_reflection_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return KadConfig_Contact_reflection_;
}

// -------------------------------------------------------------------



KadConfig::KadConfig()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    port_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void KadConfig::InitAsDefaultInstance() {}

KadConfig::KadConfig(const KadConfig& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    port_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

KadConfig::~KadConfig() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* KadConfig::descriptor() {
  if (KadConfig_descriptor_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return KadConfig_descriptor_;
}

const KadConfig& KadConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return *default_instance_;
}

KadConfig* KadConfig::default_instance_ = NULL;

KadConfig* KadConfig::New() const {
  return new KadConfig;
}

const ::google::protobuf::Descriptor* KadConfig::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* KadConfig::GetReflection() const {
  if (KadConfig_reflection_ == NULL) protobuf_BuildDesc_general_5fmessages_2eproto();
  return KadConfig_reflection_;
}

}  // namespace base
