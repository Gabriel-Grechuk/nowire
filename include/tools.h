#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <Arduino.h>

#include "nowire.h"

/**
 *  This function locks the application execution to prevent unexpected
 *  behavior.
 *
 *  It runs an S.O.S. in morse code in the LED_BUILTIN.
 */
void nwr_panic(const char *msg);

/**
 *  This function checks if the pin is already being used in somewhere else or
 *  if the pin in invalid.
 *
 *  Args
 *   pin pin:   The pin that must be checked.
 *  Returns
 *    true:  If the pin is being used.
 *    false: If the pin is not being used.
 */
boolean nwr_valid_pin(pin pin);


/**
 *  This funcion assigns a pin as being used.
 *
 *  Args
 *    pin pin:  Pin to be marked as being used.
 */
void nwr_use_pin(pin pin);

#endif // _TOOLS_H_
