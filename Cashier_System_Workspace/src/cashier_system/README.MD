# ROS 2 Cashier System
## PROBLEM STATEMENT
Create a Cashier System where one node will publish a Bill message, another node will subscribe to the topic and update the inventory and income. 

Inventory and Income are ROS2 parameters stored on the rosparameter server.

A ROS2 service must be called from the second nod`e to update these parameters.
Bill message definition:
Bill Number
Time stamp
Quantity
Price
Total

Create third node which on any input prints the Last Bill message as well as the current inventory and income


## Overview

This ROS 2 package implements a simple cashier system with three core nodes that demonstrate inter-node communication and parameter management:

1. **Publisher Node**: Generates and publishes bill information
2. **Listener Node**: Tracks and displays bill details and system status
3. **Cashier Node**: Monitors and logs total sales

## Features

- Real-time bill generation
- Inventory tracking
- Sales monitoring
- Interactive bill viewing
- Timestamp logging

## System Architecture

### Nodes

#### Bill Publisher Node
- Generates bills at 1-second intervals
- Tracks bill numbers and inventory
- Publishes bill details to `bill_topic`

#### Bill Listener Node
- Subscribes to `bill_topic`
- Tracks current inventory
- Provides interactive bill and status viewing
- Allows real-time status checks

#### Cashier Node
- Monitors total sales
- Logs bill and sales information

### Message Structure

`Bill.msg` contains:
- `bill_number`: Unique identifier for each bill
- `timestamp`: Bill creation time
- `quantity`: Number of items sold
- `price`: Price per item
- `total`: Total bill amount

## Prerequisites

- ROS 2 Humble (or compatible version)
- C++17 compatible compiler
- CMake

## YOUTUBE VIDEO LINK
https://youtu.be/GASnjODQGP0



