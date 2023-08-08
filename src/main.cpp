#include <Arduino.h>
#include <esp32_smartdisplay.h>
#include <../src/ui/ui.h>



void setup()
{
  Serial.begin(115200);

  smartdisplay_init();
  ui_init();
}

void loop()
{
  auto r = (byte)(millis() / 75);
  auto g = (byte)(millis() / 10);
  auto b = (byte)(millis() / 150);

  smartdisplay_set_led_color(lv_color32_t({.ch = {.blue = b, .green = g, .red = r}}));

  lv_timer_handler();
}
