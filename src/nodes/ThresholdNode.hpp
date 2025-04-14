#pragma once
#include "NodeBase.hpp"

class ThresholdNode : public NodeBase {
public:
    ThresholdNode();
    void process() override;
    void renderProperties() override;
private:
    float threshold_; // Threshold value (0 to 255)
};