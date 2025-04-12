# Terminal-Cube
An interactive Rubik’s Cube simulator in C++ with a real-time terminal UI using ANSI escape sequences to represent cube faces and rotations.


## 🚀 How to Run

### 1. Clone the repository
git clone https://github.com/yourusername/rubiks-cube-visualizer.git
cd rubiks-cube-visualizer


###2. Install the Kociemba solver (Python)
pip install kociemba


###3. Compile the C++ code
g++ color_cube_optimized_solver.cpp -o cube


###4. Run it!
./cube



 ###Controls
###Key	###Action
F	Rotate Front face clockwise
f	Rotate Front face anti-clockwise
U	Rotate Up face clockwise
u	Rotate Up face anti-clockwise
R	Rotate Right face clockwise
r	Rotate Right face anti-clockwise
D	Rotate Down face clockwise
d	Rotate Down face anti-clockwise
L	Rotate Left face clockwise
l	Rotate Left face anti-clockwise
B	Rotate Back face clockwise
b	Rotate Back face anti-clockwise
@	Reset cube to solved state
!	Solve current cube (via Kociemba)
Any other key	Exit
