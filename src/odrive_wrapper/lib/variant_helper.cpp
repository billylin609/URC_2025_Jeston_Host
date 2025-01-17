#ifndef VARIANT_HELPER
#define VARIANT_HELPER

//#include <variant>
#include <cstdint>

typedef struct {
  bool val;
  bool pos;
} bool_t;

namespace PayloadVariant {
  // Todo:
  // 1. bad impl -> see similiar impl https://stackoverflow.com/questions/36717725/c-same-variable-act-as-int-and-float
  // Note: int sizing using a variable
  // 2. variant and index?
  union MsgPayload {
    bool_t _b;
    uint8_t _us;
    int16_t _is;
    uint32_t _u;
    int32_t _i;
    uint64_t _ul;
    float _f;
  };

  enum DataType {
    bool_t = 0,
    uint8_t = 1,
    int16_t = 2,
    uint32_t = 3,
    int32_t = 4,
    uint64_t = 5,
    float_t = 6
  };

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
