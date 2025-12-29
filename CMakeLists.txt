cmake_minimum_required(VERSION 3.10)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 17)

# 1. Fetch Raylib automatically
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

# 2. Define your executable
add_executable(cube3d main.cpp math.cpp cube.cpp)

# 3. Link Raylib
target_link_libraries(cube3d PRIVATE raylib)