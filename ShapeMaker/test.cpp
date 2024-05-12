//g++ -std=c++17 \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/test.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/src/glad.c \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/EBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/VAO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/VBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/shaderClass.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/imgui.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/imgui_demo.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/imgui_draw.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/imgui_widgets.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/imgui_tables.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/backends/imgui_impl_opengl3.cpp \
    /Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/backends/imgui_impl_glfw.cpp \
    -o main \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/include \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/include/glm \
    -I/Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui \
    -I/Users/dillonmaltese/documents/github/opengl/Shapemaker/include/imgui/backends \
    -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
    -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo


#include <iostream>
#include <limits>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp> 
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

bool cubeMove = true;
bool cubeVisible = true;
bool keyPressed = false;
bool display = false;
bool xNeg = false;
bool yNeg = false;
bool xStop = false;
bool yStop = false;
int v = 0;

#define _USE_MATH_DEFINES
#include <cmath>

const int SPHERE_SEGMENTS = 50; // Increase for smoother sphere

// Function to generate vertices of a sphere
void generateSphere(std::vector<float>& vertices, std::vector<unsigned int>& indices) {
    const float radius = 0.5f;
    const float sectorStep = 2 * M_PI / SPHERE_SEGMENTS;
    const float stackStep = M_PI / SPHERE_SEGMENTS;
    
    for (int i = 0; i <= SPHERE_SEGMENTS; ++i) {
        float stackAngle = M_PI / 2 - i * stackStep;
        float xy = radius * cosf(stackAngle);
        float z = radius * sinf(stackAngle);
        
        for (int j = 0; j <= SPHERE_SEGMENTS; ++j) {
            float sectorAngle = j * sectorStep;
            float x = xy * cosf(sectorAngle);
            float y = xy * sinf(sectorAngle);
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
            
            float nx = x / radius;
            float ny = y / radius;
            float nz = z / radius;
            vertices.push_back(nx);
            vertices.push_back(ny);
            vertices.push_back(nz);
        }
    }
    
    for (int i = 0; i < SPHERE_SEGMENTS; ++i) {
        int k1 = i * (SPHERE_SEGMENTS + 1);
        int k2 = k1 + SPHERE_SEGMENTS + 1;
        
        for (int j = 0; j < SPHERE_SEGMENTS; ++j, ++k1, ++k2) {
            if (i != 0) {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }
            
            if (i != (SPHERE_SEGMENTS - 1)) {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
}

// Vertices coordinates (Goes from -1 to 1)
GLfloat cubeVertices[] = {
    // 0
    -0.5f, 0.0f, 0.5f, // Lower left
    1.0f, 1.0f, 1.0f,   // Color
    0.0f, 0.0f,         // Image coords

    -0.5f, 0.0f, -0.5f,  // Upper left
    1.0f, 1.0f, 1.0f,   // Color
    0.0f, 0.0f,         // Image coords

    0.5f, 0.0f, -0.5f,   // Upper right
    1.0f, 1.0f, 1.0f,   // Color
    0.0f, 0.0f,         // Image coords

    0.5f, 0.0f, 0.5f,  // Lower right
    1.0f, 1.0f, 1.0f,   // Color
    0.0f, 0.0f,          // Image coords

    0.0f, 0.8f, 0.0f,    // Middle
    1.0f, 1.0f, 1.0f, //Color 
    0.0f, 0.0f // Image coords
};

GLuint indices[] = {
    // Front face
    0, 1, 2,
    0, 2, 3,

    // Left face
    4, 5, 1,
    4, 1, 0,

    // Right face
    3, 2, 6,
    3, 6, 7,

    // Bottom face
    0, 3, 7,
    0, 7, 4,

    // Top face
    1, 5, 6,
    1, 6, 2,

    // Back face
    5, 4, 7,
    5, 7, 6
};

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1000, 800, "Sphere", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL functions
    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set viewport size
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Generate sphere vertices and indices
    std::vector<float> sphereVertices;
    std::vector<unsigned int> sphereIndices;
    generateSphere(sphereVertices, sphereIndices);

    // Create shader program
    Shader shaderProgram("ShapeMaker/default.vert", "ShapeMaker/default.frag");

    // Create vertex array object (VAO), vertex buffer object (VBO), and element buffer object (EBO)
    VAO VAO;
    VAO.Bind();
    VBO VBO(sphereVertices.data(), sphereVertices.size() * sizeof(float));
    EBO EBO(sphereIndices.data(), sphereIndices.size() * sizeof(unsigned int));
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // Position attribute
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); // Normal attribute
    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll events
        glfwPollEvents();

        // Clear the color and depth buffers
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Activate shader program
        shaderProgram.Activate();

        // Set up transformations
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

        // Pass transformations to the shader
        shaderProgram.SetMatrix4("model", model);
        shaderProgram.SetMatrix4("view", view);
        shaderProgram.SetMatrix4("projection", projection);

        // Bind VAO and draw
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, sphereIndices.size(), GL_UNSIGNED_INT, 0);

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
