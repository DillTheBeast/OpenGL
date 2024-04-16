#include "Button.h"
#include <glad/glad.h> // Include GLAD to get all the required OpenGL headers
#include <GLFW/glfw3.h>

Button::Button(float x, float y, float width, float height)
    : position(x, y), width(width), height(height) {}

void Button::render() {
    // Set up viewport
    int width, height;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &width, &height);
    glViewport(0, 0, width, height);

    // Clear the buffer
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Activate the shader program if you have one
    // shaderProgram.Activate(); // Activate your shader program here if needed

    // Define button vertices
    GLfloat vertices[] = {
        position.x, position.y, 0.0f, // Bottom-left
        position.x + width, position.y, 0.0f, // Bottom-right
        position.x + width, position.y + height, 0.0f, // Top-right
        position.x, position.y + height, 0.0f // Top-left
    };

    // Generate and bind VAO
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate VBO
    GLuint VBO;
    glGenBuffers(1, &VBO);

    // Bind VBO and buffer data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    // Render the button
    glDrawArrays(GL_QUADS, 0, 4);

    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Delete VAO and VBO
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // Swap buffers
    glfwSwapBuffers(glfwGetCurrentContext());
}

bool Button::isMouseOver(double mouseX, double mouseY) const {
    // Check if the mouse is over the button
    return mouseX >= position.x && mouseX <= position.x + width &&
           mouseY >= position.y && mouseY <= position.y + height;
}

bool Button::isClicked(double mouseX, double mouseY, int action) const {
    // Check if the mouse is clicked within the button's bounds
    return isMouseOver(mouseX, mouseY) && action == GLFW_PRESS;
}