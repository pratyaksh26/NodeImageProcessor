#include "nodes/InputNode.hpp"
#include <imgui.h>
#include <opencv2/imgcodecs.hpp>
#include <filesystem>

InputNode::InputNode() : NodeBase("Input Node", 0, 1) {}

void InputNode::process() {
    if (!filepath_.empty()) {
        image_ = cv::imread(filepath_, cv::IMREAD_COLOR);
        if (!image_.empty()) {
            outputs_[0] = image_.clone();
        } else {
            outputs_[0] = cv::Mat();
        }
    }
}

void InputNode::renderProperties() {
    char buffer[256];
    strncpy(buffer, filepath_.c_str(), sizeof(buffer));
    if (ImGui::InputText("File Path", buffer, sizeof(buffer))) {
        filepath_ = buffer;
        process();
    }
    if (!image_.empty()) {
        ImGui::Text("Dimensions: %d x %d", image_.cols, image_.rows);
        ImGui::Text("File Size: %zu KB", std::filesystem::file_size(filepath_) / 1024);
        ImGui::Text("Format: %s", std::filesystem::path(filepath_).extension().c_str());
    }
}