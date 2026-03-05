# EngineSimulator

A C-based internal combustion engine simulator that models a 4-stroke V8 engine using real physics calculations.

## Features

- **4-Stroke Cycle Simulation**: Models intake, compression, power, and exhaust strokes
- **Kinematics**: Calculates piston position and cylinder volume based on crank angle and connecting rod geometry
- **Thermodynamics**: Implements adiabatic compression/expansion for pressure calculations
- **V8 Configuration**: Simulates an 8-cylinder V8 engine with proper firing order offsets

## Building

```bash
make
```

## Running

```bash
./bin/engine_sim
```

## Project Structure

```
EngineSimulator/
├── include/
│   ├── core/engine.h       # Engine struct and step function
│   └── physics/
│       ├── kinematics.h    # Piston motion calculations
│       └── thermo.h       # Thermodynamic calculations
├── src/
│   ├── main.c              # Entry point (simulates Coyote V8)
│   ├── core/engine.c       # Engine simulation logic
│   └── physics/
│       ├── kinematics.c    # Piston position/volume math
│       └── thermo.c        # Adiabatic pressure calculations
└── Makefile                # Build configuration
```

## Key Components

- **Engine**: Contains RPM, angular velocity, throttle position, cylinders
- **Cylinder**: Tracks angle, pressure, temperature, and current stroke phase
- **EngineGeometry**: Defines bore, stroke, and connecting rod length

## Example Output

The simulator outputs time, RPM, and cylinder pressure values during simulation.
