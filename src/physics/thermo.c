#include "physics/thermo.h"
#include <math.h>
double calculate_adiabatic_pressure(double P_initial, double V_initial,
                                    double V_final) {
  if (V_final <= 0)
    return P_initial;

  return P_initial * pow((V_initial / V_final), AIR_GAMMA);
}
