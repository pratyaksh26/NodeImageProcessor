
#pragma once
#include "nodes/NodeBase.hpp"
#include <vector>
#include <memory>

class NodeGraph {
public:
    void addNode(std::shared_ptr<NodeBase> node);
    void process();
    void render();
    void handleLinkCreation(); // New: Handle ImNodes link events
private:
    std::vector<std::shared_ptr<NodeBase>> nodes_;
    std::vector<std::pair<int, int>> links_; // ImNodes links (start_attr, end_attr)
};