# Import Sys Packages
import CAN
import sys
import glob
import serial


class CanInstance:
    def __init__(self):
        # Check platform, read yml whitelist config
        # Try expect and enable the interface
        self.can_bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
        msg = bus.recv(None)        
