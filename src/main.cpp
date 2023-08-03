#include <Arduino.h>

#define LED_PIN 21
#define BLINK_DELAY 250

int n = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("# Start #");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_DELAY);
  digitalWrite(LED_PIN, LOW);
  delay(BLINK_DELAY);

  // Serial.println(sin(n * 2 * 3.1415 / 20));
  // n++;
}

