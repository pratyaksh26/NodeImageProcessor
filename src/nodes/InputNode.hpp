#pragma once
#include "NodeBase.hpp"

class InputNode : public NodeBase {
public:
    InputNode();
    void process() override;
    void renderProperties() override;
private:
    std::string filepath_;
    cv::Mat image_;
};