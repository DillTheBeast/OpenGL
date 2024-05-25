#include "physics.h"

Physics::Physics(float gravity, float bounceDamping)
    : gravity(gravity), bounceDamping(bounceDamping) {}

void Physics::update(float& position, float& velocity) {
    velocity += gravity;
    position += velocity;

    // Check for collision with the bottom of the screen (assumed to be -1.0f)
    if (position < -1.0f) {
        position = -1.0f;
        velocity *= -bounceDamping;

        // Ensure position doesn't go below the bottom of the window
        if (position < -1.0f) {
            position = -1.0f;
        }
    }
}

