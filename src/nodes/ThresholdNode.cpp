#include "nodes/ThresholdNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

ThresholdNode::ThresholdNode() : NodeBase("Threshold Node", 1, 1), threshold_(128.0f) {}

void ThresholdNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat gray, thresh, output;
            // Convert to grayscale if needed
            if (input.channels() == 3) {
                cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
            } else {
                gray = input.clone();
            }
            // Apply binary threshold
            cv::threshold(gray, thresh, threshold_, 255, cv::THRESH_BINARY);
            // Convert to 3-channel for compatibility
            cv::cvtColor(thresh, output, cv::COLOR_GRAY2BGR);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void ThresholdNode::renderProperties() {
    if (ImGui::SliderFloat("Threshold", &threshold_, 0.0f, 255.0f, "%.1f")) {
        threshold_ = std::clamp(threshold_, 0.0f, 255.0f);
        process();
    }
}