#ifndef BUTTON_H
#define BUTTON_H

#include <string>

class Button {
private:
    float x, y;
    float width, height;
    std::string label;
    bool visible;

public:
    Button(float x, float y, float width, float height, const std::string& label);

    void render() const;

    bool isClicked(float mouseX, float mouseY) const;

    void toggleVisibility();

    bool isVisible() const;
};

#endif // BUTTON_H