#include<bits/stdc++.h>
#include <cstdlib> // For system()
#include <unistd.h> // for usleep

using namespace std;



class Cube{
    public:

    vector<vector<string>> Front = vector<vector<string>>(3, vector<string>(3,"\033[42m   \033[0m")); //ANSI ESCAPE COLORS USED
    vector<vector<string>> Bottom = vector<vector<string>>(3, vector<string>(3,"\033[44m   \033[0m"));
    vector<vector<string>> Up = vector<vector<string>>(3, vector<string>(3,"\033[47m   \033[0m"));
    vector<vector<string>> Down = vector<vector<string>>(3, vector<string>(3,"\033[43m   \033[0m"));
    vector<vector<string>> Right = vector<vector<string>>(3, vector<string>(3,"\033[41m   \033[0m"));
    vector<vector<string>> Left = vector<vector<string>>(3, vector<string>(3,"\033[45m   \033[0m"));
    Cube(){
    // Front[1][1] = "\033[42;30m G \033[0m";
    // Bottom[1][1] = "\033[44;30m B \033[0m";
    // Up[1][1] = "\033[47;30m W \033[0m";
    // Down[1][1] = "\033[43;30m Y \033[0m";
    // Right[1][1] = "\033[41;30m R \033[0m";
    // Left[1][1] = "\033[45;30m O \033[0m";
    }


