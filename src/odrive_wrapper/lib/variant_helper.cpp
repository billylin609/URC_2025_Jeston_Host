#ifndef VARIANT_HELPER
#define VARIANT_HELPER

#include <variant/variant.h>
#include <stdint/stdint.h>

template<class... Ts>
struct overloads: Ts... { using Ts::operator()...; }

static_assert(sizeof(uint8_t) == 1);
static_assert(sizeof(float) == 4);
static_assert(sizeof(bool) == 1)
using can_payload_t = std::variant<int, float, bool>;

// Generic lambda visitor, handles both int and string types
struct CallPrintName {
    void operator()(const Derived& d) { d.PrintName(); }    
    void operator()(const ExtraDerived& ed) { ed.PrintName(); }    
};


#endif //VARIANT_HELPER