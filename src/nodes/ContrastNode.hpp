#pragma once
#include "NodeBase.hpp"

class ContrastNode : public NodeBase {
public:
    ContrastNode();
    void process() override;
    void renderProperties() override;
private:
    float contrast_; // Contrast adjustment (0.5 to 2.0)
};