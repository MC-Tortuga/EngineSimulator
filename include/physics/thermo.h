#ifndef THERMO_H
#define THERMO_H

#define AIR_GAMMA 1.4

double calculate_adiabatic_pressure(double P_initial, double V_initial,
                                    double V_final);
#endif // !THERMO_H
