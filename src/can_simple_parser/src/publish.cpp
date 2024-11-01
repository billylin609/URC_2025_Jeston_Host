#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "can_msg/msg/odrive_can.hpp"                                            // CHANGE

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<can_msg::msg::OdriveCAN>("topic", 10);  // CHANGE
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = can_msg::msg::OdriveCAN();                                   // CHANGE
    message.message = can_msg::msg::GenericCAN();
    message.message.arbitration_id = 1<<5 | 1;
    message.rtr = 1;                                                     // CHANGE
    RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: '" << message.message.arbitration_id << "'");    // CHANGE
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<can_msg::msg::OdriveCAN>::SharedPtr publisher_;             // CHANGE
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}