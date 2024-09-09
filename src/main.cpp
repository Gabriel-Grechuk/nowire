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

int trigButton = 1;

void run_car(int millisec){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);

  /* The activation order should be exactly as bellow.
   * There is some delay at the 
   */
  digitalWrite(LEFT_DRIVE_IN1, LOW);
  digitalWrite(LEFT_DRIVE_IN2, HIGH);
  digitalWrite(RIGHT_DRIVE_IN1, HIGH);
  digitalWrite(RIGHT_DRIVE_IN2, LOW);

  delay(millisec);

  digitalWrite(LEFT_DRIVE_IN2, LOW);
  digitalWrite(RIGHT_DRIVE_IN1, LOW);
  digitalWrite(LEFT_DRIVE_IN1, LOW);
  digitalWrite(RIGHT_DRIVE_IN2, LOW);

  digitalWrite(LED_BUILTIN, LOW);
}


void setup() {
  /* Serial */
  Serial.begin(115200);

  /* Activate button */
  pinMode(0, INPUT);

  /* Led */
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  /* Motor drive */
  pinMode(LEFT_DRIVE_IN1, OUTPUT);
  pinMode(LEFT_DRIVE_IN2, OUTPUT);

  pinMode(RIGHT_DRIVE_IN1, OUTPUT);
  pinMode(RIGHT_DRIVE_IN2, OUTPUT);
}

void loop() {
  trigButton = digitalRead(0);

  if(!trigButton){
    run_car(RUNNING_TIME);
  }

  trigButton = 0;
  digitalWrite(LED_BUILTIN, LOW);
}
