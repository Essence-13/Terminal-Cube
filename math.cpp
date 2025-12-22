#include "math.h"
#include<iostream>
#include<algorithm>


Cube_Math::Cube_Math(uint8_t dimension): Cube::Cube(dimension)
{}

void rotateMatrix(std::vector<std::vector<std::string>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotateMatrixAnticlockwise(std::vector<std::vector<std::string>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0, k = n - 1; i < k; i++, k--) {
            swap(matrix[i][j], matrix[k][j]);
        }
    }
}

void Cube_Math::F(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[dimension - 1][i];
    Up[dimension - 1][i] = Left[dimension - 1-i][dimension - 1];
    Left[dimension - 1-i][dimension - 1] = Down[0][dimension - 1-i];
    Down[0][dimension - 1-i] = Right[i][0];
    Right[i][0] = temp[i];
}
rotateMatrix(Front);
display();}

void Cube_Math:: f(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[dimension - 1][i];
    Up[dimension - 1][i] = Right[i][0]; 
    Right[i][0] = Down[0][dimension - 1-i];
    Down[0][dimension - 1-i] = Left[dimension - 1-i][dimension - 1];
    Left[dimension - 1-i][dimension - 1] = temp[i];
}
rotateMatrixAnticlockwise(Front);
display();}

void Cube_Math:: R(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[i][dimension - 1];
    Up[i][dimension - 1] = Front[i][dimension - 1];
    Front[i][dimension - 1] = Down[i][dimension - 1];
    Down[i][dimension - 1] = Bottom[dimension - 1-i][0];
    Bottom[dimension - 1-i][0] = temp[i];
}
rotateMatrix(Right);
display();}

void Cube_Math:: r(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[i][dimension - 1];
    Up[i][dimension - 1] = Bottom[dimension - 1-i][0]; 
    Bottom[dimension - 1-i][0] = Down[i][dimension - 1];
    Down[i][dimension - 1] = Front[i][dimension - 1];
    Front[i][dimension - 1] = temp[i];
}
rotateMatrixAnticlockwise(Right);
display();}

void Cube_Math:: U(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Front[0][i];
    Front[0][i] = Right[0][i]; 
    Right[0][i] = Bottom[0][i];
    Bottom[0][i] = Left[0][i];
    Left[0][i] = temp[i];
}
rotateMatrix(Up);
display();}

void Cube_Math:: u(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Front[0][i];
    Front[0][i] = Left[0][i]; 
    Left[0][i] = Bottom[0][i];
    Bottom[0][i] = Right[0][i];
    Right[0][i] = temp[i];
}
rotateMatrixAnticlockwise(Up);
display();}

void Cube_Math:: B(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[0][i];
    Up[0][i] = Right[i][dimension - 1];
    Right[i][dimension - 1] = Down[dimension - 1][dimension - 1-i];
    Down[dimension - 1][dimension - 1-i] = Left[dimension - 1-i][0];
    Left[dimension - 1-i][0] = temp[i];
}
rotateMatrix(Bottom);
display();}

void Cube_Math:: b(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[0][i];
    Up[0][i] = Left[dimension - 1-i][0];
    Left[dimension - 1-i][0] = Down[dimension - 1][dimension - 1-i];
    Down[dimension - 1][dimension - 1-i] = Right[i][dimension - 1];
    Right[i][dimension - 1] = temp[i];
}
rotateMatrixAnticlockwise(Bottom);
display();}

void Cube_Math:: L(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[i][0];
    Up[i][0] = Bottom[dimension - 1-i][dimension - 1];
    Bottom[dimension - 1-i][dimension - 1] = Down[i][0];
    Down[i][0] = Front[i][0];
    Front[i][0] = temp[i];
}
rotateMatrix(Left);
display();}

void Cube_Math:: l(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Up[i][0];
    Up[i][0] = Front[i][0];
    Front[i][0] = Down[i][0];
    Down[i][0] = Bottom[dimension - 1-i][dimension - 1];
    Bottom[dimension - 1-i][dimension - 1] = temp[i];
}
rotateMatrixAnticlockwise(Left);
display();}

void Cube_Math:: D(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Front[dimension - 1][i];
    Front[dimension - 1][i] = Left[dimension - 1][i]; 
    Left[dimension - 1][i] = Bottom[dimension - 1][i];
    Bottom[dimension - 1][i] = Right[dimension - 1][i];
    Right[dimension - 1][i] = temp[i];
}
rotateMatrix(Down);
display();}

void Cube_Math:: d(){
std::vector<std::string> temp(dimension,"\033[0m ");
for(int i=0;i<dimension;i++){
    temp[i] = Front[dimension - 1][i];
    Front[dimension - 1][i] = Right[dimension - 1][i]; 
    Right[dimension - 1][i] = Bottom[dimension - 1][i];
    Bottom[dimension - 1][i] = Left[dimension - 1][i];
    Left[dimension - 1][i] = temp[i];
}
rotateMatrixAnticlockwise(Down);
display();}

void Cube_Math:: M(){
    std::vector<std::string> temp(dimension,"\033[0m ");
    std::cout<<"Enter which column(0-based) to turn: "<<std::endl;
    int col = -1; std::cin>>col;
    if(col >= dimension || col <=0){
        std::cout<<"Invalid column chosen. Try again."<<std::endl;
        return;
    }
    for(int i=0;i<dimension;i++){
        temp[i] = Front[i][col];
        Front[i][col] = Down[i][col];
        Down[i][col] = Bottom[dimension - 1-i][col];
        Bottom[dimension - 1-i][col] = Up[i][col];
        Up[i][col] = temp[i];
    }
display();}

void Cube_Math:: m(){
    std::vector<std::string> temp(dimension,"\033[0m ");
    std::cout<<"Enter which column(0-based) to turn: "<<std::endl;
    int col = -1; std::cin>>col;
    if(col >= dimension || col <=0){
        std::cout<<"Invalid column chosen. Try again."<<std::endl;
        return;
    }
    for(int i=0;i<dimension;i++){
        temp[i] = Front[i][col];
        Front[i][col] = Up[i][col];
        Up[i][col] = Bottom[dimension - 1-i][col];
        Bottom[dimension - 1-i][col] = Down[i][col];
        Down[i][col] = temp[i];
    }
display();}

void Cube_Math:: HM(){
    std::vector<std::string> temp(dimension,"\033[0m ");
    std::cout<<"Enter which row(0-based) to turn: "<<std::endl;
    int row = -1; std::cin>>row;
    if(row >= dimension || row <=0){
        std::cout<<"Invalid row chosen. Try again."<<std::endl;
        return;
    }
    for(int i=0;i<dimension;i++){
        temp[i] = Front[row][i];
        Front[row][i] = Right[row][i];
        Right[row][i] = Bottom[row][i];
        Bottom[row][i] = Left[row][i];
        Left[row][i] = temp[i];
    }
display();}

void Cube_Math:: hm(){
    std::vector<std::string> temp(dimension,"\033[0m ");
    std::cout<<"Enter which row(0-based) to turn: "<<std::endl;
    int row = -1; std::cin>>row;
    if(row >= dimension || row <=0){
        std::cout<<"Invalid row chosen. Try again."<<std::endl;
        return;
    }
    for(int i=0;i<dimension;i++){
        temp[i] = Front[row][i];
        Front[row][i] = Left[row][i];
        Left[row][i] = Bottom[row][i];
        Bottom[row][i] = Right[row][i];
        Right[row][i] = temp[i];
    }
display();}