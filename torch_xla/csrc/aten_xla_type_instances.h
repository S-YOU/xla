// Autogenerated file by gen.py. Do not edit directly!
#include "aten_xla_type.h"

#include <ATen/Context.h>

namespace torch_xla {


class XLATypeByte : public AtenXlaType {
 public:
  XLATypeByte(at::TensorTypeId type_id, bool is_variable, bool is_undefined)
    : AtenXlaType(type_id, is_variable, is_undefined) {}

  at::ScalarType scalarType() const override {
    return at::ScalarType::Byte;
  }

  const char* toString() const override {
    return "XLATypeByte";
  }

  size_t elementSizeInBytes() const override {
    return 1;
  }
};

static inline at::Type* GetXLATypeByte() {
  static XLATypeByte* xla_type = new XLATypeByte(
    c10::HIPTensorId(), /*is_variable=*/false, /*is_undefined=*/false);
  return xla_type;
}


class XLATypeChar : public AtenXlaType {
 public:
  XLATypeChar(at::TensorTypeId type_id, bool is_variable, bool is_undefined)
    : AtenXlaType(type_id, is_variable, is_undefined) {}

  at::ScalarType scalarType() const override {
    return at::ScalarType::Char;
  }

  const char* toString() const override {
    return "XLATypeChar";
  }

  size_t elementSizeInBytes() const override {
    return 1;
  }
};

static inline at::Type* GetXLATypeChar() {
  static XLATypeChar* xla_type = new XLATypeChar(
    c10::HIPTensorId(), /*is_variable=*/false, /*is_undefined=*/false);
  return xla_type;
}


class XLATypeShort : public AtenXlaType {
 public:
  XLATypeShort(at::TensorTypeId type_id, bool is_variable, bool is_undefined)
    : AtenXlaType(type_id, is_variable, is_undefined) {}

  at::ScalarType scalarType() const override {
    return at::ScalarType::Short;
  }

  const char* toString() const override {
    return "XLATypeShort";
  }

  size_t elementSizeInBytes() const override {
    return 2;
  }
};

static inline at::Type* GetXLATypeShort() {
  static XLATypeShort* xla_type = new XLATypeShort(
    c10::HIPTensorId(), /*is_variable=*/false, /*is_undefined=*/false);
  return xla_type;
}


class XLATypeInt : public AtenXlaType {
 public:
  XLATypeInt(at::TensorTypeId type_id, bool is_variable, bool is_undefined)
    : AtenXlaType(type_id, is_variable, is_undefined) {}

  at::ScalarType scalarType() const override {
    return at::ScalarType::Int;
  }

  const char* toString() const override {
    return "XLATypeInt";
  }

  size_t elementSizeInBytes() const override {
    return 4;
  }
};

static inline at::Type* GetXLATypeInt() {
  static XLATypeInt* xla_type = new XLATypeInt(
    c10::HIPTensorId(), /*is_variable=*/false, /*is_undefined=*/false);
  return xla_type;
}


class XLATypeLong : public AtenXlaType {
 public:
  XLATypeLong(at::TensorTypeId type_id, bool is_variable, bool is_undefined)
    : AtenXlaType(type_id, is_variable, is_undefined) {}

  at::ScalarType scalarType() const override {
    return at::ScalarType::Long;
  }

  const char* toString() const override {
    return "XLATypeLong";
  }

  size_t elementSizeInBytes() const override {
    return 8;
  }
};

static inline at::Type* GetXLATypeLong() {
  static XLATypeLong* xla_type = new XLATypeLong(
    c10::HIPTensorId(), /*is_variable=*/false, /*is_undefined=*/false);
  return xla_type;
}


class XLATypeFloat : public AtenXlaType {
 public:
  XLATypeFloat(at::TensorTypeId type_id, bool is_variable, bool is_undefined)
    : AtenXlaType(type_id, is_variable, is_undefined) {}

  at::ScalarType scalarType() const override {
    return at::ScalarType::Float;
  }

  const char* toString() const override {
    return "XLATypeFloat";
  }

  size_t elementSizeInBytes() const override {
    return 4;
  }
};

static inline at::Type* GetXLATypeFloat() {
  static XLATypeFloat* xla_type = new XLATypeFloat(
    c10::HIPTensorId(), /*is_variable=*/false, /*is_undefined=*/false);
  return xla_type;
}


static inline void RegisterAtenXlaTypes() {
  auto& context = at::globalContext();
  context.registerType(at::Backend::HIP, at::ScalarType::Byte, GetXLATypeByte());
  context.registerType(at::Backend::HIP, at::ScalarType::Char, GetXLATypeChar());
  context.registerType(at::Backend::HIP, at::ScalarType::Float, GetXLATypeFloat());
  context.registerType(at::Backend::HIP, at::ScalarType::Int, GetXLATypeInt());
  context.registerType(at::Backend::HIP, at::ScalarType::Long, GetXLATypeLong());
  context.registerType(at::Backend::HIP, at::ScalarType::Short, GetXLATypeShort());
}

}  // namespace torch_xla

