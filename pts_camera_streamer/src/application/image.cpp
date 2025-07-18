#include "application/image.hpp"

using namespace pts::cam;

Image::Image(const rclcpp::Node::SharedPtr &node)
    : node_(node)
{
    if (this->node_ == nullptr)
    {
        return;
    }

    this->image_publisher_cb_group_ = this->node_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    rclcpp::PublisherOptions image_publisher_opts;
    image_publisher_opts.callback_group = this->image_publisher_cb_group_;
    this->image_publisher_ = this->node_->create_publisher<sensor_msgs::msg::Image>(
        "/camera/image",
        rclcpp::QoS(rclcpp::SystemDefaultsQoS()),
        image_publisher_opts);

    std::string image_path = ament_index_cpp::get_package_share_directory(this->node_->get_name()) + "/images/pallet.png";
    cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
}

Image::~Image() = default;