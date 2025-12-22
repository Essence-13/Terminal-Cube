#include<iostream>
#include "cube.h"
#include "math.h"
#include <stdint.h>

void solveCubeWithKociemba(const std::string& cubeState) {
    std::string command = "python -c \"import kociemba; print(kociemba.solve('" + cubeState + "'))\"";
    system(command.c_str());
}

int main() {
std::cout<<"Please Enter the dimension of the cube you want to visualize: "<<std::endl;
std::cout<<"Please Note currently you only be able to get the solving sequence of a 3x3 cube."<<std::endl;
int dim; std::cin>>dim;
uint8_t dimension = static_cast<uint8_t>(dim);
Cube_Math c(dimension); 
c.display();

char s;


std::cout<<"Use standard keyboard keys (U-F-R-D-B-L) to manuver the cube."
<<std::endl<<"Use smallcase (u-f-r-d-b-l) to rotate a face in anti-clockwise direction."
<<std::endl<<"Use ! to get the solving moves."
<<std::endl<<"Use @ to reset the cube."
<<std::endl<<"To solve the cube you will need kociemba library. Install it using pip install kociemba"
<<std::endl;
while(std::cin >> s){
    if (s == 'F') c.F();
    else if (s == 'f') c.f();
    else if (s == 'U') c.U();
    else if (s == 'u') c.u();
    else if (s == 'R') c.R();
    else if (s == 'r') c.r();
    else if (s == 'D') c.D();
    else if (s == 'd') c.d();
    else if (s == 'L') c.L();
    else if (s == 'l') c.l();
    else if (s == 'B') c.B();
    else if (s == 'b') c.b();
    else if (s == '@') c.reset();
    else if (s == 'M') c.M();
    else if (s == 'm') c.m();
    else if (s == 'X')c.HM();
    else if (s == 'x')c.hm();
    else if(s == '!'){
        if(dim!=3){
            std::cout<<"Currently cannot solve a "<<dim<<"x"<<dim<<" cube"<<std::endl;
            continue;
        }
        std::cout<<"To solve the cube(3x3) use following moves(using Komciemba's Algorithm.): "<<std::endl;
        solveCubeWithKociemba(c.cube_state());
    }
    else return 0;
}
    return 0;
}