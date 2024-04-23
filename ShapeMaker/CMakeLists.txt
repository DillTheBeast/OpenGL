cmake_minimum_required(VERSION 3.10)
project(ShapeMaker)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Add the executable target
add_executable(main
    Main.cpp
    ../src/glad.c
    EBO.cpp
    VAO.cpp
    VBO.cpp
    shaderClass.cpp
    include/imgui/imgui.cpp
    include/imgui/imgui_demo.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/backends/imgui_impl_opengl3.cpp
    include/imgui/backends/imgui_impl_glfw.cpp
)

# Add include directories
target_include_directories(main PRIVATE
    include
    include/glm
    include/imgui
    include/imgui/backends
)

# Link GLFW library
target_link_libraries(main PRIVATE
    glfw
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
