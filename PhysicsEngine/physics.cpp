#include "physics.h"

const glm::vec2 GRAVITY(0.0f, -9.81f);

Ball::Ball(glm::vec2 startPos, glm::vec2 startVel, float r)
    : position(startPos), velocity(startVel), radius(r) {}

void Ball::update(float deltaTime) {
    // Apply gravity to the velocity
    velocity += GRAVITY * deltaTime;
    // Update position based on velocity
    position += velocity * deltaTime;
}

void Ball::checkCollision(float windowWidth, float windowHeight) {
    // Check collision with the left and right window boundaries
    if (position.x - radius < 0.0f) {
        position.x = radius;
        velocity.x = -velocity.x;
    }
    if (position.x + radius > windowWidth) {
        position.x = windowWidth - radius;
        velocity.x = -velocity.x;
    }

    // Check collision with the bottom and top window boundaries
    if (position.y - radius < 0.0f) {
        position.y = radius;
        velocity.y = -velocity.y;
    }
    if (position.y + radius > windowHeight) {
        position.y = windowHeight - radius;
        velocity.y = -velocity.y;
    }
}
