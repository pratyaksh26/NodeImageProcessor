#include "nodes/SharpenNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

SharpenNode::SharpenNode() : NodeBase("Sharpen Node", 1, 1), strength_(1.0f) {}

void SharpenNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat output;
            // Apply sharpening: output = input + strength * (input - blurred)
            cv::Mat blurred;
            cv::GaussianBlur(input, blurred, cv::Size(5, 5), 1.0);
            output = input + strength_ * (input - blurred);
            // Ensure pixel values are in valid range
            cv::normalize(output, output, 0, 255, cv::NORM_MINMAX);
            output.convertTo(output, CV_8U);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void SharpenNode::renderProperties() {
    if (ImGui::SliderFloat("Strength", &strength_, 0.0f, 2.0f, "%.2f")) {
        strength_ = std::clamp(strength_, 0.0f, 2.0f);
        process();
    }
}