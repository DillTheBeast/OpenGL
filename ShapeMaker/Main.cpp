
//g++ -std=c++17 \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/ShapeMaker/Main.cpp \
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
#include "physics.h"
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

// Vertices coordinates (Goes from -1 to 1)
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
    GLFWwindow* window = glfwCreateWindow(1000, 800, "RGB Square", NULL, NULL);
    // Making sure window can be created
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Putting the window into the current context
    glfwMakeContextCurrent(window);

    // Loading opengl configurations
    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Tell opengl the area of the window
    // Bottom left --> top right
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Generates Shader object using shaders default.vert and default.frag
    Shader shaderProgram("ShapeMaker/default.vert", "ShapeMaker/default.frag");

    // Generates Vertex Array Object and binds it
    VAO VAO;
    VAO.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO(cubeVertices, sizeof(cubeVertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO(indices, sizeof(indices));

    // Links VBO to VAO
    VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0); // Position attribute
    VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float))); // Color attribute
    //VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float))); // Image Coords attribute // Image Coords attribute

    // Unbind all to prevent accidentally modifying them
    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();

    // Creating rotation variables
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    double prevTime = glfwGetTime();

    // Enables z-buffer so OpenGL knows which triangle texture goes on top of another
    glEnable(GL_DEPTH_TEST);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    float gravity = 9.8f;
    float bounceDamping = 0.5f;
    Physics physics(gravity, bounceDamping);

    //Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll events
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Set up the main ImGui window
        ImGui::SetNextWindowSize(ImVec2(1000, 800)); // Set the window size to accommodate all buttons
        ImGui::SetNextWindowPos(ImVec2(10, 10)); // Set the window position
        ImGui::Begin("Controls", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground);

        // Set text size
        ImGui::SetWindowFontScale(1.2); // Set text scale

        if (ImGui::Button("Close Application", ImVec2(150, 50))) {
            glfwSetWindowShouldClose(window, true);
        }

        // Move to the right side of the window
        ImGui::SameLine(825);

        if (ImGui::Button(cubeMove ? "Stop Spinning" : "Start Spinning", ImVec2(150, 50))) {
            cubeMove = !cubeMove;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 1 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 1;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(xStop ? "Stop X" : "Start X", ImVec2(150, 50))) {
            // Button action
            xStop = !xStop;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 2 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 2;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(yStop ? "Stop Y" : "Start Y", ImVec2(150, 50))) {
            // Button action
            yStop = !yStop;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 3 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 3;
        }

        ImGui::SameLine(825);

        if (ImGui::Button("Reverse Both", ImVec2(150, 50))) {
            // Button action
            xNeg = !xNeg;
            yNeg = !yNeg;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 4 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 4;
        }

        ImGui::SameLine(825);

        if (ImGui::Button("Reverse X", ImVec2(150, 50))) {
            // Button action
            xNeg = !xNeg;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 5 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 5;
        }

        ImGui::SameLine(825);

        if (ImGui::Button("Reverse Y", ImVec2(150, 50))) {
            // Button action
            yNeg = !yNeg;
        }
        
        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 6 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 6;
        }

        ImGui::SameLine(825);

        if (ImGui::Button(cubeVisible ? "Cube Visible" : "Cube Invisible", ImVec2(150, 50))) {
            cubeVisible = !cubeVisible;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 7 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 7;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("Vertice 8 Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = 8;
        }

        // Move to the next line
        ImGui::NewLine();

        if (ImGui::Button("All Vertice Color", ImVec2(150, 50))) {
            cubeVisible = false;
            display = true;
            v = -1;
        }

        if (display) {
            ImGui::NewLine();

            // RGB scale selector
            static ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // Initial color
            ImGui::ColorEdit3("RGB", (float*)&color); // Color picker for RGB

            // Display the selected color
            ImGui::Text("Selected Color:");
            ImGui::SameLine();
            ImGui::ColorButton("##ColorButton", color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_NoTooltip, ImVec2(50, 25));
            ImGui::SameLine();
            if (ImGui::Button("Enter", ImVec2(50, 25))) {
                float red = color.x;
                float green = color.y;
                float blue = color.z;

                if (v == -1) {
                    for(int i = 0; i < 8; i++) {
                        cubeVertices[(8 * (i) + 3)] = red;
                        cubeVertices[(8 * (i) + 4)] = green;
                        cubeVertices[(8 * (i) + 5)] = blue;
                    }
                }

                else {
                    cubeVertices[(8 * (v-1) + 3)] = red;
                    cubeVertices[(8 * (v-1) + 4)] = green;
                    cubeVertices[(8 * (v-1) + 5)] = blue;
                }
                
                cubeVisible = true;
                display = false;
            }
        }

        // Bind VBO
        VBO.Bind();
        // Update the data in VBO
        VBO.BufferData(cubeVertices, sizeof(cubeVertices));
        // Unbind VBO
        VBO.Unbind();

        ImGui::End(); // End the main ImGui window

        // Call the keyPress function with the obtained parameters
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Activate shader program
        shaderProgram.Activate();

        glm::vec3 cubePosition = glm::vec3(0.0f, 0.0f, 0.0f); // Initialize cube position to the origin
        glm::vec3 cubeVelocity = glm::vec3(0.0f, 0.0f, 0.0f); // Initialize cube velocity to zero


        physics.update(cubePosition, cubeVelocity);

        // Update rotation if cube is spinning
        if (cubeMove) {
            double currentTime = glfwGetTime();
            if (currentTime - prevTime >= 1 / 60) {
                if (!xStop) {
                    if (xNeg) {
                        rotationX -= 0.5f;
                    }
                    else {
                        rotationX += 0.5f;
                    }
                }
                if (!yStop) {
                    if (yNeg) {
                        rotationY -= 0.5f;
                    }
                    else {
                        rotationY += 0.5f;
                    }
                }
                prevTime = currentTime;
            }
        }

        // Initialize matrices
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);

        // Assign transformations
        model = glm::rotate(model, glm::radians(rotationY), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(rotationX), glm::vec3(0.0f, 1.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
        proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

        // Pass matrices to vertex shader
        int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

        // Bind VAO
        VAO.Bind();
        if(cubeVisible) {
            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        }

        // Render Dear ImGui into screen
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Delete all the objects we've created
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    VAO.Delete();
    VBO.Delete();
    EBO.Delete();
    shaderProgram.Delete();
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}