#include "nodes/ContrastNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

ContrastNode::ContrastNode() : NodeBase("Contrast Node", 1, 1), contrast_(1.0f) {}

void ContrastNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat output;
            // Adjust contrast using convertScaleAbs (alpha=contrast_, beta=0)
            cv::convertScaleAbs(input, output, contrast_, 0);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void ContrastNode::renderProperties() {
    if (ImGui::SliderFloat("Contrast", &contrast_, 0.5f, 2.0f, "%.2f")) {
        contrast_ = std::clamp(contrast_, 0.5f, 2.0f);
        process();
    }
}