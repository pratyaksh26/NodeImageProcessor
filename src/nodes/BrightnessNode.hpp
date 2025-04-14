#pragma once
#include "NodeBase.hpp"

class BrightnessNode : public NodeBase {
public:
    BrightnessNode();
    void process() override;
    void renderProperties() override;
private:
    float brightness_; // Brightness adjustment (-100 to +100)
};