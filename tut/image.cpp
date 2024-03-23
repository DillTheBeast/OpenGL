//g++ -std=c++17 -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include \
tut/image.cpp /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c \
/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/EBO.cpp \
/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/VAO.cpp \
/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/VBO.cpp \
/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/stb.cpp \
/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/Texture.cpp \
/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/shaderClass.cpp \
-o main -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
-lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

#include <filesystem>
namespace fs = std::filesystem;

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "Texture.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

// Vertices coordinates (Goes from -1 to 1)
GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f, // Lower left
    1.0f, 0.0f, 0.0f,   // Color
    0.0f, 0.0f,         // Image coords

    -0.5f, 0.5f, 0.0f,  // Upper left
    0.0f, 1.0f, 0.0f,   // Color
    0.0f, 1.0f,         // Image coords

    0.5f, 0.5f, 0.0f,   // Upper right
    0.0f, 0.0f, 1.0f,   // Color
    1.0f, 1.0f,         // Image coords

    0.5f, -0.5f, 0.0f,  // Lower right
    1.0f, 1.0f, 1.0f,   // Color
    1.0f, 0.0f          // Image coords
};

GLuint indices[] = {
    0, 2, 1, // Upper triangle
    0, 3, 2  // Lower triangle
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

    // Texture loading
    int widthImg, heightImg, numChannels;
    unsigned char* bytes = stbi_load("/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/textures/LinuxIcon.png", &widthImg, &heightImg, &numChannels, 0);
    if (!bytes) {
        std::cerr << "Failed to load texture" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "Image loaded successfully. Dimensions: " << widthImg << "x" << heightImg << ", Channels: " << numChannels << std::endl;

    // Generates Shader object using shaders default.vert and default.frag
    Shader shaderProgram("tut/default.vert", "tut/default.frag");

    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0); // Position attribute
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float))); // Color attribute
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float))); // Image Coords attribute // Image Coords attribute

    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    std::string parentDir = (fs::current_path().parent_path()).string();
    std::string texPath = "/tut/textures/";

    // Texture
    //Texture icon((parentDir + texPath + "LinuxIcon.png").c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    Texture icon("/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/textures/LinuxIcon.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    icon.texUnit(shaderProgram, "tex0", 0);

    // Main loop
    // Main loop
while (!glfwWindowShouldClose(window)) {
        // Setting background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        // Assign new background to back buffer
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Changes size of triangle
        glUniform1f(uniID, 0.5f);
        icon.Bind();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Check for OpenGL errors
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL Error before swapping buffers: " << error << std::endl;
        }

        // Swap back and front buffers
        glfwSwapBuffers(window);

        // Check for OpenGL errors
        error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL Error after swapping buffers: " << error << std::endl;
        }

        glfwPollEvents();
    }


    // Delete all the objects we've created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    icon.Delete();
    shaderProgram.Delete();
    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}
