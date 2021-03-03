
#include "vehicleserver.h"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VehicleServer>());
    rclcpp::shutdown();
    return 0;
}

