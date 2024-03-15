//g++ -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include tut/blank.cpp /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c -o main -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

    // Initialize GLFW
    glfwInit();

    //Tell GLFW the version being used + Core profile is being used (Only modern functions)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Telling GLFW that a mac is being used
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //Making GLFW window                                      Making window not fullscreen
    GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
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
    glViewport(0, 0, 800, 800);

    //Setting background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    //Assign new background to back buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //Swap back and front buffers
    glfwSwapBuffers(window);

    //Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents(); 
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
