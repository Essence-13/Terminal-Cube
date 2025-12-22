#  Rubik’s Cube Terminal Visualizer & Solver

An interactive terminal-based Rubik’s Cube simulator and solver written in **C++**, featuring real-time cube rotation, ANSI color rendering, and integration with **Kociemba's algorithm** for solving.

---

## Features

-  **Keyboard-Controlled Cube Manipulation**\
  Rotate any face (clockwise or anticlockwise) using single-key inputs (`U`, `D`, `F`, `B`, `L`, `R`, or lowercase for reverse).

-  **ANSI Color-Coded Display**\
  Visual cube rendered in your terminal with true Rubik’s Cube colors.

-  **Solver Integration**\
  Uses Python’s `kociemba` module to calculate and print the optimal solving sequence from any cube state.

-  **Live Display Refresh**\
  Terminal automatically updates on each move with a clean animation-like effect.

---

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/Essence-13/Terminal-Cube.git
```

### 2. Install the Kociemba solver (Python)

```bash
pip install kociemba
```

### 3. Compile the C++ code

```bash
g++ Cube.cpp -o cube
```

### 4. Run it!

```bash
./cube
```

---

## 🎮 Controls

| Key             | Action                            |
| --------------- | --------------------------------- |
| `F`             | Rotate Front face clockwise       |
| `f`             | Rotate Front face anti-clockwise  |
| `U`             | Rotate Up face clockwise          |
| `u`             | Rotate Up face anti-clockwise     |
| `R`             | Rotate Right face clockwise       |
| `r`             | Rotate Right face anti-clockwise  |
| `D`             | Rotate Down face clockwise        |
| `d`             | Rotate Down face anti-clockwise   |
| `L`             | Rotate Left face clockwise        |
| `l`             | Rotate Left face anti-clockwise   |
| `B`             | Rotate Back face clockwise        |
| `b`             | Rotate Back face anti-clockwise   |
| `@`             | Reset cube to solved state        |
| `!`             | Solve current cube (via Kociemba) |
| *Any other key* | Exit                              |

---

##  How It Works

- Cube faces are rendered using 2D vectors of ANSI-colored strings.
- Rotations update face data and re-render the cube.
- Kociemba solving is done via a Python call with serialized cube state.
- Supports clean user interaction with real-time updates.

---

##  Requirements

- C++ Compiler (e.g., g++)
- Python 3
- `kociemba` Python package

---

## Snapshots

https://github.com/user-attachments/assets/e7c92a91-6881-48c4-9f0a-7ba183d07d37

##  License

This project is open-source under the MIT License.

---

