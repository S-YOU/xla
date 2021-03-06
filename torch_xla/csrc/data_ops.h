#pragma once

#include <vector>

#include "tensorflow/compiler/xla/client/xla_builder.h"
#include "tensorflow/core/lib/gtl/array_slice.h"
#include "torch/csrc/jit/ir.h"

// Collection of XLA lowerings for operations which only involve some form of
// data movement and no computation.
namespace torch_xla {

// For input_sizes and a potentially incomplete output_sizes, return a complete
// output shape. The complete output shape has same total number of elements as
// input_sizes and matches output_sizes in all dimensions except for at most
// one, which can be inferred and stored as -1 in output_sizes.
std::vector<xla::int64> GetCompleteShape(
    tensorflow::gtl::ArraySlice<const xla::int64> output_sizes,
    tensorflow::gtl::ArraySlice<const xla::int64> input_sizes);

// Creates a new tensor with the same data as the input tensor and the size
// specified by the "size" attribute of the given node.
xla::XlaOp BuildView(const torch::jit::Node* node, const xla::XlaOp& input);

// Same as above, with output size provided as parameter.
xla::XlaOp BuildView(
    const xla::XlaOp& input,
    tensorflow::gtl::ArraySlice<const xla::int64> output_sizes);

// Creates a new tensor with the singleton dimensions expanded to the sizes
// specified by the "size" attribute of the given node.
xla::XlaOp BuildExpand(const torch::jit::Node* node, const xla::XlaOp& input);

// Same as above, with output size provided as parameter.
xla::XlaOp BuildExpand(
    const xla::XlaOp& input,
    tensorflow::gtl::ArraySlice<const xla::int64> output_sizes);

// Concatenates a list of tensors along a new dimension specified by the "dim"
// attribute of the given node.
xla::XlaOp BuildStack(
    const torch::jit::Node* node,
    const std::function<xla::XlaOp(const torch::jit::Value*)>& node_op,
    xla::XlaBuilder* b);

// Concatenates a list of tensors along an existing dimension specified by the
// "dim" attribute of the given node.
xla::XlaOp BuildCat(
    const torch::jit::Node* node,
    const std::function<xla::XlaOp(const torch::jit::Value*)>& node_op,
    xla::XlaBuilder* b);

// Splits a tensor into a specific number of chunks specified by the "chunks"
// attribute of the given node, along an existing dimension specified by the
// "dim" attribute of the given node.
std::vector<xla::XlaOp> BuildChunk(const torch::jit::Node* node,
                                   const xla::XlaOp& input);

}  // namespace torch_xla
