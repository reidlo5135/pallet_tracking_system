#include "pts_mqtt/client.hpp"

using namespace pts::itf;

mqtt_client::mqtt_client(const std::string &url, const std::string &client_id)
    : client_(url, client_id)
{
}

mqtt_client::~mqtt_client() = default;

void mqtt_client::connect()
{
    mqtt::connect_options conn_opts;
    conn_opts.set_keep_alive_interval(20);
    conn_opts.set_clean_session(true);
    this->client_.connect(conn_opts)->wait();
}

void mqtt_client::publish(const std::string &topic, const std::string &payload, const int &qos, const bool &retained)
{
    this->client_.publish(topic, payload.c_str(), payload.length(), qos, retained);
}

void mqtt_client::subscribe(const std::string &topic, std::function<void(const std::string &)> callback, const int &qos)
{
    this->message_callback_ = callback;

    class callback_handler : public mqtt::callback
    {
    private:
        mqtt_client *parent_;

    public:
        explicit callback_handler(mqtt_client *parent) : parent_(parent)
        {
        }

        void message_arrived(mqtt::const_message_ptr msg) override 
        {
            if (this->parent_->message_callback_)
            {
                this->parent_->message_callback_(msg->to_string());
            }
        }
    };

    this->client_.set_callback(callback_handler(this));
    this->client_.subscribe(topic, qos)->wait();
}