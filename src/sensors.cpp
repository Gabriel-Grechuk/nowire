#include "sensors.h"
#include "tools.h"

void nwr_setup_ultrasonic_sensor(UltrasonicSensor *sensor) {
  if (!nwr_valid_pin(sensor->trig) || !nwr_valid_pin(sensor->echo))
    nwr_panic("Invalid UltrasonicSensor pins!");

  nwr_use_pin(sensor->trig);
  nwr_use_pin(sensor->echo);
  pinMode(sensor->trig, OUTPUT);
  pinMode(sensor->echo, INPUT);
  sensor->valid = true;
}

long nwr_read_ultrasonic_sensor(UltrasonicSensor sensor) {
  if (!sensor.valid)
    nwr_panic("Sensor config not validated!");

  long duration = 0;
  long cm = 0.0;

  digitalWrite(sensor.trig, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor.trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor.trig, LOW);

  duration = pulseIn(sensor.echo, HIGH);
  cm = (duration / 29 / 2);

  return cm;
}
