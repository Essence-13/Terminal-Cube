#ifndef MATH_H
#define MATH_H

#include <vector>
#include <string>
#include "cube.h"

class Cube_Math : public Cube{
public:
    Cube_Math(uint8_t dimension);
    void F();
    void f();
    void R();
    void r();
    void U();
    void u();
    void B();
    void b();
    void L();
    void l();
    void D();
    void d();
    void M();
    void m();
    void HM();
    void hm();
};
void rotateMatrix(std::vector<std::vector<std::string>>& Matrix);
void rotateMatrixAnticlockwise(std::vector<std::vector<std::string>>& Matrix);


#endif