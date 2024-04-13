#include "Physicalobject.h"
#include <cmath>

Physicalobject::Physicalobject(const Vector3D& position, const Vector3D& velocity, const Vector3D& acceleration, float& mass)
: position_(position), velocity_(velocity) ,acceleration_(acceleration), mass_(mass) {}

Physicalobject::~Physicalobject() {}

float Physicalobject::getMass() {
    return mass_;
}
