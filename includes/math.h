#ifndef _MATH_H_
#define _MATH_H_

typedef struct {
  double x;
  double y;
  double z;
} Vec3;

Vec3 multiply_vec3(Vec3 v1, Vec3 v2);

void print_vec3(const Vec3 *v);

#endif
