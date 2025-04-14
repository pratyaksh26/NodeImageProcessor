#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <memory>
#include <imgui.h>
#include <imnodes.h>

class NodeBase {
public:
    struct Connection {
        std::shared_ptr<NodeBase> node;
        size_t output_idx;
    };

    NodeBase(const std::string& name, size_t num_inputs, size_t num_outputs);
    virtual ~NodeBase() = default;

    virtual void process() = 0;
    virtual void renderProperties() {}
    virtual void renderNode();

    void connectInput(size_t input_idx, std::shared_ptr<NodeBase> node, size_t output_idx);
    cv::Mat getOutput(size_t idx) const;
    const std::vector<std::vector<Connection>>& getInputs() const { return inputs_; }

    std::string getName() const { return name_; }
    size_t getId() const { return id_; }

protected:
    std::string name_;
    size_t id_;
    std::vector<std::vector<Connection>> inputs_;
    std::vector<cv::Mat> outputs_;
    static size_t next_id_;
};