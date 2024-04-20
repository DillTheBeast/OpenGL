#include "Button.h"
#include <iostream> // For demonstration purpose
#include <GLFW/glfw3.h>

Button::Button(float x, float y, float width, float height, const std::string& label)
    : x(x), y(y), width(width), height(height), label(label), visible(true) {}

void Button::render() const {
    if (visible) {
        // Render button on the screen using OpenGL
        glBegin(GL_QUADS);
        glColor3f(0.2f, 0.3f, 0.8f); // Set button color to light blue
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }
}

bool Button::isClicked(float mouseX, float mouseY) const {
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

void Button::toggleVisibility() {
    visible = !visible;
}

bool Button::isVisible() const {
    return visible;
}
