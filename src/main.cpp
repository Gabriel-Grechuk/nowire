#include <Arduino.h>

#include "nowire.h"
#include "sensors.h"
#include "tools.h"

UltrasonicSensor us_left = {
    LEFT_ULTRASONIC_SENSOR_TRIG, // Trig.
    LEFT_ULTRASONIC_SENSOR_ECHO, // Echo.
};

UltrasonicSensor us_right = {
    RIGHT_ULTRASONIC_SENSOR_TRIG, // Trig.
    RIGHT_ULTRASONIC_SENSOR_ECHO, // Echo.
};

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  nwr_setup_ultrasonic_sensor(&us_left);
  nwr_setup_ultrasonic_sensor(&us_right);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  long left_distance = nwr_read_ultrasonic_sensor(us_left);
  long right_distance = nwr_read_ultrasonic_sensor(us_right);

  Serial.print("Distances: ");
  Serial.print(left_distance);
  Serial.print(" <|> ");
  Serial.print(right_distance);
  Serial.print("\r");

  delay(10);
  digitalWrite(LED_BUILTIN, LOW);
  delay(10);
}
