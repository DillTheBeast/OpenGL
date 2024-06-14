#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "physics.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <GL/freeglut.h>  // Use this for FreeGLUT

const int NUM_SEGMENTS = 100; // Number of segments to approximate the circle
const float RADIUS = 0.5f;    // Radius of the circle
const float WINDOW_WIDTH = 1000.0f;
const float WINDOW_HEIGHT = 800.0f;

std::vector<GLfloat> generateCircleVertices(float radius) {
    std::vector<GLfloat> vertices;
    
    // Center of the circle
    vertices.push_back(0.0f); // x
    vertices.push_back(0.0f); // y
    vertices.push_back(0.0f); // z (optional, if you're working in 3D)
    vertices.push_back(1.0f); // r
    vertices.push_back(0.0f); // g
    vertices.push_back(0.0f); // b
    
    // Vertices around the circumference
    for (int i = 0; i <= NUM_SEGMENTS; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(NUM_SEGMENTS);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        
        vertices.push_back(x); // x
        vertices.push_back(y); // y
        vertices.push_back(0.0f); // z (optional)
        vertices.push_back(1.0f); // r
        vertices.push_back(0.0f); // g
        vertices.push_back(0.0f); // b
    }
    
    return vertices;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set GLFW context version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Telling GLFW that a mac is being used
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 800, "Bouncing Ball", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load OpenGL functions using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Compile and link shaders
    Shader shaderProgram("PhysicsEngine/default.vert", "PhysicsEngine/default.frag");

    // Generate circle vertices
    std::vector<GLfloat> vertices = generateCircleVertices(RADIUS);

    // Generate and bind VAO
    VAO VAO;
    VAO.Bind();

    // Generate and bind VBO
    VBO VBO(vertices.data(), vertices.size() * sizeof(GLfloat));

    // Link VBO to VAO (positions and colors)
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);  // Positions
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));  // Colors

    // Unbind VAO and VBO
    VAO.Unbind();
    VBO.Unbind();

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Create a Ball object
    Ball ball(glm::vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), glm::vec2(100.0f, 100.0f), RADIUS);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll events
        glfwPollEvents();

        // Calculate deltaTime
        static float lastFrame = 0.0f;
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Update ball physics
        ball.update(deltaTime);
        ball.checkCollision(WINDOW_WIDTH, WINDOW_HEIGHT);

        // Clear the screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use the shader program
        shaderProgram.Activate();

        // Bind VAO
        VAO.Bind();
        
        // Update circle position based on ball physics
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(ball.position, 0.0f));
        unsigned int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, NUM_SEGMENTS + 2);

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Delete all resources
    VAO.Delete();
    VBO.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
