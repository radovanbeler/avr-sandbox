#ifndef AVR_HPP
#define AVR_HPP

#include <stdint.h>
#include <util/delay.h>

namespace avr {
  using pin_type = uint8_t;
  using port_type = uint8_t;

  namespace port {
    constexpr port_type b = 0x25;
  }

  namespace pin {
    constexpr pin_type b5 = (1 << 5);
  }

  inline void delay_ms(double ms) {
    _delay_ms(ms);
  }

  template <const port_type port, const pin_type pin>
  class Pin final {
  public:
    Pin() {
      *reinterpret_cast<volatile pin_type*>(port) &= static_cast<pin_type>(~pin);
      *reinterpret_cast<volatile pin_type*>(port - 1) |= pin;
    }

    void toggle() const {
      *reinterpret_cast<volatile pin_type*>(port) ^= pin;
    }

  private:
    Pin(const Pin& other) = delete;
    Pin& operator=(const Pin& other) = delete;
  };
}

#endif
