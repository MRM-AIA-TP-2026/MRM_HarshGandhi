#include <rclcpp/rclcpp.hpp>
#include "cashier_system/msg/bill.hpp"

class CashierNode : public rclcpp::Node {
public:
    CashierNode() : Node("cashier_node") {
        // Create a subscription to the "bill_topic"
        subscription_ = this->create_subscription<cashier_system::msg::Bill>(
            "bill_topic", 10, 
            std::bind(&CashierNode::billCallback, this, std::placeholders::_1)
        );
        total_sales_ = 0.0;  // Initialize the total sales to 0
    }

private:
    void billCallback(const cashier_system::msg::Bill::SharedPtr msg) {
        // Calculate the total sales by adding the current bill's total
        total_sales_ += msg->total;

        // Log the total sales and bill details
        RCLCPP_INFO(this->get_logger(), 
                    "Received Bill:\n"
                    "Bill Number: %d\n"
                    "Quantity: %d\n"
                    "Total: $%.2f", 
                    msg->bill_number, msg->quantity, msg->total);
        
        RCLCPP_INFO(this->get_logger(), 
                    "Current Total Sales: $%.2f", 
                    total_sales_);
    }

    rclcpp::Subscription<cashier_system::msg::Bill>::SharedPtr subscription_;
    double total_sales_;  // Variable to track the total sales
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CashierNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
