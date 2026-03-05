#include "core/engine.h"
#include "physics/kinematics.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  EngineGeometry coyote_geo = {
      .bore = 0.093, .stroke = 0.0927, .rod_length = 0.1507};

  Engine v8;
  v8.geo = coyote_geo;
  v8.num_cylinders = 8;
  v8.angular_velocity = 100;
  v8.throttle = 0.5;
  v8.cylinders = malloc(sizeof(Cylinder) * v8.num_cylinders);

  double offsets[8] = {0, 90, 180, 270, 360, 450, 540, 630};

  for (int i = 0; i < 8; i++) {
    v8.cylinders[i].angle = (offsets[i] * 90) * (M_PI / 180.0);
    v8.cylinders[i].pressure = 101325.0;
    v8.cylinders[i].phase = INTAKE;
  }

  double dt = 0.0001;
  double sim_time = 0;

  printf("Starting Coyote V8 Simulation...\n");
  printf("Time(s)\t\tRPM\t\tCyl1_Press(Pa)\n");

  for (int i = 0; i < 10000; i++) {
    step_engine(&v8, dt);
    sim_time += dt;

    if (i % 100 == 0) {
      printf("%.3f\t\t%.0f\t\t%.2f\n", sim_time, v8.rpm,
             v8.cylinders[0].pressure);
    }
  }

  free(v8.cylinders);
  return 0;
}
