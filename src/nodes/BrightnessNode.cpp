#include "nodes/BrightnessNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

BrightnessNode::BrightnessNode() : NodeBase("Brightness Node", 1, 1), brightness_(0.0f) {}

void BrightnessNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat output;
            // Adjust brightness using convertScaleAbs (alpha=1, beta=brightness_)
            cv::convertScaleAbs(input, output, 1.0, brightness_);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void BrightnessNode::renderProperties() {
    if (ImGui::SliderFloat("Brightness", &brightness_, -100.0f, 100.0f, "%.1f")) {
        process();
    }
}