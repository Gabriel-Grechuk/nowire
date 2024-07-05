#ifndef _SENSORS_H_
#define _SENSORS_H_

#include <Arduino.h>

#include "nowire.h"

/**
 *  Defines a struct to handle the pins used by a HC-SR04 ultrasonic sensor.
 */
typedef struct {
  pin trig;
  pin echo;
  boolean valid;
} UltrasonicSensor;

/**
 *  Checks the requested pins and configures them for a HC-SR04 ultrasonic
 *  sensor.
 *
 *  Args
 *    UltrasonicSensor sensor: The sensor pins to be validated and configured.
 */
void nwr_setup_ultrasonic_sensor(UltrasonicSensor *sensor);

/**
 *  Reads the HC-SR04 ultrasonic sensor and returns its values in centimeters
 *  (cm).
 *
 *  Args
 *    UltrasonicSensor sensor: The sensor config.
 *
 *  Returns
 *    long: The distance of a obj in centimeters (cm).
 */
long nwr_read_ultrasonic_sensor(UltrasonicSensor sensor);

#endif // _SENSORS_H_
