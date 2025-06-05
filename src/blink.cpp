#define F_CPU 16000000UL

#include "avr.hpp"

#include <util/delay.h>

int main() {
  const avr::Pin<avr::port::b, avr::pin::b5> led;
  for (;;) {
    led.toggle();
    _delay_ms(1000);
    led.toggle();
    _delay_ms(1000);
  }
}
