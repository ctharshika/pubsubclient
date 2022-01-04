#include <Arduino.h>
#include <SSD1306Wire.h>

void setup() {
  SSD1306Wire *display;

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(KEY_BUILTIN, INPUT);

  digitalWrite(LED_BUILTIN, 1);

  display = new SSD1306Wire(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64);
  display->init();
	display->flipScreenVertically();
	display->setFont(ArialMT_Plain_10);
	display->drawString(0, 0, "OLED initial done!");
	display->display();

  delay(2000);

  display->clear();
  display->display();
}

void loop() {
  // put your main code here, to run repeatedly:
}