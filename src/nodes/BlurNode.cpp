// BlurNode.cpp
#include "BlurNode.hpp"
#include <opencv2/opencv.hpp>

BlurNode::BlurNode() {
    // Initialize node properties
}

void BlurNode::process() {
    if(inputs.empty() || inputs[0]->output.empty()) return;
    
    if(isGaussian) {
        cv::GaussianBlur(inputs[0]->output, output, cv::Size(radius*2+1, radius*2+1), 0);
    } else {
        cv::blur(inputs[0]->output, output, cv::Size(radius*2+1, radius*2+1));
    }
}

void BlurNode::drawGUI() {
    // SFML/ImGui drawing code
}