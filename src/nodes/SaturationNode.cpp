#include "nodes/SaturationNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

SaturationNode::SaturationNode() : NodeBase("Saturation Node", 1, 1), saturation_(1.0f) {}

void SaturationNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat hsv, output;
            // Convert to HSV
            cv::cvtColor(input, hsv, cv::COLOR_BGR2HSV);
            // Split channels
            std::vector<cv::Mat> channels;
            cv::split(hsv, channels);
            // Adjust saturation (channel 1)
            channels[1] = channels[1] * saturation_;
            // Merge and convert back
            cv::merge(channels, hsv);
            cv::cvtColor(hsv, output, cv::COLOR_HSV2BGR);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void SaturationNode::renderProperties() {
    if (ImGui::SliderFloat("Saturation", &saturation_, 0.0f, 2.0f, "%.2f")) {
        saturation_ = std::clamp(saturation_, 0.0f, 2.0f);
        process();
    }
}