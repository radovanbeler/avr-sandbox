#ifndef AVR_HPP
#define AVR_HPP

#include <stdint.h>

namespace avr {
  using pin_type = uint8_t;
  using port_type = uint8_t;

  namespace port {
    constexpr port_type b = 0x25;
  }

  namespace pin {
    constexpr pin_type b5 = 1 << 5;
  }

  template <const port_type port, const pin_type pin>
  struct Pin {
    Pin() {
      *reinterpret_cast<volatile pin_type*>(port) &= static_cast<pin_type>(~pin);
      *reinterpret_cast<volatile pin_type*>(port - 1) |= pin;
    }

    void toggle() const noexcept {
      *reinterpret_cast<volatile pin_type*>(port) ^= pin;
    }
  };
}

#endif
