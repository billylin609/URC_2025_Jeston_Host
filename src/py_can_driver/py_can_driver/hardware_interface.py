# Import python Packages
import os
from enum import Enum
try:
  import can
except ImportError:
  print "Trying to Install required module: requests python-can\n"
  os.system('python3 -m pip install python-can')
import can
try:
  import yaml
except ImportError:
  print "Trying to Install required module: requests pyyaml\n"
  os.system('python3 -m pip install pyyaml')
import yaml 

# TODO:
# Proper documentation

class std_ReturnType(Enum):
    E_NOT_OK = 0
    E_OK = 1

# This is Parent class(for all the new can device)
class CanInstance:
    _instance = None
    _status = std_ReturnType.E_NOT_OK

    def __new__(cls, interface, channel, bitrate):
        if cls._instance is None:
            cls._instance = super(CanInstance, cls).__new__(cls)
            try:
                # Var
                self.can_bus = can.interface.Bus(interface=interface, channel=channel, bitrate=bitrate)
                _status = std_ReturnType.E_OK
            # Find runtime error
            except:
                print("CAN Interface not available.")
                _status = std_ReturnType.E_NOT_OK

    def get_status(self):
        return self._status



# Contain a dictionary of can interface instance also singleton
class FindDevice:
    _instance = None
    # @return: dict:(key, CanInstance object)
    can_devices = []

    def __new__(cls, config):
        if cls._instance is None:
            cls._instance = super(FindDevice, cls).__new__(cls)
            # init code here
        # can interface code
        cls._instance.read_config(config)
        cls._instance.get_device()
        return cls._instance

    def read_config(self, config):
        with open(config, 'r') as file:
            self.devices = yaml.safe_load(file)
    
    def get_device(self):
        try:
            self.devices = self.devices["devices"]
        except KeyError:
            print("No valid CAN interface registered")
        for device in self.devices:
            print(device)

        

def main(args=None):


if __name__ == '__main__':
    main()
