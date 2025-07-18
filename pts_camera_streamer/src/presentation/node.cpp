#include "presentation/node.hpp"

using namespace pts::cam;

Streamer::Streamer()
    : Node(NODE_NAME)
{
    this->node_ = std::shared_ptr<rclcpp::Node>(this, [](rclcpp::Node *) {});

    this->image_ = std::make_shared<Image>(this->node_);
}

Streamer::~Streamer() = default;