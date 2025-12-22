#include "cube.h"
#include <iostream>
#include <unistd.h>

Cube::Cube(uint8_t dimension){
    this->dimension = dimension;
    Front = std::vector<std::vector<std::string>>(dimension, std::vector<std::string>(dimension,"\033[42m   \033[0m"));
    Bottom = std::vector<std::vector<std::string>>(dimension, std::vector<std::string>(dimension,"\033[44m   \033[0m"));
    Up = std::vector<std::vector<std::string>>(dimension, std::vector<std::string>(dimension,"\033[47m   \033[0m"));
    Down = std::vector<std::vector<std::string>>(dimension, std::vector<std::string>(dimension,"\033[43m   \033[0m"));
    Right = std::vector<std::vector<std::string>>(dimension, std::vector<std::string>(dimension,"\033[41m   \033[0m"));
    Left = std::vector<std::vector<std::string>>(dimension, std::vector<std::string>(dimension,"\033[45m   \033[0m"));
    }

bool Cube:: solved(){
    std::vector<std::vector<std::string>> B = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[44m   \033[0m"));
    std::vector<std::vector<std::string>> F = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[42m   \033[0m")); //ANSI ESCAPE COLORS USED
    std::vector<std::vector<std::string>> U = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[47m   \033[0m"));
    std::vector<std::vector<std::string>> D = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[43m   \033[0m"));
    std::vector<std::vector<std::string>> R = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[41m   \033[0m"));
    std::vector<std::vector<std::string>> L = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[45m   \033[0m"));

    if(Front==F && Bottom == B && Up == U && Down == D && Left == L && Right == R){
        return true;
    }
    return false;
    }

std::string Cube:: face_state(std::vector<std::vector<std::string>> v){
      std::string state = "";
        for(int i=0;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                if(v[i][j]=="\033[47m   \033[0m"){
                    state+="U";
                }
                else if(v[i][j]=="\033[42m   \033[0m"){
                    state+="F";
                }
                else if(v[i][j]=="\033[44m   \033[0m"){
                    state+="B";
                }
                else if(v[i][j]=="\033[43m   \033[0m"){
                    state+="D";
                }
                else if(v[i][j]=="\033[41m   \033[0m"){
                    state+="R";
                }else if(v[i][j]=="\033[45m   \033[0m"){
                    state+="L";
                }
            }
        }
        return state;
}

std::string Cube:: cube_state(){
    std::string state = "";
    state = face_state(Up) + face_state(Right)+ face_state(Front)+ face_state(Down)+ face_state(Left)+ face_state(Bottom); 

    return state;

}

void Cube:: display(){
        int l = dimension * 3;
        int w = dimension * 4;
    std::vector<std::vector<std::string>> cube(l, std::vector<std::string>(w,"\033[0m "));
    std::cout<<"\x1b[2J";  // ANSI code for clearing the terminal.
    std::cout<<"\x1b[H";  //an ANSI escape code used to reset the terminal cursor position to the top-left corner of the screen.
    // cout << "\x1b[2J\x1b[H"; // Clear screen and reset cursor
    for(int i=0;i<dimension;i++){
        for(int j=dimension;j<2*dimension;j++){
            cube[i][j] = Up[i][j-dimension];
        }
    }
    for(int i=dimension;i<2*dimension;i++){
        for(int j=0;j<dimension;j++){
            cube[i][j] = Left[i-dimension][j];
        }
        for(int j=dimension;j<2*dimension;j++){
            cube[i][j] = Front[i-dimension][j-dimension];
        }
        for(int j=2*dimension;j<3*dimension;j++){
            cube[i][j] = Right[i-dimension][j-2*dimension];
        }
        for(int j=3*dimension;j<4*dimension;j++){
            cube[i][j] = Bottom[i-dimension][j-3*dimension];
        }
    }
    for(int i=2*dimension;i<3*dimension;i++){
        for(int j=dimension;j<2*dimension;j++){
            cube[i][j] = Down[i-2*dimension][j-dimension];
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            if(cube[i][j] == "\033[0m "){
                std::cout<< "     ";
            }
            else{
            std::cout<< "\033[4;30m" <<"|"<<cube[i][j]<<"|";
            }
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
    usleep(50000);

}

void Cube:: reset(){

    Front = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[42m   \033[0m")); //ANSI ESCAPE COLORS USED
    Bottom = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[44m   \033[0m"));
    Up = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[47m   \033[0m"));
    Down = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[43m   \033[0m"));
    Right = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[41m   \033[0m"));
    Left = std::vector<std::vector<std::string>> (dimension, std::vector<std::string>(dimension,"\033[45m   \033[0m"));
    display();
}