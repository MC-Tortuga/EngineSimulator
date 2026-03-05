#include "core/engine.h"
#include "physics/kinematics.h"
#include "physics/thermo.h"
#include <math.h>
void step_engine(Engine *e, double dt) {
  double total_torque = 0.0;
  double piston_area = M_PI * pow(e->geo.bore / 2.0, 2);
  double displacement_vol = piston_area * e->geo.stroke;
  double clearance_vol = displacement_vol / (12.0 - 1.0);

  for (int i = 0; i < e->num_cylinders; i++) {
    Cylinder *c = &e->cylinders[i];

    double v_old = calculate_cylinder_volume(c->angle, e->geo, clearance_vol);

    c->angle += e->angular_velocity * dt;
    double cycle_angle = fmod(c->angle, 4.0 * M_PI);

    if (cycle_angle < M_PI)
      c->phase = INTAKE;
    else if (cycle_angle < 2.0 * M_PI)
      c->phase = COMPRESSION;
    else if (cycle_angle < 3.0 * M_PI)
      c->phase = POWER;
    else
      c->phase = EXHAUST;

    double v_new = calculate_cylinder_volume(c->angle, e->geo, clearance_vol);

    if (c->phase == INTAKE || c->phase == EXHAUST) {
      c->pressure = 101325.0;
    } else {

      c->pressure = calculate_adiabatic_pressure(c->pressure, v_old, v_new);

      if (c->phase == COMPRESSION && cycle_angle > (2.0 * M_PI - 0.02)) {
        c->pressure += 4000000.0 * e->throttle;
      }
    }

    double force = (c->pressure - 101325.0) * piston_area;
    double crank_radius = e->geo.stroke / 2.0;
    total_torque += force * crank_radius * sin(c->angle);
  }

  double inertia = 0.15; // Placeholder
  double friction = e->angular_velocity * 0.02;
  double alpha = (total_torque - friction) / inertia;

  e->angular_velocity += alpha * dt;
  if (e->angular_velocity < 0)
    e->angular_velocity = 0;

  e->rpm = (e->angular_velocity * 60.0) / (2.0 * M_PI);
}
