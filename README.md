# SNOW Physics Engine

SNOW is a custom-built physics engine created using C++ and SDL3, with a focus on an environment to study dynamical systems. It leverages OpenGL for accelerated processing on small scaled simulations. The engine is designed for flexibility and aims to provide an interactive environment for physics simulations.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Building the Project](#building-the-project)
- [Usage](#usage)
  - [Running the Engine](#running-the-engine)
  - [Configuration](#configuration)
  - [Controls](#controls)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [Roadmap](#roadmap)
- [License](#license)
- [Contact](#contact)

---
[![CMake on multiple platforms](https://github.com/Lucaskc36/SNOW/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/Lucaskc36/SNOW/actions/workflows/cmake-multi-platform.yml)
---
## Features


- **Custom Physics Engine**: Supports classical mechanics, differential equations, and linear algebra.
- **Perspective Camera**: The rendering uses an orthogonal camera for the particle system.
- **Object-Oriented Design**: Designed with extendable classes for objects, cameras, and UI components.
- **UI with ImGui**: Interactive UI for debugging and visualizing simulation data.
- **Shaders**: Integrates basic shaders for lighting and rendering (simple shaders with plans for refactoring).
- **Simulation Interactions**: Tether objects and observe dynamic interactions.

## Getting Started

### Prerequisites

To build and run SNOW, ensure you have the following installed:

- C++ Compiler (GCC/Clang)
- CMake (version 3.15 or higher)
- Gl3w
  - Requires Python 3(I don't make the rules)
- OpenGL development libraries:
  - On Linux, run: `sudo apt-get install libgl1-mesa-dev`
- Git

The necessary external libraries (SDL3 and ImGui) will be automatically fetched through submodules.

### Installation

1. Clone the repository:
   ```bash
   git clone git@github.com:Lucaskc36/SNOW.git
   ```
2. Update Submodules (for external libraries):
   ```bash
   git submodule update --init --recursive
   ```
3. Move to the project directory:
   ```bash
   cd SNOW
   ```
4. Run Gl3W loader
   ```bash
   cd external/gl3w
   python3 gl3w_gen.py
   cd ../../
   ```   
5. Create a `build` directory:
   ```bash
   mkdir build
   cd build
   ```
6. Build using `cmake`:
   ```bash
   cmake ..
   make
   ```
7. Run the program:
   ```bash
   ./PhysicsEngine
   ```

## Usage

### Running the Engine

- After building, run the `PhysicsEngine` executable to start the engine.
- The simulation starts with a simple particle system rendered on the screen.

### Configuration

- Modify any configuration files to adjust parameters for custom simulations.

## Project Structure

```
SNOW/
├── build/              # Build directory for compiled files
├── include/            # Header files
├── src/                # Source files
├── external/           # External libraries like SDL3 and ImGui
├── shaders/            # GLSL shader files
├── CMakeLists.txt      # CMake configuration
├── README.md           # Project documentation
└── LICENSE             # License file
```

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/YourFeature
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your feature"
   ```
4. Push to your branch:
   ```bash
   git push origin feature/YourFeature
   ```
5. Open a pull request.

## Roadmap

- [ ] Default Collision Detection
- [ ] Adjustable time-scales
- [ ] Imgui parameterized queue and stack for run-time debugging and 
- [ ] Integration with other libraries (e.g., Bullet for advanced physics).

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## Contact

For questions or feedback, reach out to [lucaskc36@gmail.com](mailto:lucaskc36@gmail.com).
```

Feel free to adjust this as needed! It includes detailed steps for setup, usage, and contributions, tailored for a project using Doxygen for documentation.
