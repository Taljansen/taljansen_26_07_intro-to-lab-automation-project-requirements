

#include "Arduino_SensorKit.h"

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);                        // flip if text is upside down for you
  Oled.setFont(u8x8_font_chroma48medium8_r);     // a basic readable font
}

void loop() {
  Oled.setCursor(0, 0);      // column 0, row 0 = top left
  Oled.print("echo");
  delay(500);
}