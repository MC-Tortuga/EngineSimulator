#include "physics/kinematics.h"
#include <math.h>

double calculate_piston_height(double angle, EngineGeometry geo) {
  double r = geo.stroke / 2.0;
  double l = geo.rod_length;

  return r * cos(angle) + sqrt(pow(l, 2) - pow(r * sin(angle), 2));
}

double calculate_cylinder_volume(double angle, EngineGeometry geo,
                                 double clearance_vol) {
  double r = geo.stroke / 2.0;
  double height_max = r + geo.rod_length;
  double current_height = calculate_piston_height(angle, geo);

  double displacement =
      (height_max - current_height) * (M_PI * pow(geo.bore / 2.0, 2));
  return clearance_vol + displacement;
}
