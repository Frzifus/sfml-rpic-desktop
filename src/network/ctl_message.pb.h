// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CtlMessage.proto

#ifndef PROTOBUF_CtlMessage_2eproto__INCLUDED
#define PROTOBUF_CtlMessage_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace Network {
class CtlMessage;
class CtlMessageDefaultTypeInternal;
extern CtlMessageDefaultTypeInternal _CtlMessage_default_instance_;
}  // namespace Network

namespace Network {

namespace protobuf_CtlMessage_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_CtlMessage_2eproto

enum CtlMessage_Direction {
  CtlMessage_Direction_X = 0,
  CtlMessage_Direction_Y = 1,
  CtlMessage_Direction_CtlMessage_Direction_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CtlMessage_Direction_CtlMessage_Direction_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CtlMessage_Direction_IsValid(int value);
const CtlMessage_Direction CtlMessage_Direction_Direction_MIN = CtlMessage_Direction_X;
const CtlMessage_Direction CtlMessage_Direction_Direction_MAX = CtlMessage_Direction_Y;
const int CtlMessage_Direction_Direction_ARRAYSIZE = CtlMessage_Direction_Direction_MAX + 1;

const ::google::protobuf::EnumDescriptor* CtlMessage_Direction_descriptor();
inline const ::std::string& CtlMessage_Direction_Name(CtlMessage_Direction value) {
  return ::google::protobuf::internal::NameOfEnum(
    CtlMessage_Direction_descriptor(), value);
}
inline bool CtlMessage_Direction_Parse(
    const ::std::string& name, CtlMessage_Direction* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CtlMessage_Direction>(
    CtlMessage_Direction_descriptor(), name, value);
}
enum CtlMessage_CtlType {
  CtlMessage_CtlType_STOP = 0,
  CtlMessage_CtlType_VEHICLE = 1,
  CtlMessage_CtlType_CAMERA = 2,
  CtlMessage_CtlType_CtlMessage_CtlType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CtlMessage_CtlType_CtlMessage_CtlType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CtlMessage_CtlType_IsValid(int value);
const CtlMessage_CtlType CtlMessage_CtlType_CtlType_MIN = CtlMessage_CtlType_STOP;
const CtlMessage_CtlType CtlMessage_CtlType_CtlType_MAX = CtlMessage_CtlType_CAMERA;
const int CtlMessage_CtlType_CtlType_ARRAYSIZE = CtlMessage_CtlType_CtlType_MAX + 1;

const ::google::protobuf::EnumDescriptor* CtlMessage_CtlType_descriptor();
inline const ::std::string& CtlMessage_CtlType_Name(CtlMessage_CtlType value) {
  return ::google::protobuf::internal::NameOfEnum(
    CtlMessage_CtlType_descriptor(), value);
}
inline bool CtlMessage_CtlType_Parse(
    const ::std::string& name, CtlMessage_CtlType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CtlMessage_CtlType>(
    CtlMessage_CtlType_descriptor(), name, value);
}
// ===================================================================

class CtlMessage : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Network.CtlMessage) */ {
 public:
  CtlMessage();
  virtual ~CtlMessage();

  CtlMessage(const CtlMessage& from);

