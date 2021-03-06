#pragma once

#include <ATen/Tensor.h>
#include <ATen/Type.h>
#include <c10/core/TensorImpl.h>

#include "tensor.h"

namespace torch_xla {

// Tensor implementation class used to be fed to the at::Tensor.
// Its scope is just to handle an XLATensor.
class XLATensorImpl : public c10::TensorImpl {
 public:
  XLATensorImpl(XLATensor tensor);

  XLATensor& tensor() { return tensor_; }

 private:
  static caffe2::TypeMeta GetTypeMeta(const XLATensor& tensor);

  XLATensor tensor_;
};

}  // namespace torch_xla
