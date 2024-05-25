//g++ -std=c++17 \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/test.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/src/glad.c \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/EBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/VAO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/VBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/shaderClass.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/physics.cpp \
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
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
//#include "physics.h"  // Include the Physics class

bool cubeMove = true;
bool cubeVisible = true;
bool keyPressed = false;
bool display = false;
bool xNeg = false;
bool yNeg = false;
bool xStop = false;
bool yStop = false;
int v = 0;

float cubeYPosition = 0.0f;
float cubeYVelocity = 0.0f;

GLfloat cubeVertices[] = {
    // 0
    -0.5f, -0.5f, 0.5f,  // Lower left front
    1.0f, 0.0f, 0.0f,     // Red color
    0.0f, 0.0f,          // Image coords

    // 1
    -0.5f, 0.5f, 0.5f,   // Upper left front
    0.0f, 1.0f, 0.0f,     // Green color
    0.0f, 0.0f,          // Image coords

    // 2
    0.5f, 0.5f, 0.5f,    // Upper right front
    0.0f, 0.0f, 1.0f,     // Blue color
    0.0f, 0.0f,          // Image coords

    // 3
    0.5f, -0.5f, 0.5f,   // Lower right front
    1.0f, 1.0f, 0.0f,     // Yellow color
    0.0f, 0.0f,          // Image coords

    // 4
    -0.5f, -0.5f, -0.5f,  // Lower left back
    0.0f, 1.0f, 1.0f,     // Cyan color
    0.0f, 0.0f,           // Image coords

    // 5
    -0.5f, 0.5f, -0.5f,   // Upper left back
    1.0f, 0.0f, 1.0f,     // Magenta color
    0.0f, 0.0f,           // Image coords

    // 6
    0.5f, 0.5f, -0.5f,    // Upper right back
    0.5f, 0.5f, 0.5f,     // Gray color
    0.0f, 0.0f,           // Image coords

    // 7
    0.5f, -0.5f, -0.5f,   // Lower right back
    1.0f, 0.5f, 0.0f,     // Orange color
    0.0f, 0.0f            // Image coords
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

    // Tell GLFW the version being used + Core profile is being used (Only modern functions)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Telling GLFW that a mac is being used
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Making GLFW window
    int width = 800;
    int height = 800;
    GLFWwindow *window = glfwCreateWindow(width, height, "Cube", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Introduce window into the current context
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, width, height);

    // Enable the depth buffer
    glEnable(GL_DEPTH_TEST);

    Shader shaderProgram("default.vert", "default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(cubeVertices, sizeof(cubeVertices));
    EBO EBO1(indices, sizeof(indices));

    // Link VBO attributes
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float)));

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Instantiate Physics class with appropriate parameters
    float gravity = 9.8f; // Example gravity value
    float bounceDamping = 0.5f; // Example bounce damping value
    //Physics physics(gravity, bounceDamping);

    // Main while loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // UI elements
        ImGui::Begin("Controls");

        if (ImGui::Button("Exit", ImVec2(200, 50))) {
            glfwSetWindowShouldClose(window, true);
        }

        if (ImGui::Button("Cube Move", ImVec2(200, 50))) {
            cubeMove = !cubeMove;
        }

        if (ImGui::Button("Vertice 1 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 1;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(xStop ? "Stop X" : "Start X", ImVec2(150, 50))) {
            xStop = !xStop;
        }

        ImGui::NewLine();

        if (ImGui::Button("Vertice 2 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 2;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(yStop ? "Stop Y" : "Start Y", ImVec2(150, 50))) {
            yStop = !yStop;
        }

        ImGui::NewLine();

        if (ImGui::Button("Vertice 3 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 3;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(xNeg ? "Pos X" : "Neg X", ImVec2(150, 50))) {
            xNeg = !xNeg;
        }

        ImGui::NewLine();

        if (ImGui::Button("Vertice 4 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 4;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(yNeg ? "Pos Y" : "Neg Y", ImVec2(150, 50))) {
            yNeg = !yNeg;
        }

        ImGui::NewLine();

        if (ImGui::Button("Vertice 5 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 5;
        }

        ImGui::SameLine(825);

        if (ImGui::Button("Vertice 6 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 6;
        }

        ImGui::NewLine();

        if (ImGui::Button("Vertice 7 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 7;
        }

        ImGui::SameLine(825);

        if (ImGui::Button("Vertice 8 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 8;
        }

        ImGui::NewLine();

        if (ImGui::Button("All Vertices", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 0;
        }

        if (display) {
            if (v == 0) {
                if (ImGui::ColorPicker3("Vertices 1 Color", (float *)&cubeVertices[3]) &&
                    ImGui::ColorPicker3("Vertices 2 Color", (float *)&cubeVertices[11]) &&
                    ImGui::ColorPicker3("Vertices 3 Color", (float *)&cubeVertices[19]) &&
                    ImGui::ColorPicker3("Vertices 4 Color", (float *)&cubeVertices[27]) &&
                    ImGui::ColorPicker3("Vertices 5 Color", (float *)&cubeVertices[35]) &&
                    ImGui::ColorPicker3("Vertices 6 Color", (float *)&cubeVertices[43]) &&
                    ImGui::ColorPicker3("Vertices 7 Color", (float *)&cubeVertices[51]) &&
                    ImGui::ColorPicker3("Vertices 8 Color", (float *)&cubeVertices[59])) {
                    display = false;
                    cubeVisible = true;
                }
            } else {
                if (ImGui::ColorPicker3("Color", (float *)&cubeVertices[3 + 8 * (v - 1)])) {
                    display = false;
                    cubeVisible = true;
                }
            }

            // Update the VBO with new vertex colors
            VBO1.Bind();
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(cubeVertices), cubeVertices);
            VBO1.Unbind();
        }

        ImGui::End();

        // Rendering
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Activate();
        VAO1.Bind();

        // Update physics
        //physics.update(cubeYPosition, cubeYVelocity);

        // Model matrix for transformations
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, cubeYPosition, 0.0f));

        if (cubeMove) {
            if (!xStop) {
                model = glm::rotate(model, glm::radians(xNeg ? -0.5f : 0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
            }
            if (!yStop) {
                model = glm::rotate(model, glm::radians(yNeg ? -0.5f : 0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
            }
        }

        // View and Projection matrices
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

        GLuint viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        GLuint projectionLoc = glGetUniformLocation(shaderProgram.ID, "projection");

        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        GLuint modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        if (cubeVisible) {
            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        }

        // ImGui rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
    }

    // Cleanup
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}