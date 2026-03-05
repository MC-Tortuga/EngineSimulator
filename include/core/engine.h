#ifndef ENGINE_H
#define ENGINE_H

#include "physics/kinematics.h"
typedef enum { INTAKE, COMPRESSION, POWER, EXHAUST } StrokePhase;

typedef struct {
  double angle;
  double pressure;
  double temperature;
  StrokePhase phase;
} Cylinder;

typedef struct {
  double rpm;
  double angular_velocity;
  double throttle;
  EngineGeometry geo;
  Cylinder *cylinders;
  int num_cylinders;
} Engine;

void step_engine(Engine *e, double dt);
#endif // !ENGINE_H
