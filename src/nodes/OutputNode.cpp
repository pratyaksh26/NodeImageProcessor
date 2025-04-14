#include "nodes/OutputNode.hpp"
#include <imgui.h>
#include <opencv2/imgcodecs.hpp>

OutputNode::OutputNode() : NodeBase("Output Node", 1, 0), quality_(90), format_(0) {}

void OutputNode::process() {
    if (!inputs_[0].empty() && !save_path_.empty()) {
        cv::Mat input = inputs_[0][0].node->getOutput(inputs_[0][0].output_idx);
        if (!input.empty()) {
            std::vector<int> params;
            if (format_ == 0) { // JPG
                params = {cv::IMWRITE_JPEG_QUALITY, quality_};
            } else if (format_ == 1) { // PNG
                params = {cv::IMWRITE_PNG_COMPRESSION, quality_ / 10};
            }
            cv::imwrite(save_path_, input, params);
        }
    }
}

void OutputNode::renderProperties() {
    char buffer[256];
    strncpy(buffer, save_path_.c_str(), sizeof(buffer));
    if (ImGui::InputText("Save Path", buffer, sizeof(buffer))) {
        save_path_ = buffer;
    }
    ImGui::Combo("Format", &format_, "JPG\0PNG\0BMP\0");
    if (format_ == 0) {
        ImGui::SliderInt("Quality", &quality_, 0, 100);
    } else if (format_ == 1) {
        ImGui::SliderInt("Compression", &quality_, 0, 90);
    }
    if (ImGui::Button("Save")) {
        process();
    }
}