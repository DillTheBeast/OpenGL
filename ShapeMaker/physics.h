#ifndef PHYSICS_H
#define PHYSICS_H

class Physics {
public:
    Physics(float gravity, float bounceDamping);
    void update(float& position, float& velocity);

private:
    float gravity;
    float bounceDamping;
};

#endif
