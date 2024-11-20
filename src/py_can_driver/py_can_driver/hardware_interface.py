# Import python Packages
import can
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
                # Var
                self.can_bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
            # Find runtime error
            except:




# Contain a dictionary of can interface instance also singleton
class FindDevice:
    _instance = None
    CONFIG = 'config/interface.yaml'
    # @return: dict:(key, CanInstance object)
    can_devices = []

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(FindDevice, cls).__new__(cls)
            # init code here
        # can interface code
        cls._instance.read_config()
        cls._instance.get_device()
        return cls._instance

    def read_config(self):
        with open(CONFIG, 'r') as file:
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
