#include "GUI.h"
#include <iostream>
#include <glad/glad.h>

GUI::GUI() {}

void GUI::dropDown(GLFWwindow* window) {
    // Toggle the settings menu flag when the user presses the Escape key
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        settingsMenuToggled = !settingsMenuToggled;
    }

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Start rendering GUI elements
    // For example, you can draw a simple rectangle representing a button
    // You can use GLFW functions like glfwGetWindowSize to get the window size
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // Set the viewport to match the window size
    glViewport(0, 0, width, height);

    // Draw a rectangle representing a button
    // Use modern OpenGL to draw geometry
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.3f, 0.4f); // Set button color
    glVertex2f(0.25f * width, 0.5f * height); // Bottom left corner
    glVertex2f(0.75f * width, 0.5f * height); // Bottom right corner
    glVertex2f(0.75f * width, 0.7f * height); // Top right corner
    glVertex2f(0.25f * width, 0.7f * height); // Top left corner
    glEnd();

    // Swap the front and back buffers
    glfwSwapBuffers(window);
}