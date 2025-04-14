#include "nodes/NodeBase.hpp"

size_t NodeBase::next_id_ = 0;

NodeBase::NodeBase(const std::string& name, size_t num_inputs, size_t num_outputs)
    : name_(name), id_(next_id_++), inputs_(num_inputs), outputs_(num_outputs) {}

void NodeBase::connectInput(size_t input_idx, std::shared_ptr<NodeBase> node, size_t output_idx) {
    if (input_idx < inputs_.size() && output_idx < node->outputs_.size()) {
        inputs_[input_idx].clear();
        inputs_[input_idx].push_back({node, output_idx});
    }
}

cv::Mat NodeBase::getOutput(size_t idx) const {
    if (idx < outputs_.size()) return outputs_[idx];
    return cv::Mat();
}

void NodeBase::renderNode() {
    ImNodes::BeginNode(id_);
    ImNodes::BeginNodeTitleBar();
    ImGui::TextUnformatted(name_.c_str());
    ImNodes::EndNodeTitleBar();

    for (size_t i = 0; i < inputs_.size(); ++i) {
        ImNodes::BeginInputAttribute(id_ * 100 + i);
        ImGui::Text("Input %zu", i);
        ImNodes::EndInputAttribute();
    }

    for (size_t i = 0; i < outputs_.size(); ++i) {
        ImNodes::BeginOutputAttribute(id_ * 100 + i + 50);
        ImGui::Text("Output %zu", i);
        ImNodes::EndOutputAttribute();
    }

    ImNodes::EndNode();
}