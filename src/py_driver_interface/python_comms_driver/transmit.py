# Base Class Transmit
# TODO:Base class for all transmit and then one transmit childclass for can impl
# abstrat class for all the communication

import can

class transmit:

class Can_Transmit {
        def __init__(self, interface) { #legal?
            self.interface = ;
        }

        def ROS_listening_node(self) {
            if msg != NULL:
                self.transmit(msg)
            else:
                LOG()
        }

        def transmit(self) {
            msg = can.Message(arbitration_id = uwrap(msg, Arbitration_id),
                id_remote_frame = uwrap(msg, RTR),
                data = 
        }
        
        def HARDWARE_TRANSMITi() {
            bus.send(self.msg)
        }
}



# TODO: unwrap use enum implmentation => return data field

# Note: data processing need to be done within the higher level driver
# data need also dlc information when encoding and decodeing
# Decouple ODrive related code to the higher level driver
