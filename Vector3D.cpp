#include "Vector3D.h"
#include <cmath>

// Constructor with parameters
Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

// Destructor
Vector3D::~Vector3D() {}

// Getters
float Vector3D::getX() { return x; }
float Vector3D::getY() { return y; }
float Vector3D::getZ() { return z; }
