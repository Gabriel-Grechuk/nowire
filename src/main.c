#include "consts.h"
#include "physics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  Object box = {
      {0.0, 10.0, 0.0},    // Position.
      {0.0, 0.0, 0.0},     // Velocity.
      {0.0, GRAVITY, 0.0}, // Acceletarion.
  };

  Object box2 = {
      {0.0, 10.0, 0.0},    // Position.
      {0.0, 0.0, 0.0},     // Velocity.
      {0.0, GRAVITY, 0.0}, // Acceletarion.
  };

  double seconds = 0.3;
  double start = (double)clock() / CLOCKS_PER_SEC;
  double elapsed_time = 0.0;
  double timeStep = 0.001;

  while (elapsed_time <= seconds) {
    double iterationStartTime = (double)clock() / CLOCKS_PER_SEC;

    simulate_moviment(&box, timeStep);
    double iterationElapsedTime =
        ((double)clock() / CLOCKS_PER_SEC) - iterationStartTime;

    /*printf("%f\n", elapsed_time);*/
    if (iterationElapsedTime < timeStep) {
      double remainingTime = timeStep - iterationElapsedTime;
      usleep(remainingTime * 1000000); // Sleep in microseconds
    }

    elapsed_time = ((double)clock() / CLOCKS_PER_SEC) - start;
  }

  printf("Position: ");
  print_vec3(&box.position);

  printf("Velocity: ");
  print_vec3(&box.velocity);

  printf("Acceletarion: ");
  print_vec3(&box.acceleration);

  printf("------------------------\n");

  simulate_moviment(&box2, 3.0);
  printf("Position: ");
  print_vec3(&box2.position);

  printf("Velocity: ");
  print_vec3(&box2.velocity);

  printf("Acceletarion: ");
  print_vec3(&box2.acceleration);

  printf("%f\n", elapsed_time);
  return 0;
}
