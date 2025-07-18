#ifndef APPLICATION_IMAGE_HPP
#define APPLICATION_IMAGE_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

#include <ament_index_cpp/get_package_share_directory.hpp>

namespace pts
{
    namespace cam
    {
        class Image final
        {
        private:
            rclcpp::Node::SharedPtr node_;
            
            rclcpp::CallbackGroup::SharedPtr image_publisher_cb_group_;
            rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_publisher_;

        public:
            explicit Image(const rclcpp::Node::SharedPtr &node = nullptr);
            virtual ~Image();

        public:
            using SharedPtr = std::shared_ptr<Image>;
        };
    }
}

#endif