    // Cube solved_cube(){
    //     Cube sol_c;
    //     return c;
    // }
    bool solved(){
    vector<vector<string>> F = vector<vector<string>>(3, vector<string>(3,"\033[42m   \033[0m")); //ANSI ESCAPE COLORS USED
    vector<vector<string>> B = vector<vector<string>>(3, vector<string>(3,"\033[44m   \033[0m"));
    vector<vector<string>> U = vector<vector<string>>(3, vector<string>(3,"\033[47m   \033[0m"));
    vector<vector<string>> D = vector<vector<string>>(3, vector<string>(3,"\033[43m   \033[0m"));
    vector<vector<string>> R = vector<vector<string>>(3, vector<string>(3,"\033[41m   \033[0m"));
    vector<vector<string>> L = vector<vector<string>>(3, vector<string>(3,"\033[45m   \033[0m"));
    // F[1][1] = "\033[42;30m G \033[0m";
    // B[1][1] = "\033[44;30m B \033[0m";
    // U[1][1] = "\033[47;30m W \033[0m";
    // D[1][1] = "\033[43;30m Y \033[0m";
    // R[1][1] = "\033[41;30m R \033[0m";
    // L[1][1] = "\033[45;30m O \033[0m";
    if(Front==F && Bottom == B && Up == U && Down == D && Left == L && Right == R){
        return true;
    }
    return false;
    }

string face_state(vector<vector<string>> v){
        string state = "";
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
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

string cube_state(){
    string state = "";
    state = face_state(Up) + face_state(Right)+ face_state(Front)+ face_state(Down)+ face_state(Left)+ face_state(Bottom); 
    // cout << state<<endl;
    // cout << face_state(Up).length() <<" "<<face_state(Right).length() <<" "<<face_state(Front).length() <<" "<<face_state(Down).length() <<" "<<face_state(Left).length() <<" "<<face_state(Right).length() <<endl;

    return state;

}

void solveCubeWithKociemba(const std::string& cubeState) {
    std::string command = "python -c \"import kociemba; print(kociemba.solve('" + cubeState + "'))\"";
    system(command.c_str());
}
    void display(){
    vector<vector<string>> cube(9, vector<string>(12,"\033[0m "));
    cout<<"\x1b[2J";  // ANSI code for clearing the terminal.
    cout<<"\x1b[H";  //an ANSI escape code used to reset the terminal cursor position to the top-left corner of the screen.
    for(int i=0;i<3;i++){
        for(int j=3;j<6;j++){
            cube[i][j] = Up[i][j-3];
        }
    }
    for(int i=3;i<6;i++){
        for(int j=0;j<3;j++){
            cube[i][j] = Left[i-3][j];
        }
        for(int j=3;j<6;j++){
            cube[i][j] = Front[i-3][j-3];
        }
        for(int j=6;j<9;j++){
            cube[i][j] = Right[i-3][j-6];
        }
        for(int j=9;j<12;j++){
            cube[i][j] = Bottom[i-3][j-9];
        }
    }
    for(int i=6;i<9;i++){
        for(int j=3;j<6;j++){
            cube[i][j] = Down[i-6][j-3];
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<12;j++){
            if(cube[i][j] == "\033[0m "){
                cout<< "     ";
            }
            else{
            cout<< "\033[4;30m" <<"|"<<cube[i][j]<<"|";
            }
        }
        cout << endl;
    }
    cout<<endl;
    usleep(300000000000000); // usleep is depricated.

}

void reset(){

    Front = vector<vector<string>>(3, vector<string>(3,"\033[42m   \033[0m")); //ANSI ESCAPE COLORS USED
    Bottom = vector<vector<string>>(3, vector<string>(3,"\033[44m   \033[0m"));
    Up = vector<vector<string>>(3, vector<string>(3,"\033[47m   \033[0m"));
    Down = vector<vector<string>>(3, vector<string>(3,"\033[43m   \033[0m"));
    Right = vector<vector<string>>(3, vector<string>(3,"\033[41m   \033[0m"));
    Left = vector<vector<string>>(3, vector<string>(3,"\033[45m   \033[0m"));
    display();
}
void rotateMatrix(vector<vector<string>> &matrix) {
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

void rotateMatrixAnticlockwise(vector<vector<string>>& matrix) {
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

void F(){
vector<string> temp(3,"\033[0m ");
// cout<<"F";
for(int i=0;i<3;i++){
    temp[i] = Up[2][i];
    Up[2][i] = Left[2-i][2];
    Left[2-i][2] = Down[0][2-i];
    Down[0][2-i] = Right[i][0];
    Right[i][0] = temp[i];
}
rotateMatrix(Front);
display();}
void f(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[2][i];
    Up[2][i] = Right[i][0]; 
    Right[i][0] = Down[0][2-i];
    Down[0][2-i] = Left[2-i][2];
    Left[2-i][2] = temp[i];
}
rotateMatrixAnticlockwise(Front);
display();}

void R(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[i][2];
    Up[i][2] = Front[i][2];
    Front[i][2] = Down[i][2];
    Down[i][2] = Bottom[2-i][0];
    Bottom[2-i][0] = temp[i];
}
rotateMatrix(Right);
display();}
void r(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[i][2];
    Up[i][2] = Bottom[2-i][0]; 
    Bottom[2-i][0] = Down[i][2];
    Down[i][2] = Front[i][2];
    Front[i][2] = temp[i];
}
rotateMatrixAnticlockwise(Right);
display();}

void U(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Front[0][i];
    Front[0][i] = Right[0][i]; 
    Right[0][i] = Bottom[0][i];
    Bottom[0][i] = Left[0][i];
    Left[0][i] = temp[i];
}
rotateMatrix(Up);
display();}
void u(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Front[0][i];
    Front[0][i] = Left[0][i]; 
    Left[0][i] = Bottom[0][i];
    Bottom[0][i] = Right[0][i];
    Right[0][i] = temp[i];
}
rotateMatrixAnticlockwise(Up);
display();}

void B(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[0][i];
    Up[0][i] = Right[i][2];
    Right[i][2] = Down[2][2-i];
    Down[2][2-i] = Left[2-i][0];
    Left[2-i][0] = temp[i];
}
rotateMatrix(Bottom);
display();}
void b(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[0][i];
    Up[0][i] = Left[2-i][0];
    Left[2-i][0] = Down[2][2-i];
    Down[2][2-i] = Right[i][2];
    Right[i][2] = temp[i];
}
rotateMatrixAnticlockwise(Bottom);
display();}

