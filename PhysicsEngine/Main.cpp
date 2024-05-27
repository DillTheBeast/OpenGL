//g++ -std=c++17 \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/Main.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/Shader.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/src/glad.c \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/imgui.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/imgui_demo.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/imgui_draw.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/imgui_widgets.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/imgui_tables.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/backends/imgui_impl_opengl3.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/backends/imgui_impl_glfw.cpp \
    -o main \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/glm \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/PhysicsEngine/include/imgui/backends \
    -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
    -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "Shader.h"

// Global shader program ID
unsigned int shaderProgram;

// Callback function for window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
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

// Function to build circle vertex data
void buildCircle(float radius, int vCount, std::vector<glm::vec3>& vertices) {
    float angleStep = 360.0f / vCount;

    vertices.push_back(glm::vec3(0.0f, 0.0f, 0.0f)); // Center point

    for (int i = 0; i <= vCount; ++i) {
        float angle = glm::radians(angleStep * i);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        vertices.push_back(glm::vec3(x, y, 0.0f));
    }
}

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

    // Build circle vertices
    std::vector<glm::vec3> vertices;
    buildCircle(0.5f, 100, vertices); // Adjust the segment count for a smoother circle

    // Compile and link shaders
    shaderProgram = createShaderProgram("PhysicsEngine/default.vert", "PhysicsEngine/default.frag");

    // Calculate initial aspect ratio and set it as a uniform
    float aspectRatio = 800.0f / 600.0f;
    glUseProgram(shaderProgram);
    int aspectRatioLocation = glGetUniformLocation(shaderProgram, "aspectRatio");
    glUniform1f(aspectRatioLocation, aspectRatio);

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Use shader program
        glUseProgram(shaderProgram);

        // Bind vertex array and draw circle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
