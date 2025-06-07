#include "avr.hpp"

int main() {
  const auto led = avr::Pin<avr::port::b, avr::pin::b5> {};

  for (;;) {
    led.toggle();
    avr::delay_ms(1000);
    led.toggle();
    avr::delay_ms(1000);
  }
}
