#include "raylib.h"
#include "math.h"
#include <iostream>
#include <string>
#include <cmath>

// --- HELPER FUNCTIONS ---

Color GetColorFromCode(std::string code) {
    if (code.find("47m") != std::string::npos) return WHITE;
    if (code.find("42m") != std::string::npos) return GREEN;
    if (code.find("44m") != std::string::npos) return BLUE;
    if (code.find("43m") != std::string::npos) return YELLOW;
    if (code.find("41m") != std::string::npos) return RED;
    if (code.find("45m") != std::string::npos) return ORANGE;
    return BLACK; 
}

// Relative Move Logic (The "Quadrant System")
void PerformRelativeMove(Cube_Math* cube, char move, int quadrant, bool prime) {
    if (cube == nullptr) return;
    char baseMoves[4] = {'F', 'R', 'B', 'L'};
    int moveIndex = -1;
    if (move == 'F') moveIndex = 0;
    else if (move == 'R') moveIndex = 1;
    else if (move == 'B') moveIndex = 2;
    else if (move == 'L') moveIndex = 3;
    
    if (moveIndex != -1) {
        int actualIndex = (moveIndex + quadrant) % 4;
        move = baseMoves[actualIndex];
    }

    if (move == 'F') prime ? cube->f() : cube->F();
    else if (move == 'R') prime ? cube->r() : cube->R();
    else if (move == 'B') prime ? cube->b() : cube->B();
    else if (move == 'L') prime ? cube->l() : cube->L();
    else if (move == 'U') prime ? cube->u() : cube->U();
    else if (move == 'D') prime ? cube->d() : cube->D();
}

// --- MAIN APPLICATION ---

