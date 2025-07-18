#ifndef PRESENTATION_NODE_HPP
#define PRESENTATION_NODE_HPP

#include <rclcpp/rclcpp.hpp>

#include "application/image.hpp"

#define NODE_NAME "pts_camera_streamer"

namespace pts
{
    namespace cam
    {
        class Streamer final : public rclcpp::Node
        {
        private:
            rclcpp::Node::SharedPtr node_;
            Image::SharedPtr image_;

        public:
            explicit Streamer();
            virtual ~Streamer();
        };
    }
}

#endif