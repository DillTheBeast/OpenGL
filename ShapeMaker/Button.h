#ifndef BUTTON_H
#define BUTTON_H

#include <glm/glm.hpp>

class Button {
public:
    Button(float x, float y, float width, float height);

    void render();
    bool isMouseOver(double mouseX, double mouseY) const;
    bool isClicked(double mouseX, double mouseY, int action) const;
    void toggleVisibility() { visible = !visible; }
    bool visible = false;

private:
    glm::vec2 position;
    float width, height;
};

#endif // BUTTON_H
