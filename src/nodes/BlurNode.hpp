// BlurNode.hpp
#pragma once
#include "NodeBase.hpp"

class BlurNode : public Node {
public:
    BlurNode();
    void process() override;
    void drawGUI() override;
    
private:
    int radius = 3;
    bool isGaussian = true;
};