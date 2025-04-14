#pragma once
#include "NodeBase.hpp"

class SaturationNode : public NodeBase {
public:
    SaturationNode();
    void process() override;
    void renderProperties() override;
private:
    float saturation_; // Saturation adjustment (0.0 to 2.0)
};