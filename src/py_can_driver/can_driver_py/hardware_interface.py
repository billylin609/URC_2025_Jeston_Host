# Import p Packages
import can
import yaml 

# TODO:
# Impl singleton for all the can interface and each have an attribute
class CanInstance:
    def __init__(self):
        # Check platform, read yml whitelist config
        # Try expect and enable the interface
        # self.can_bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
        self.read_config()
        self.get_device()
    
    def read_config(self):
        with open('config/interface.yaml', 'r') as file:
            self.devices = yaml.safe_load(file)
        
    def get_device(self):
        try:
            self.devices = self.devices["devices"]
        except KeyError:
            print("No valid CAN interface registered")




def main(args=None):
    test = CanInstance()
    test.read_config()

if __name__ == '__main__':
    main()
