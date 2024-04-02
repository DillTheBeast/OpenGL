#include "GUI.h"
#include <iostream>

GUI::GUI() {}

void GUI::Input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_RELEASE) {
		std::cout << "Input" << std::endl;
	}
}

void GUI::dropDown() {
}