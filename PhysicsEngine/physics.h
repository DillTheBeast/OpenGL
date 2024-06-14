#ifndef PHYSICS_H
#define PHYSICS_H

#include <glm/glm.hpp>

class Ball {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;

    Ball(glm::vec2 startPos, glm::vec2 startVel, float r);

    void update(float deltaTime);
    void checkCollision(float windowWidth, float windowHeight);
};

#endif // PHYSICS_H
