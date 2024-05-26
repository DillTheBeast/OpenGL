//g++ -std=c++17 \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/Main.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/Shader.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/src/glad.c \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/imgui.cpp \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/imgui_demo.cpp \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/imgui_draw.cpp \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/imgui_widgets.cpp \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/imgui_tables.cpp \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/backends/imgui_impl_opengl3.cpp \
    /Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/backends/imgui_impl_glfw.cpp \
    -o main \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/glm \
    -I/Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui \
    -I/Users/dillonmaltese/documents/github/opengl/PhysicsEngine/include/imgui/backends \
    -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
    -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "Shader.h"

// Callback function for window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    // Use the shader program
    extern unsigned int shaderProgram;
    glUseProgram(shaderProgram);

    // Calculate the new aspect ratio and set it as a uniform
    float aspectRatio = (float)width / (float)height;
    int aspectRatioLocation = glGetUniformLocation(shaderProgram, "aspectRatio");
    glUniform1f(aspectRatioLocation, aspectRatio);
}

// Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

unsigned int shaderProgram; // Declare shaderProgram globally

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Physics Engine", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load all OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set viewport size and callback function for resizing
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Compile and link shaders
    shaderProgram = createShaderProgram("PhysicsEngine/default.vert", "PhysicsEngine/default.frag");

    // Calculate initial aspect ratio and set it as a uniform
    float aspectRatio = 800.0f / 600.0f;
    glUseProgram(shaderProgram);
    int aspectRatioLocation = glGetUniformLocation(shaderProgram, "aspectRatio");
    glUniform1f(aspectRatioLocation, aspectRatio);

    // Define circle vertices
    const int numSegments = 100; // Number of segments used to approximate the circle
    const float radius = 0.5f;   // Radius of the circle

    std::vector<float> vertices; // Vector to hold the vertex data

    // Center of the circle
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * M_PI * float(i) / float(numSegments); // Calculate the angle for this segment
        float x = radius * cosf(angle); // Calculate the x component
        float y = radius * sinf(angle); // Calculate the y component

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f); // z component is 0 since we are in 2D
    }

    // Generate and bind the VAO and VBO
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        glUseProgram(shaderProgram);

        // Bind the VAO (the circle)
        glBindVertexArray(VAO);

        // Draw the circle using GL_TRIANGLE_FAN
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size() / 3);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
