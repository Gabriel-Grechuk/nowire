#include "math.h"
#include <stdio.h>

Vec3 multiply_vec3(Vec3 v1, Vec3 v2) {
  Vec3 vec = {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
  return vec;
}

void print_vec3(const Vec3 *v) {
  printf("(%.2f, %.2f, %.2f)\n", v->x, v->y, v->z);
}
