#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "math.h"

typedef struct {
  Vec3 position;
  Vec3 velocity;
  Vec3 acceleration;
} Object;

void simulate_moviment(Object *obj, double time);

#endif