void L(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[i][0];
    Up[i][0] = Bottom[2-i][2];
    Bottom[2-i][2] = Down[i][0];
    Down[i][0] = Front[i][0];
    Front[i][0] = temp[i];
}
rotateMatrix(Left);
display();}
void l(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Up[i][0];
    Up[i][0] = Front[i][0];
    Front[i][0] = Down[i][0];
    Down[i][0] = Bottom[2-i][2];
    Bottom[2-i][2] = temp[i];
}
rotateMatrixAnticlockwise(Left);
display();}

void D(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Front[2][i];
    Front[2][i] = Left[2][i]; 
    Left[2][i] = Bottom[2][i];
    Bottom[2][i] = Right[2][i];
    Right[2][i] = temp[i];
}
rotateMatrix(Down);
display();}
void d(){
vector<string> temp(3,"\033[0m ");
for(int i=0;i<3;i++){
    temp[i] = Front[2][i];
    Front[2][i] = Right[2][i]; 
    Right[2][i] = Bottom[2][i];
    Bottom[2][i] = Left[2][i];
    Left[2][i] = temp[i];
}
rotateMatrixAnticlockwise(Down);
display();}

void M(){
    vector<string> temp(3,"\033[0m ");
    for(int i=0;i<3;i++){
        temp[i] = Front[i][1];
        Front[i][1] = Down[i][1];
        Down[i][1] = Bottom[2-i][1];
        Bottom[2-i][1] = Up[i][1];
        Up[i][1] = temp[i];
    }
display();}
void m(){
    vector<string> temp(3,"\033[0m ");
    for(int i=0;i<3;i++){
        temp[i] = Front[i][1];
        Front[i][1] = Up[i][1];
        Up[i][1] = Bottom[2-i][1];
        Bottom[2-i][1] = Down[i][1];
        Down[i][1] = temp[i];
    }
display();}

void HM(){
    vector<string> temp(3,"\033[0m ");
    for(int i=0;i<3;i++){
        temp[i] = Front[1][i];
        Front[1][i] = Right[1][i];
        Right[1][i] = Bottom[1][i];
        Bottom[1][i] = Left[1][i];
        Left[1][i] = temp[i];
    }
display();}
void hm(){
    vector<string> temp(3,"\033[0m ");
    for(int i=0;i<3;i++){
        temp[i] = Front[1][i];
        Front[1][i] = Left[1][i];
        Left[1][i] = Bottom[1][i];
        Bottom[1][i] = Right[1][i];
        Right[1][i] = temp[i];
    }
display();}
};

int main() {
Cube c{}; 
c.display();
// c.cube_state();
// cout<< c.cube_state().length()<<endl;
char s;

// // for(int i=1;i<=126;i++){
// //     if(i%2==0) c.l();
// //     else c.u();
// // }
// // while()
// // cout<<c.solved()<<endl;
// // c.m();
// // cout<<c.solved()<<endl;
// // c.M();
// // cout<<c.solved()<<endl;


// c.R();
// c.u();
// c.cube_state();
// cout<< c.cube_state().length()<<endl;

// c.r();
// c.u();
// int i=4;
// while(!c.solved() and i<1000){
    
//     c.R();i++; if(c.solved()) break;
//     c.u();i++; if(c.solved()) break;
//     c.r();i++;if(c.solved()) break;
//     c.u();i++;

// }
// cout << i << endl;
cout<<"Use standard keyboard keys (U-F-R-D-B-L) to manuver the cube."<<endl<<"Use smallcase (u-f-r-d-b-l) to rotate a face in anti-clockwise direction."<<endl<<"Use ! to get the solving moves."<<endl<<"Use @ to reset the cube."<<endl<<"To solve the cube you will need kociemba library. Install it using pip install kociemba"<<endl;
while(cin >> s){
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
    // else if (s == 'M') c.M();
    // else if (s == 'm') c.m();
    // else if (s == 'X')c.HM();
    // else if (s == 'x')c.hm();
    else if(s == '!'){
        cout<<"To solve the cube use following moves(using Komciemba's Algorithm.): "<<endl;
        c.solveCubeWithKociemba(c.cube_state());}
    else return 0;
}
    return 0;
}