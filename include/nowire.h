#ifndef _NOWIRE_H_
#define _NOWIRE_H_

/**
 *  This defines the max amount on GPIO pins in the board.
 */
#define MAX_PINS 25

/**
 *  Defines a `pin` type.
 */
typedef unsigned char pin;

/**
 *  Used pin inside the program.
 */
#define LEFT_ULTRASONIC_SENSOR_TRIG 23
#define LEFT_ULTRASONIC_SENSOR_ECHO 22

#define RIGHT_ULTRASONIC_SENSOR_TRIG 5
#define RIGHT_ULTRASONIC_SENSOR_ECHO 4

#define LEFT_DRIVE_IN1 27
#define LEFT_DRIVE_IN2 14

#define RIGHT_DRIVE_IN1 12
#define RIGHT_DRIVE_IN2 13


/**
 *  Defines the time that the car will run before stopping.
 * 
 *  Time in milliseconds
 */
#define RUNNING_TIME 2000

#endif // _NOWIRE_H_
