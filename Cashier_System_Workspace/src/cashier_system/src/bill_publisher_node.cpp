#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "cashier_system/msg/bill.hpp"
#include <chrono>
#include <iomanip>
#include <ctime>

class BillPublisherNode : public rclcpp::Node {
public:
    BillPublisherNode() : Node("bill_publisher_node") {
        publisher_ = this->create_publisher<cashier_system::msg::Bill>("bill_topic", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),  // Publish a bill every second for demonstration
            std::bind(&BillPublisherNode::publishBill, this)
        );
        quantity_ = 100;  // Starting quantity of inventory
        bill_number_ = 0;
        price_per_quantity_ = 10.50;  // Price per quantity
    }

private:
    void publishBill() {
        if (quantity_ > 0) {
            auto bill = cashier_system::msg::Bill();
            bill_number_++;
            bill.bill_number = bill_number_;
            bill.timestamp = this->now();  // Add the timestamp for the bill
            bill.quantity = 1;  // Example quantity (can be adjusted per bill)
            bill.price = price_per_quantity_;  // Price per quantity
            bill.total = bill.quantity * price_per_quantity_;  // Total price for this bill
            
            // Decrease quantity in publisher node
            quantity_--;

            // Extract seconds from the timestamp
            int64_t timestamp_sec = bill.timestamp.sec;
            
            // Convert timestamp_sec to a system time (chrono)
            std::chrono::system_clock::time_point time_point = 
                std::chrono::system_clock::from_time_t(timestamp_sec);
            std::time_t time_t_format = std::chrono::system_clock::to_time_t(time_point);
            std::tm tm = *std::localtime(&time_t_format);

            // Format the time into a readable string (HH:MM:SS)
            std::ostringstream timestamp_stream;
            timestamp_stream << std::put_time(&tm, "%H:%M:%S");  // 24-hour format (HH:MM:SS)
            std::string timestamp_str = timestamp_stream.str();

            RCLCPP_INFO(this->get_logger(), 
                "Publishing Bill: Number %d, Quantity %d, Price per Quantity $%.2f, Total $%.2f, Timestamp: %s, Remaining Quantity: %d", 
                bill.bill_number, bill.quantity, price_per_quantity_, bill.total, 
                timestamp_str.c_str(), quantity_);

            publisher_->publish(bill);
        } else {
            RCLCPP_WARN(this->get_logger(), "No more inventory left to publish bills.");
        }
    }

    rclcpp::Publisher<cashier_system::msg::Bill>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    uint32_t quantity_;  // Inventory count
    uint32_t bill_number_;  // Bill number tracker
    double price_per_quantity_;  // Price per single quantity item
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BillPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
