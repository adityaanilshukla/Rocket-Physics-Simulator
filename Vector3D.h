//handles basic vector operations for physical calculations such as addition subtraction
//scalar multiplication and division, dot product, cross product, and magnitude
#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {

	private:

	    // Variables
	    float x, y, z;

	public:

	    // Constructors
	    Vector3D(float x, float y, float z);
	    // Destructor
	    ~Vector3D(); 
	    
	    //getters
	    float getX();
	    float getY();
	    float getZ();

	    //vector operations
	    Vector3D operator+(const Vector3D& v);
	    Vector3D operator-(const Vector3D& v);

	    //scalar operations
	    Vector3D operator*(float scalar);



};

#endif // VECTOR3D_H
