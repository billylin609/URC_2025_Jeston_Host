## ./py_can_driver

project structure:
+----ROS TOPIC (TX && RX) [arbitration, rtr, dlc, data]
    +----module(py tx & rx)
        +----Abstract base class(initialization)
        |   +----interface initialization
        |   +----use abstract class to access object
        +----Abstract base class(transmit)
        |   +----CAN TX
        +----Abstract base class(receive)
            +----CAN RX

### Goal:
This program handles logic:
1. CAN interface initialization
2. CAN transmit
3. CAN receive
4. forward TX/RX message to the high level manager
5. LOG data input instance [DEBUG]
