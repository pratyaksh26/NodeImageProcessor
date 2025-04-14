#pragma once
#include "NodeBase.hpp"

class SharpenNode : public NodeBase {
public:
    SharpenNode();
    void process() override;
    void renderProperties() override;
private:
    float strength_; // Sharpening strength (0.0 to 2.0)
};