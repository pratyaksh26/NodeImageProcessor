#pragma once
#include "NodeBase.hpp"

class BlurNode : public NodeBase {
public:
    BlurNode();
    void process() override;
    void renderProperties() override;
private:
    int kernel_size_; // Gaussian blur kernel size (odd, 3 to 31)
};