int main() {
    InitWindow(1000, 800, "Rubik's Cube Master");
    SetTargetFPS(60);

    // Application States
    enum AppState { MENU, CUBE };
    AppState currentState = MENU;

    // Cube Logic Pointer (Created dynamically after user chooses size)
    Cube_Math* myCube = nullptr;
    int cubeDim = 3; // Default

    // Camera Variables
    Camera3D camera = { 0 };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    
    float cameraAngleH = 1.0f;
    float cameraAngleV = 0.5f;
    float cameraDist = 10.0f;

    while (!WindowShouldClose()) {
        
        // --- UPDATE LOGIC ---
        
        if (currentState == MENU) {
            // Check keys 2-9 for quick selection
            int key = GetKeyPressed();
            if (key >= KEY_TWO && key <= KEY_NINE) {
                cubeDim = key - KEY_ZERO;
                // Initialize the cube and switch state
                myCube = new Cube_Math(cubeDim);
                cameraDist = cubeDim * 2.5f; 
                currentState = CUBE;
            }
        }
        else if (currentState == CUBE) {
            // 1. Camera Controls
            if (IsKeyDown(KEY_LEFT)) cameraAngleH -= 0.05f;
            if (IsKeyDown(KEY_RIGHT)) cameraAngleH += 0.05f;
            if (IsKeyDown(KEY_UP)) cameraAngleV += 0.05f;
            if (IsKeyDown(KEY_DOWN)) cameraAngleV -= 0.05f;
            
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                Vector2 delta = GetMouseDelta();
                cameraAngleH += delta.x * 0.01f;
                cameraAngleV += delta.y * 0.01f;
            }
            
            cameraDist -= GetMouseWheelMove() * 2.0f;
            if (cameraDist < 2.0f) cameraDist = 2.0f;

            // Clamp vertical angle
            if (cameraAngleV > 1.5f) cameraAngleV = 1.5f;
            if (cameraAngleV < -1.5f) cameraAngleV = -1.5f;

            // Calculate Position
            float hDist = cameraDist * cos(cameraAngleV);
            camera.position.y = cameraDist * sin(cameraAngleV);
            camera.position.x = hDist * sin(cameraAngleH);
            camera.position.z = hDist * cos(cameraAngleH);
            camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

            // 2. Cube Move Inputs
            // Calculate Quadrant
            float angle = cameraAngleH;
            while (angle < 0) angle += 2 * PI;
            while (angle >= 2 * PI) angle -= 2 * PI;
            int quadrant = (int)((angle + PI / 4.0f) / (PI / 2.0f)) % 4;

            bool shift = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);

            if (IsKeyPressed(KEY_F)) PerformRelativeMove(myCube, 'F', quadrant, shift);
            if (IsKeyPressed(KEY_B)) PerformRelativeMove(myCube, 'B', quadrant, shift);
            if (IsKeyPressed(KEY_L)) PerformRelativeMove(myCube, 'L', quadrant, shift);
            if (IsKeyPressed(KEY_R)) PerformRelativeMove(myCube, 'R', quadrant, shift);
            if (IsKeyPressed(KEY_U)) PerformRelativeMove(myCube, 'U', quadrant, shift);
            if (IsKeyPressed(KEY_D)) PerformRelativeMove(myCube, 'D', quadrant, shift);
            
            // Go back to menu
            if (IsKeyPressed(KEY_BACKSPACE)) {
                delete myCube;
                myCube = nullptr;
                currentState = MENU;
            }
        }

        // --- DRAWING ---
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentState == MENU) {
            DrawText("RUBIK'S CUBE MASTER", 220, 200, 50, DARKBLUE);
            DrawText("Press a Number Key (2 - 9)", 300, 350, 30, DARKGRAY);
            DrawText("to select Cube Dimension", 320, 390, 30, DARKGRAY);
            
            // Draw visual examples
            DrawRectangleLines(300, 500, 60, 60, BLACK); DrawText("2", 320, 515, 30, BLACK);
            DrawRectangleLines(400, 500, 60, 60, BLACK); DrawText("3", 420, 515, 30, BLACK);
            DrawRectangleLines(500, 500, 60, 60, BLACK); DrawText("4", 520, 515, 30, BLACK);
        }
        else if (currentState == CUBE && myCube != nullptr) {
            BeginMode3D(camera);
            
            int n = cubeDim;
            float spacing = 1.05f;
            float offset = (n - 1) / 2.0f;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int z = 0; z < n; z++) {
                        float wx = (x - offset) * spacing;
                        float wy = (y - offset) * spacing;
                        float wz = (z - offset) * spacing;
                        Vector3 pos = { wx, wy, wz };

                        DrawCube(pos, 1.0f, 1.0f, 1.0f, BLACK);
                        DrawCubeWires(pos, 1.0f, 1.0f, 1.0f, DARKGRAY);

                        float sSize = 0.9f;
                        float sOff = 0.51f;

                        // Sticker Drawing Logic
                        if (x == n - 1) { // Right
                            Color c = GetColorFromCode(myCube->getColorCode("R", (n-1)-y, (n-1)-z));
                            DrawCube((Vector3){wx+sOff, wy, wz}, 0.05f, sSize, sSize, c);
                        }
                        if (x == 0) { // Left
                            Color c = GetColorFromCode(myCube->getColorCode("L", (n-1)-y, z));
                            DrawCube((Vector3){wx-sOff, wy, wz}, 0.05f, sSize, sSize, c);
                        }
                        if (y == n - 1) { // Up
                            Color c = GetColorFromCode(myCube->getColorCode("U", z, x));
                            DrawCube((Vector3){wx, wy+sOff, wz}, sSize, 0.05f, sSize, c);
                        }
                        if (y == 0) { // Down
                            Color c = GetColorFromCode(myCube->getColorCode("D", (n-1)-z, x));
                            DrawCube((Vector3){wx, wy-sOff, wz}, sSize, 0.05f, sSize, c);
                        }
                        if (z == n - 1) { // Front
                            Color c = GetColorFromCode(myCube->getColorCode("F", (n-1)-y, x));
                            DrawCube((Vector3){wx, wy, wz+sOff}, sSize, sSize, 0.05f, c);
                        }
                        if (z == 0) { // Back
                            Color c = GetColorFromCode(myCube->getColorCode("B", (n-1)-y, (n-1)-x));
                            DrawCube((Vector3){wx, wy, wz-sOff}, sSize, sSize, 0.05f, c);
                        }
                    }
                }
            }
            EndMode3D();

            DrawText("Controls: U D L R F B (Shift for inverse)", 10, 10, 20, DARKGRAY);
            DrawText("Backspace: Menu", 10, 40, 20, DARKGRAY);
        }

        EndDrawing();
    }

    if(myCube) delete myCube;
    CloseWindow();
    return 0;
}