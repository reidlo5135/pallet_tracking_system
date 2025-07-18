#pragma once

#ifndef PTS_MQTT_HPP
#define PTS_MQTT_HPP

#include <string>
#include <functional>
#include <mqtt/async_client.h>

namespace pts
{
    namespace itf
    {
        class mqtt_client final
        {
        private:
            mqtt::async_client client_;
            std::function<void(const std::string &)> message_callback_;

        public:
            explicit mqtt_client(const std::string &url, const std::string &client_id);
            virtual ~mqtt_client();

            void connect();
            void publish(const std::string &topic, const std::string &payload, const int &qos, const bool &retained);
            void subscribe(const std::string &topic, std::function<void(const std::string &)> callback, const int &qos);
        };
    }
}

#endif