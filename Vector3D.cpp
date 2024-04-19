#include "Vector3D.h"
#include <cmath>

// Constructor with parameters
Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

// Destructor
Vector3D::~Vector3D() {}

// Getters
float Vector3D::getX() { return this->x; }
float Vector3D::getY() { return this->y; }
float Vector3D::getZ() { return this->z; }

//Vector operations
Vector3D Vector3D::operator+(const Vector3D& v) {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D& v) {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

//Scalar operations
Vector3D Vector3D::operator*(float scalar) {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}






