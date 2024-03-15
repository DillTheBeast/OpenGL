//g++ -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include tut/triangle.cpp /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c -o main -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main() {

    // Initialize GLFW
    glfwInit();

    //Tell GLFW the version being used + Core profile is being used (Only modern functions)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Telling GLFW that a mac is being used
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Vertices coordinates (Goes from -1 to 1) 
    GLfloat vertices[] = {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    // Lower left
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,     // Lower right
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  // Top

    };

    //Making GLFW window                                      Making window not fullscreen
    GLFWwindow* window = glfwCreateWindow(800, 800, "Engine", NULL, NULL);
    //Making sure window can be created
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Putting the window into the current context
    glfwMakeContextCurrent(window);

    //Loading opengl configurations
    gladLoadGL();

    //Tell opengl the area of the window 
    //Bottom left --> top right
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //             Reference value, length of source string, pointer to source code, NULL
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // Compiling the source code
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //             Reference value, length of source string, pointer to source code, NULL
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    // Compiling the source code
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 

    //VAO = stores pointers to VBO + tell opengl how to use VBO
    GLuint VAO, VBO;

    //VAO needs to be before VBO 
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO); 

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Storing vertices in VBO
    //           Type of Buffer, size of buffer, pointer to data, usage
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Tell opengl how to read VBO
    //                    Pos, Size, Type, int coords?, Amount of data, Pointer to data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 

    // Bind the VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Setting background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    //Assign new background to back buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //Swap back and front buffers
    glfwSwapBuffers(window);

    //Main loop
    while (!glfwWindowShouldClose(window)) {
        //Setting background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        //Assign new background to back buffer
        glClear(GL_COLOR_BUFFER_BIT);
        //Using the shaders
        glUseProgram(shaderProgram);
        //Draw the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //Swap back and front buffers
        glfwSwapBuffers(window);

        glfwPollEvents(); 
    }

    //Deleting objects
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}