
#include "NodeGraph.hpp"

void NodeGraph::addNode(std::shared_ptr<NodeBase> node) {
    nodes_.push_back(node);
}

void NodeGraph::process() {
    for (auto& node : nodes_) {
        node->process();
    }
}

void NodeGraph::render() {
    ImNodes::BeginNodeEditor();
    for (auto& node : nodes_) {
        node->renderNode();
    }
    for (size_t i = 0; i < links_.size(); ++i) {
        ImNodes::Link(i, links_[i].first, links_[i].second);
    }
    ImNodes::EndNodeEditor();
}

void NodeGraph::handleLinkCreation() {
    int start_attr, end_attr;
    if (ImNodes::IsLinkCreated(&start_attr, &end_attr)) {
        // Find nodes and pin indices
        size_t from_node_id = start_attr / 100;
        size_t from_output_idx = (start_attr % 100) - 50;
        size_t to_node_id = end_attr / 100;
        size_t to_input_idx = end_attr % 100;

        std::shared_ptr<NodeBase> from_node = nullptr;
        std::shared_ptr<NodeBase> to_node = nullptr;
        for (auto& node : nodes_) {
            if (node->getId() == from_node_id) from_node = node;
            if (node->getId() == to_node_id) to_node = node;
        }

        if (from_node && to_node) {
            to_node->connectInput(to_input_idx, from_node, from_output_idx);
            links_.push_back({start_attr, end_attr});
        }
    }
}