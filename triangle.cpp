//g++ -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include triangle.cpp /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c -o main -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);  
void processInput(GLFWwindow *window);
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Creating Window + making sure GLFW is initialized
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    //Making sure GLAD is initialized properly
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    } 
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };  

    //Keeping window running
    //glfwwindowShouldClose sees whether the window was closed
    while(!glfwWindowShouldClose(window)) {
        //Calling function
        processInput(window);

        //Where rendering goes


        //Keyboard/Mouse input
        glfwPollEvents();  
        //Update screen
        glfwSwapBuffers(window);  
    }


    glfwTerminate();
    return 0;
}

//Making everything scale with the window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

//Taking input and doing something with it
void processInput(GLFWwindow *window)
{
    //If escape key is pressed, close the window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
