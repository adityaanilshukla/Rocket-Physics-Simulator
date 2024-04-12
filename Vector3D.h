//handles basic vector operations for physical calculations such as addition subtraction
//scalar multiplication and division, dot product, cross product, and magnitude
#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    float x, y, z;  // Public members (ideally should be private with getter and setter methods)

    // Constructors
    Vector3D(float x, float y, float z);

    // Destructor
    ~Vector3D(); 
    
    //getters
    float getX();
    float getY();
    float getZ();
};

#endif // VECTOR3D_H
