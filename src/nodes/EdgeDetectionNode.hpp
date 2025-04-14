#pragma once
#include "NodeBase.hpp"

class EdgeDetectionNode : public NodeBase {
public:
    EdgeDetectionNode();
    void process() override;
    void renderProperties() override;
private:
    float threshold1_; // First Canny threshold
    float threshold2_; // Second Canny threshold
};