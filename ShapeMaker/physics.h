#ifndef PHYSICS_H
#define PHYSICS_H

#include <glm/vec3.hpp>

class Physics {
public:
    Physics(float gravity, float bounceDamping);
    void update(glm::vec3& position, glm::vec3& velocity);

private:
    float gravity;
    float bounceDamping;
};

#endif
