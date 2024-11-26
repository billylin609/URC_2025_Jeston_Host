# Import python Packages
import os

try:
  import can
except ImportError:
  print "Trying to Install required module: requests python-can\n"
  os.system('python3 -m pip install python-can')
import can
try:
  import yaml
except ImportError:
  print "Trying to Install requiredmodule: pyyaml\n"
  os.system('python3 -m pip install pyyaml')
import yaml 


# TODO:
# Proper documentation

# This is Parent class(for all the new can device)
class CanInstance:
    _instance = None

    def __new__(cls, arg1, arg2):
        if cls._instance is None:
            cls._instance = super(CanInstance, cls).__new__(cls)
            try:
                self.can_bus = can.interface.Bus(interface='slcan', channel='/dev/ttyACM0', bitrate=500000)
            # Find runtime error
            except:
                #interface not init properly
                pass




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
