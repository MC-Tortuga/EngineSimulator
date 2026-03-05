#ifndef KINEMATICS_H
#define KINEMATICS_H

typedef struct {
  double stroke;
  double rod_length;
  double bore;
} EngineGeometry;

double calculate_piston_height(double angle, EngineGeometry geo);
double calculate_cylinder_volume(double angle, EngineGeometry geo,
                                 double clearance_vol);
#endif // !KINEMATICS_H
