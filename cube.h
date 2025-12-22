#ifndef CUBE_H  
#define CUBE_H

#include <vector>
#include <string>
#include <cstdint>
class Cube{
    public:
    Cube(uint8_t dimension);
    void display();
    bool solved();
    std::string face_state(std::vector<std::vector<std::string>> v);
    std::string cube_state();
    void reset();
    protected:
    uint8_t dimension;
    std::vector<std::vector<std::string>> Front, Bottom, Up, Down, Right, Left;
};



#endif