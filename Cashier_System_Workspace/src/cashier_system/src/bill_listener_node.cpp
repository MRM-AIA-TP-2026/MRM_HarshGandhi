#include <rclcpp/rclcpp.hpp>
#include <cashier_system/msg/bill.hpp>
#include <iostream>

class BillListenerNode : public rclcpp::Node {
public:
    BillListenerNode() : Node("bill_listener_node"), latest_bill_(nullptr) {
        // Declare parameters with default values
        this->declare_parameter<int>("inventory", 100);
        this->declare_parameter<double>("total_sales", 0.0);
        
        // Subscriber to 'bill_topic'
        subscription_ = this->create_subscription<cashier_system::msg::Bill>(
            "bill_topic", 10, 
            std::bind(&BillListenerNode::billCallback, this, std::placeholders::_1)
        );
    }

    void waitForInput() {
        while (rclcpp::ok()) {
            std::string input;
            std::cout << "Press Enter to view latest bill and status (or 'q' to quit): ";
            std::getline(std::cin, input);

            if (input == "q") {
                break;
            }

            // If a bill has been received
            if (latest_bill_) {
                // Get current values of parameters
                int inventory = this->get_parameter("inventory").as_int();
                double total_sales = this->get_parameter("total_sales").as_double();

                RCLCPP_INFO(this->get_logger(), 
                    "Latest Bill Details:\n"
                    "Bill Number: %d\n"
                    "Quantity: %d\n"
                    "Price per Item: $%.2f\n"
                    "Total: $%.2f", 
                    latest_bill_->bill_number, 
                    latest_bill_->quantity, 
                    latest_bill_->price,
                    latest_bill_->total);

                RCLCPP_INFO(this->get_logger(), 
                    "Current Status:\n"
                    "Inventory: %d\n"
                    "Total Sales: $%.2f", 
                    inventory, total_sales);
            } else {
                RCLCPP_WARN(this->get_logger(), "No bills received yet.");
            }
        }
    }

private:
    void billCallback(const cashier_system::msg::Bill::SharedPtr msg) {
        // Update latest bill
        latest_bill_ = msg;

        // Get current values of parameters
        int inventory = this->get_parameter("inventory").as_int();
        double total_sales = this->get_parameter("total_sales").as_double();

        // Update inventory and total sales
        inventory -= msg->quantity;
        total_sales += msg->total;

        // Update parameters
        this->set_parameter(rclcpp::Parameter("inventory", inventory));
        this->set_parameter(rclcpp::Parameter("total_sales", total_sales));
    }

    rclcpp::Subscription<cashier_system::msg::Bill>::SharedPtr subscription_;
    cashier_system::msg::Bill::SharedPtr latest_bill_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BillListenerNode>();

    // Create a separate thread for ROS spinning
    std::thread spin_thread([&]() {
        rclcpp::spin(node);
    });

    // Wait for input in the main thread
    node->waitForInput();

    // Shutdown ROS and join the spin thread
    rclcpp::shutdown();
    spin_thread.join();

    return 0;
}
