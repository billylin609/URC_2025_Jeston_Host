# Import Sys Packages
import CAN
import sys
import glob
import serial


class CanInstance:
    def __init__(self):
        self.can_bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
        msg = bus.recv(None)        
    
    # TODO: more than one ACM device? check for ACM ID
    def serial_ports(self, id):
        """ Lists serial port names

            :raises EnvironmentError:
                On unsupported or unknown platforms
            :returns:
                A list of the serial ports available on the system
        """
        if sys.platform.startswith('win'):
            self.ports = ['COM%s' % (i + 1) for i in range(256)]
        elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
            # this excludes your current terminal "/dev/tty"
            self.ports = glob.glob('/dev/ttyACM[A-Za-z]*')
        elif sys.platform.startswith('darwin'):
            self.ports = glob.glob('/dev/ttyACM.*')
        else:
            raise EnvironmentError('Unsupported platform')
        # check dev ID (yaml WHITELIST) and return CODE