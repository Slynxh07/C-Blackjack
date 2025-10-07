# Blackjack

A simple C++ card game built with CMake.

# Build Instructions

```bash
# Clone the repository
git clone https://github.com/<your-username>/CardGame.git
cd CardGame

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .
```
# Project Structure

CardGame/

├── include/          # Header files (.h)

├── src/              # Source files (.cpp)

├── CMakeLists.txt    # CMake build config

├── .gitignore

└── README.md

```bash
# After building, the executable will be inside the build/ folder:
./CardGame
```

# Requirements

CMake ≥ 3.10
C++17 compatible compiler (GCC, Clang, or MSVC)