#include "ops/threshold.h"
#include "elementwise.h"
#include "lowering_context.h"

namespace torch_xla {
namespace ir {
namespace ops {

Threshold::Threshold(const NodeOperand& input, float threshold, float value)
    : Node(ir::OpKind(at::aten::threshold), {input}, input.node->shape()),
      threshold_(threshold),
      value_(value) {}

XlaOpVector Threshold::Lower(LoweringContext* loctx) const {
  xla::XlaOp input = loctx->GetOutputOp(operand(0));
  xla::XlaOp output = BuildThreshold(input, input, threshold_, value_);
  return ReturnOp(output, loctx);
}

std::string Threshold::ToString() const {
  std::stringstream ss;
  ss << Node::ToString() << ", threshold=" << threshold_
     << ", value=" << value_;
  return ss.str();
}

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla
