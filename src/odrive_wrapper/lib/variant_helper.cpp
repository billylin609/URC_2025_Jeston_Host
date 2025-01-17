#ifndef VARIANT_HELPER
#define VARIANT_HELPER

//#include <variant>
#include <cstdint>

using CustomDataType {
  /**
   * example: type_t(val, ..., sizeof(type_t)) 
   */
  

  // check syntax duplicate variable name
  // pass by reference?
  static_assert(sizeof(bool) == 1)
  class bool_t {
    public:
      bool_t(bool val, uint8_t pos, uint8_t size)
        : val(val), pos(pos), buf(val<<pos) {
          assert(size == this->size);
      }

      uint8_t getsize() { return this->size; }
    private:
      bool val;
      bool pos;
      uint8_t buf;
      uint8_t size = 1;
  };

  class uint_t {
    public:
      uint_t(auto val, uint8_t size)
        : val(dynamic_cast<uint64_t>val), size(size) {
          assert (this->size <= 8);
      }

      uint8_t getsize() { return this->size; }
    private:
      uint64_t val;
      uint8_t size;
  };

  class int_t {
    public:
      int_t(auto val, uint8_t size)
        : val(dynamic_cast<int64_t>val), size(size) {
          assert (this->size <= 8);
      }

      uint8_t getsize() { return this->size; }
    private:
      int64_t val;
      uint8_t size;
  };

  static_assert(sizeof(float) == 4); 
  class float_t {
    public:
      int_t(float val)
        : val(val) {
      }

      uint8_t getsize() { return this->size; }
    private:
      float val;
      uint8_t size = 4;
  }
}

namespace PayloadVariant {
  // Todo:
  // 1. bad impl -> see similiar impl https://stackoverflow.com/questions/36717725/c-same-variable-act-as-int-and-float
  // Note: int sizing using a variable
  // 2. variant and index?

  class Payload{
    public:
      uint8_t sizeof
    private:
      int_t d;
      uint_t u;
      float f;
      bool_t b;
  }

  class MsgBuf {
      MsgBuf(input, type)
    private:
      MsgPayload buf;
      DataType type;
  }

  /** Todo: impl using variant
   * static_assert(sizeof(uint8_t) == 1);
   * static_assert(sizeof(float) == 4);
   * static_assert(sizeof(bool) == 1)
   * using can_payload_t = std::variant<int, float, bool_t>;

   * // Generic lambda visitor, handles int, boolean, and float types
   * // api: std::visit(visitor, val)
   * auto vistor = [](const auto& val) -> auto { return mem_cast(val); }
   **/

}

#endif //VARIANT_HELPER
