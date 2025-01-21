#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>

using namespace std::chrono_literals;

class RoverControlNode : public rclcpp::Node
{
public:
    RoverControlNode() : Node("rover_control_node")
    {
        // Publisher to control the rover
        velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Timer to update rover's control periodically
        timer_ = this->create_wall_timer(
            100ms, std::bind(&RoverControlNode::timer_callback, this));

        // Initialize state variables
        start_time_ = this->now();
        is_turning_ = false;
    }

private:
    void timer_callback()
    {
        auto current_time = this->now();
        double elapsed_time = (current_time - start_time_).seconds();

        if (elapsed_time >= 5.0) {
            if (!is_turning_) {
                // Start the turn
                is_turning_ = true;
                turn_start_time_ = current_time; // Record time when turning starts
                RCLCPP_INFO(this->get_logger(), "Starting 90-degree turn");
            }

            // Continue turning for 1.57 seconds (90 degrees)
            double turn_duration = 1.57;  // Time to turn 90 degrees (approx. π/2 seconds)
            if ((current_time - turn_start_time_).seconds() < turn_duration) {
                publish_velocity(0.0, 1.0);  // Turn with angular velocity
            } else {
                // Stop turning and reset for the next cycle
                publish_velocity(0.0, 0.0);
                is_turning_ = false;
                start_time_ = current_time; // Reset timer for the next forward motion
                RCLCPP_INFO(this->get_logger(), "Completed 90-degree turn");
            }
        } else {
            // Move forward
            publish_velocity(0.5, 0.0);
        }
    }

    void publish_velocity(double linear_x, double angular_z)
    {
        geometry_msgs::msg::Twist cmd_vel_msg;
        cmd_vel_msg.linear.x = linear_x;
        cmd_vel_msg.angular.z = angular_z;
        velocity_publisher_->publish(cmd_vel_msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Time start_time_;
    rclcpp::Time turn_start_time_;
    bool is_turning_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RoverControlNode>());
    rclcpp::shutdown();
    return 0;
}

