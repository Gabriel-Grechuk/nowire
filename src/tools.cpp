#include "tools.h"

/**
 *  This global variable keeps track of all the used pins.
 */
pin nwr_used_pins[MAX_PINS] = {0};

void nwr_blink_morse_code(char c) {
  switch (c) {
  case 's': {
    // S is dot-dot-dot
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200); // Dot
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Gap between parts of the same letter
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200); // Dot
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Gap between parts of the same letter
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200); // Dot
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Gap between letters
  } break;

  case 'o': {
    // O is dash-dash-dash
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500); // Dash
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Gap between parts of the same letter
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500); // Dash
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Gap between parts of the same letter
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500); // Dash
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Gap between letters
  } break;
  default:
    // If the character is not supported, do nothing
    break;
  }

  delay(300);
}

void nwr_panic(const char *msg) {
  pinMode(LED_BUILTIN, OUTPUT);

  // Locks the execution in this loop.
  while (1) {
    Serial.println(msg);

    nwr_blink_morse_code('s');
    delay(100);
    nwr_blink_morse_code('o');
    delay(100);
  }
}

boolean nwr_valid_pin(pin pin) {
  if (pin < 1 || pin > 25)
    return false;

  for (int i = 0; i < MAX_PINS; i++) {
    if (nwr_used_pins[i] == pin) {
      return false;
    }
  }

  return true;
}

void nwr_use_pin(pin pin) {
  if (!nwr_valid_pin(pin))
    nwr_panic("Trying to use an already used pin!");

  for (int i = 0; i < MAX_PINS; i++) {
    if (nwr_used_pins[i] == 0)
      nwr_used_pins[i] = pin;
  }
}
