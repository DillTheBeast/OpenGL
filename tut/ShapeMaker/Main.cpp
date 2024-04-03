//g++ -std=c++17 \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/glm \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/Main.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/EBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/VAO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/VBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/shaderClass.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/GUI.cpp \
    -o main \
    -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
    -lglfw3 \
    -framework OpenGL \
    -framework Cocoa \
    -framework IOKit \
    -framework CoreVideo


#include <iostream>
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
#include "GUI.h"

void takeInput(GLfloat vertices[]);

// Vertices coordinates (Goes from -1 to 1)
GLfloat vertices[] = {
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
    GLFWwindow* window = glfwCreateWindow(800, 800, "RGB Square", NULL, NULL);
    // Making sure window can be created
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Putting the window into the current context
    glfwMakeContextCurrent(window);

    // Initialize GLAD to load OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        // Handle GLAD initialization failure
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

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

    // Create instance of GUI
    GUI thing;

    // Generates Shader object using shaders default.vert and default.frag
    Shader shaderProgram("tut/ShapeMaker/default.vert", "tut/ShapeMaker/default.frag");

    // Create and bind VAO, VBO, and EBO objects
    VAO VAO1;
    VAO1.Bind();
    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    // Link VBO to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0); // Position attribute
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float))); // Color attribute

    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // Creating rotation variables
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    double prevTime = glfwGetTime();

    // Enables z-buffer so OpenGL knows which triangle texture goes on top of another
    glEnable(GL_DEPTH_TEST);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render the GUI elements
        thing.dropDown(window);

        // Update cube rotation only if settings menu is not toggled
        if (!thing.settingsMenuToggled) {
            // Timer to update rotation
            double crntTime = glfwGetTime();
            if (crntTime - prevTime >= 1 / 60 ) {
                rotationX += 0.5f;
                rotationY += 0.5f;

                // Ensure rotation angles stay within [0, 360) range
                // rotationX = fmod(rotationX, 360.0f);
                // rotationY = fmod(rotationY, 360.0f);
                prevTime = crntTime;
            }
        }

        // Setting background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        // Assign new background to back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        shaderProgram.Activate();

        // Initialize matrices
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);

        // Assign transformation to each matrix
        model = glm::rotate(model, glm::radians(rotationY), glm::vec3(1.0f, 0.0f, 0.0f)); // x-axis rotation
        model = glm::rotate(model, glm::radians(rotationX), glm::vec3(0.0f, 1.0f, 0.0f)); // y-axis rotation     
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
        proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

        // Outputs matrices into vertex shader
        int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Delete all the objects we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}