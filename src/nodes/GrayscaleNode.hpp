#pragma once
#include "NodeBase.hpp"

class GrayscaleNode : public NodeBase {
public:
    GrayscaleNode();
    void process() override;
    void renderProperties() override;
};