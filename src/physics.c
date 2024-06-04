#include "physics.h"
#include "consts.h"
#include <stdio.h>

// Simple Euler method to calculate the velocity and acceleration.
void simulate_moviment(Object *obj, double time) {
  obj->velocity.x += obj->acceleration.x * time;
  obj->velocity.y += obj->acceleration.y * time;
  obj->velocity.z += obj->acceleration.z * time;

  obj->position.x += obj->velocity.x * time;
  obj->position.y += obj->velocity.y * time;
  obj->position.z += obj->velocity.z * time;
}
