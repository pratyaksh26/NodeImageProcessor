#pragma once
#include "NodeBase.hpp"

class OutputNode : public NodeBase {
public:
    OutputNode();
    void process() override;
    void renderProperties() override;
private:
    std::string save_path_;
    int quality_;
    int format_; // 0: JPG, 1: PNG, 2: BMP
};