  inline CtlMessage& operator=(const CtlMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CtlMessage& default_instance();

  static inline const CtlMessage* internal_default_instance() {
    return reinterpret_cast<const CtlMessage*>(
               &_CtlMessage_default_instance_);
  }

  void Swap(CtlMessage* other);

  // implements Message ----------------------------------------------

  inline CtlMessage* New() const PROTOBUF_FINAL { return New(NULL); }

  CtlMessage* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CtlMessage& from);
  void MergeFrom(const CtlMessage& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CtlMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef CtlMessage_Direction Direction;
  static const Direction X =
    CtlMessage_Direction_X;
  static const Direction Y =
    CtlMessage_Direction_Y;
  static inline bool Direction_IsValid(int value) {
    return CtlMessage_Direction_IsValid(value);
  }
  static const Direction Direction_MIN =
    CtlMessage_Direction_Direction_MIN;
  static const Direction Direction_MAX =
    CtlMessage_Direction_Direction_MAX;
  static const int Direction_ARRAYSIZE =
    CtlMessage_Direction_Direction_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Direction_descriptor() {
    return CtlMessage_Direction_descriptor();
  }
  static inline const ::std::string& Direction_Name(Direction value) {
    return CtlMessage_Direction_Name(value);
  }
  static inline bool Direction_Parse(const ::std::string& name,
      Direction* value) {
    return CtlMessage_Direction_Parse(name, value);
  }

  typedef CtlMessage_CtlType CtlType;
  static const CtlType STOP =
    CtlMessage_CtlType_STOP;
  static const CtlType VEHICLE =
    CtlMessage_CtlType_VEHICLE;
  static const CtlType CAMERA =
    CtlMessage_CtlType_CAMERA;
  static inline bool CtlType_IsValid(int value) {
    return CtlMessage_CtlType_IsValid(value);
  }
  static const CtlType CtlType_MIN =
    CtlMessage_CtlType_CtlType_MIN;
  static const CtlType CtlType_MAX =
    CtlMessage_CtlType_CtlType_MAX;
  static const int CtlType_ARRAYSIZE =
    CtlMessage_CtlType_CtlType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  CtlType_descriptor() {
    return CtlMessage_CtlType_descriptor();
  }
  static inline const ::std::string& CtlType_Name(CtlType value) {
    return CtlMessage_CtlType_Name(value);
  }
  static inline bool CtlType_Parse(const ::std::string& name,
      CtlType* value) {
    return CtlMessage_CtlType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // int32 value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  ::google::protobuf::int32 value() const;
  void set_value(::google::protobuf::int32 value);

  // .Network.CtlMessage.Direction direction = 2;
  void clear_direction();
  static const int kDirectionFieldNumber = 2;
  ::Network::CtlMessage_Direction direction() const;
  void set_direction(::Network::CtlMessage_Direction value);

  // .Network.CtlMessage.CtlType ctl_type = 3;
  void clear_ctl_type();
  static const int kCtlTypeFieldNumber = 3;
  ::Network::CtlMessage_CtlType ctl_type() const;
  void set_ctl_type(::Network::CtlMessage_CtlType value);

  // @@protoc_insertion_point(class_scope:Network.CtlMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 value_;
  int direction_;
  int ctl_type_;
  mutable int _cached_size_;
  friend struct  protobuf_CtlMessage_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CtlMessage

// int32 value = 1;
inline void CtlMessage::clear_value() {
  value_ = 0;
}
inline ::google::protobuf::int32 CtlMessage::value() const {
  // @@protoc_insertion_point(field_get:Network.CtlMessage.value)
  return value_;
}
inline void CtlMessage::set_value(::google::protobuf::int32 value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:Network.CtlMessage.value)
}

// .Network.CtlMessage.Direction direction = 2;
inline void CtlMessage::clear_direction() {
  direction_ = 0;
}
inline ::Network::CtlMessage_Direction CtlMessage::direction() const {
  // @@protoc_insertion_point(field_get:Network.CtlMessage.direction)
  return static_cast< ::Network::CtlMessage_Direction >(direction_);
}
inline void CtlMessage::set_direction(::Network::CtlMessage_Direction value) {
  
  direction_ = value;
  // @@protoc_insertion_point(field_set:Network.CtlMessage.direction)
}

// .Network.CtlMessage.CtlType ctl_type = 3;
inline void CtlMessage::clear_ctl_type() {
  ctl_type_ = 0;
}
inline ::Network::CtlMessage_CtlType CtlMessage::ctl_type() const {
  // @@protoc_insertion_point(field_get:Network.CtlMessage.ctl_type)
  return static_cast< ::Network::CtlMessage_CtlType >(ctl_type_);
}
inline void CtlMessage::set_ctl_type(::Network::CtlMessage_CtlType value) {
  
  ctl_type_ = value;
  // @@protoc_insertion_point(field_set:Network.CtlMessage.ctl_type)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace Network

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Network::CtlMessage_Direction> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Network::CtlMessage_Direction>() {
  return ::Network::CtlMessage_Direction_descriptor();
}
template <> struct is_proto_enum< ::Network::CtlMessage_CtlType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Network::CtlMessage_CtlType>() {
  return ::Network::CtlMessage_CtlType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CtlMessage_2eproto__INCLUDED