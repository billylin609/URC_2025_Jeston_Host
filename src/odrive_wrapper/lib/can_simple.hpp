#ifndef CAN_WRAPPER

#include <stdint.h>
#include <iterator>

class Msg {
		/*complete this class*/
		virtual encode(uint8_t &msg) = 0;
		virtual decode(uint8_t &msg) = 0;
		virtual ~Msg() = 0;
}

class CanMessage: Msg {
		public
				CanMessage(uint8_t id, uint8_t cmd, bool rtr, uint8_t dlc, uint8_t *buf);
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
				// cpp representation IEEE 754 and value
}

#endif //CAN_WRAPPER
