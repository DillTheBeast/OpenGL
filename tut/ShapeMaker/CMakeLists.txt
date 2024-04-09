cmake_minimum_required(VERSION 3.12)
project(OpenGLProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    /Users/dillonmaltese/Documents/GitHub/OpenGL/include
    /Users/dillonmaltese/Documents/GitHub/OpenGL/include/glm
)

# Add source files
add_executable(main
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/Main.cpp
    /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/EBO.cpp
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/VAO.cpp
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/VBO.cpp
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/shaderClass.cpp
)

# Link GLFW library
find_package(glfw3 REQUIRED)
target_link_libraries(main glfw)

# Link OpenGL frameworks
target_link_libraries(main
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
