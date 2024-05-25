#include "physics.h"

Physics::Physics(float gravity, float bounceDamping)
    : gravity(gravity), bounceDamping(bounceDamping) {}

void Physics::update(glm::vec3& position, glm::vec3& velocity) {
    velocity += gravity;
    position += velocity;

    // Example collision detection and response with the bottom of the screen (assumed to be at y = -1.0f)
    if (position.y < -1.0f) {
        position.y = -1.0f;
        velocity.y *= -bounceDamping;

        // Ensure position doesn't go below the bottom of the window
        if (position.y < -1.0f) {
            position.y = -1.0f;
        }
    }
}
