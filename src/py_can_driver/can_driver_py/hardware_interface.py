# Import p Packages
import can
import yaml 


class CanInstance:
    def __init__(self):
        # Check platform, read yml whitelist config
        # Try expect and enable the interface
        # self.can_bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
        pass
    
    def read_config(self):
        with open('config/interface.yaml', 'r') as file:
            devices = yaml.safe_load(file)
            print(devices)



def main(args=None):
    test = CanInstance()
    test.read_config()

if __name__ == '__main__':
    main()
