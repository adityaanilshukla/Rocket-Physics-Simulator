#include "Physicalobject.h"
#include <cmath>

Physicalobject::Physicalobject(const Vector3D& position, const Vector3D& velocity, const Vector3D& acceleration, float& mass)
: position_(position), velocity_(velocity) ,acceleration_(acceleration), mass_(mass) {}

Physicalobject::~Physicalobject() {}

float Physicalobject::getMass() {
    return mass_;
}

Vector3D Physicalobject::getPosition() {
	return position_;
}

Vector3D Physicalobject::getVelocity(){
	return velocity_;
}

Vector3D Physicalobject::getAcceleration(){
	return acceleration_;
}
// we multipy 0.5f after to prevent commutative property of multiplication of C++
void Physicalobject::updatePosition(float& deltaTime){
	position_ = position_ + velocity_ * deltaTime + acceleration_ * (0.5f * deltaTime * deltaTime);
	velocity_ = velocity_ + acceleration_ * deltaTime;
}











