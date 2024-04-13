cmake_minimum_required(VERSION 3.10)
project(OpenGLDemo)

set(CMAKE_CXX_STANDARD 17)

# Add your source files
set(SOURCE_FILES
    Main.cpp
    ../src/glad.c  # Adjust the path to glad.c relative to your CMakeLists.txt file
    EBO.cpp
    VAO.cpp
    VBO.cpp
    shaderClass.cpp
    ../include/imgui/imgui.cpp
)


# Include directories
include_directories(
    ../include
    ../include/glm
    ../include/imgui
)

# Add executable
add_executable(main ${SOURCE_FILES})

# Link directories
target_link_directories(main PRIVATE /Users/dillonmaltese/Documents/GitHub/OpenGL/lib)

# Link libraries
target_link_libraries(main glfw3)
#target_link_libraries(main imgui)

# Additional frameworks for macOS
if(APPLE)
    target_link_libraries(main
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()
