# URC_2025_Jeston_Host
This is the project for URC 2025 season code for the jetson host.

This project will only contains codes that is linked with hardware.

# TODO(Questions):
- create a proper README file
- renaming this project and reconsider how to structure this?
- Do we need to have multiple version of ros available?

Folder structure:
config for setup can interface

Note:
if enable loopback mode need to reboot before able to properly using can interface
=======
In Devel branch please branch your feature under name devel/feature_name


# TODO:
# - Update README.md file

to build this project using colcon

> colcon build

# TODO:
Create a shell script
> source ./venv/bin/Activate
> project dependent build

VENV contain all the python dependencies

# Not setting up ROS bridge between two computer:
- setup LAN connection between two device
- controller over LAN[https://www.virtualhere.com/]
- video streaming
- https://www.geeksforgeeks.org/soft-real-time-communication-in-lan/?ref=ml_lbp
- https://www.geeksforgeeks.org/data-communication-tutorial/?ref=ml_lbp
