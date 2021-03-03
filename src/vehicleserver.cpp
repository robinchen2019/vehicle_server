#include "vehicleserver.h"

VehicleServer::VehicleServer():
    rclcpp::Node("vehicle_server")
{
    RCLCPP_INFO(this->get_logger(), "vehicle_server started");
    server_ = boost::shared_ptr<server>(new server(3188, 100));
    server_->run();
    RCLCPP_INFO(this->get_logger(), "tcp server stared");
}
