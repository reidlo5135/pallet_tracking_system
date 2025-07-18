#include "pts_mqtt/client.hpp"
#include <iostream>

int main(int argc, const char* const* argv)
{
    pts::itf::mqtt_client client("tcp://localhost:1883", "test_client");
    client.connect();
    client.subscribe("test/topic", [](const std::string &msg){
        std::cout << "Received : " << msg << '\n';
    }, 0);

    client.publish("test/topic", "hello mqtt", 0, false);
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}