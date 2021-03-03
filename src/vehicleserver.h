#ifndef VEHICLESERVER_H
#define VEHICLESERVER_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "tcpserver.h"

class VehicleServer: public rclcpp::Node
{
public:
    VehicleServer();


private:
    boost::shared_ptr<server> server_;
};

#endif // VEHICLESERVER_H
