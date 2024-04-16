# Rocket Physics Simulator

## Project Overview
The Rocket Physics Simulator is a C++ project designed to model and simulate the flight dynamics of rockets. This simulator encompasses the physics of mass, lift, drag, thrust, and mass moment of inertia (MMI), providing a framework for exploring rocket behavior under various conditions.

The project currently includes basic physics modeling with implementations up to the Rocket class. The Environment handling, PhysicsEngine, and Controller for trajectory management are planned for future development.

## Current Implementation
As of now, the project includes the following classes and functionalities:

### Vector3D
- **Purpose**: Handles three-dimensional vector operations.
- **Features**:
  - Vector addition, subtraction, scalar multiplication
  - Dot and cross products
  - Magnitude calculation, normalization

### PhysicalObject
- **Purpose**: Serves as an abstract base class for all physical objects in the simulation.
- **Features**:
  - Basic attributes like position, velocity, acceleration, and mass
  - Virtual methods for physics updates (e.g., `updatePosition`)

### Rocket
- **Inherits**: PhysicalObject
- **Purpose**: Models a rocket with capabilities to compute its own thrust, drag, and other dynamics.
- **Features**:
  - Attributes for thrust, drag coefficient, cross-sectional area, fuel mass, and dry mass
  - Methods for calculating thrust and drag
  - Fuel mass updates during flight
  - Computation of net forces acting on the rocket

## Planned Features
The following components are yet to be implemented:

### Environment
- **Purpose**: To model environmental conditions affecting rocket flight.
- **Planned Features**:
  - Modeling of gravity as a vector
  - Calculation of air density based on altitude

### PhysicsEngine
- **Purpose**: To manage the simulation loop, applying physics laws to the rocket and updating its state over time.
- **Planned Features**:
  - Simulation of time steps
  - Interaction management between physical objects and the environment

### Controller
- **Purpose**: To implement control algorithms to adjust the rocket’s thrust and orientation to follow a desired trajectory.
- **Planned Features**:
  - PID control strategy or similar algorithms
  - Real-time adjustment of rocket parameters based on trajectory analysis

## Getting Started

Thus far only the Vector3D, Physicalobject and the Rocket classes have been implemented.
This section provides instructions on how to compile and run unit tests for the rocket control physics engine.

### Prerequisites

Before you begin, make sure you have the following installed on your system:
- C++ compiler (e.g., g++, clang)
- Make (for running Makefiles)
- Google's Google Test library for C++ code

### Cloning the Repository

First, clone the repository from GitHub to your local machine:

```bash
git clone https://github.com/adityaanilshukla/Rocket-Physics-Simulator.git
cd Rocket-Physics-Simulator
```

### Compiling the Tests

To compile the unit tests for the project, follow these steps:

1. Navigate to the test directory where the Makefile and `unit_test.cpp` are located:
   
   ```
   cd test
   ```

2. Run the Makefile to create the executable for the unit tests:
   
   ```
   make
   ```

This will compile the `unit_test.cpp` file along with any necessary dependencies, producing an executable file unit_test.

### Running the Tests

After compiling the tests, run the executable to see the test results:

```
./unit_test
```

This command will execute the compiled tests, and you should see the output indicating whether the tests passed or failed.

### Clean Up

To clean up the binaries and any other files generated during the build process, use:

```
make clean
```

This command will remove the generated executable and any intermediate files used during compilation, as defined in the `clean` target of your Makefile.
