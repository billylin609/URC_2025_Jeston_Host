#ifndef CAN_WRAPPER

#include <stdint.h>
#include <iterator>
#include <algorithm>
#include <bit>

#define arbitration_mask(uint8_t axis, uint8_t cmd) { return axis<<5|cmd; }
#define CAN_MSG_MAX_SIZE 8

class Msg {
		/*complete this class*/
		virtual encode(uint8_t &msg) = 0;
		virtual decode(uint8_t &msg) = 0;
		
		virtual get_id() = 0;
		virtual get_msg() = 0;

		virtual ~Msg() = 0;
}

class CanMessage: Msg {
		public
			CanMessage(uint8_t axis, uint8_t cmd, bool rtr, uint8_t dlc, uint8_t *buf)
				: id(arbitration_mask(axis, cmd)), rtr(rtr) {
					if (dlc <= CAN_MSG_MAX_SIZE) {
						this -> dlc = dlc;
						this -> msg = buf
					} else {
						throw std::range_error::range_error(std:format("CAN msg buffer out of bound. Expected MAX SIZE == {}. Received MAX SIZE == {}", CAN_MSG_MAX_SIZE, dlc));
					}
			}

			

				
		private:
				/* CAN Message format */
				uint32_t id = 0x000;
				bool isExt = false;
				bool rtr = false;
				uint8_t dlc = 8;
				uint8_t msg[8] = {0, 0, 0, 0, 0, 0, 0, 0};
				/* template*/
				// endian conversion
				// impl begin and end method
				// use std::reverse()
				// cpp representation IEEE 754 and value (memcpy or try std::bit_cast) [c++20]
}

#endif //CAN_WRAPPER
