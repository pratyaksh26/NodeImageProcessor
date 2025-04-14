#include "nodes/EdgeDetectionNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

EdgeDetectionNode::EdgeDetectionNode() : NodeBase("Edge Detection Node", 1, 1), threshold1_(50.0f), threshold2_(150.0f) {}

void EdgeDetectionNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat gray, edges, output;
            // Convert to grayscale if needed
            if (input.channels() == 3) {
                cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
            } else {
                gray = input.clone();
            }
            // Apply Canny edge detection
            cv::Canny(gray, edges, threshold1_, threshold2_);
            // Convert single-channel edges to 3-channel for compatibility
            cv::cvtColor(edges, output, cv::COLOR_GRAY2BGR);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void EdgeDetectionNode::renderProperties() {
    bool changed = false;
    changed |= ImGui::SliderFloat("Threshold 1", &threshold1_, 0.0f, 200.0f, "%.1f");
    changed |= ImGui::SliderFloat("Threshold 2", &threshold2_, 0.0f, 200.0f, "%.1f");
    if (changed) {
        threshold1_ = std::clamp(threshold1_, 0.0f, 200.0f);
        threshold2_ = std::clamp(threshold2_, 0.0f, 200.0f);
        process();
    }
}