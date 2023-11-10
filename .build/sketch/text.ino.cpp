#include <Arduino.h>
#line 1 "/Users/loki/Documents/Project/esp32.display/text/text.ino"
#include "display.h"

#line 3 "/Users/loki/Documents/Project/esp32.display/text/text.ino"
void MainSub(void);
#line 16 "/Users/loki/Documents/Project/esp32.display/text/text.ino"
void setup(void);
#line 28 "/Users/loki/Documents/Project/esp32.display/text/text.ino"
void loop(void);
#line 3 "/Users/loki/Documents/Project/esp32.display/text/text.ino"
void MainSub(void) {
  static uint32_t i = 0;
  static uint8_t j = 0;

  display.UpdataBit(j);

  if (++i == 250) {
    i = 0;
    if (++j == (4 * 16 - 1))
      j = 0;
  }
}

void setup(void) {
  display.SetFont(0, 0xB8E2);
  display.SetFont(1, 0xB5FA);
  display.SetFont(2, 0xB5BE);

  display.SetFont(4, 0xB8E2);
  display.SetFont(5, 0xB5FA);
  display.SetFont(6, 0xB5BE);

  display.InitDisplay();
}

void loop(void) {
  // MainSub();

  display.LoopDisplay();

  display.UpdataBit(56);

  delayMicroseconds(1);
}

