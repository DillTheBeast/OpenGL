#include "GUI.h"
#include <GLFW/glfw3.h>
#include <iostream>

void GUI::Input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        dropDown();
    }
}

void GUI::dropDown() {
    GLFWwindow* window = glfwCreateWindow(800, 800, "Test", NULL, NULL);
}