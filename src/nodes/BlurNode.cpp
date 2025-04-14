#include "nodes/BlurNode.hpp"
#include <imgui.h>
#include <opencv2/imgproc.hpp>

BlurNode::BlurNode() : NodeBase("Blur Node", 1, 1), kernel_size_(3) {}

void BlurNode::process() {
    if (!inputs_[0].empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            cv::Mat output;
            // Ensure kernel_size_ is odd and at least 3
            int ksize = kernel_size_ % 2 == 0 ? kernel_size_ + 1 : kernel_size_;
            ksize = std::max(3, ksize);
            // Apply Gaussian blur
            cv::GaussianBlur(input, output, cv::Size(ksize, ksize), 0);
            outputs_[0] = output.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    } else {
        outputs_[0] = cv::Mat();
    }
}

void BlurNode::renderProperties() {
    if (ImGui::SliderInt("Kernel Size", &kernel_size_, 3, 31)) {
        // Ensure kernel_size_ is odd
        if (kernel_size_ % 2 == 0) kernel_size_ += 1;
        kernel_size_ = std::clamp(kernel_size_, 3, 31);
        process();
    }
}