#include "nodes/GrayscaleNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

GrayscaleNode::GrayscaleNode() : NodeBase("Grayscale Node", 1, 1) {}

void GrayscaleNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat output;
            // Convert to grayscale
            if (input.channels() == 3) {
                cv::cvtColor(input, output, cv::COLOR_BGR2GRAY);
                // Convert back to 3 channels for compatibility
                cv::cvtColor(output, output, cv::COLOR_GRAY2BGR);
            } else {
                output = input.clone();
            }
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void GrayscaleNode::renderProperties() {
    ImGui::Text("Converts image to grayscale");
}