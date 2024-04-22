#ifndef ENGINE_H 
#define ENGINE_H

#include "Vector3D.h"

// Purpose: Represents the rocket's engine, capable of gimbaling to adjust thrust direction.
// Attributes: Thrust magnitude (float), gimbal angles (Vector3D where x, y, z represent angles in respective axes).
// Methods:
// calculateThrustVector(): Uses the gimbal angles to compute the vector direction of the thrust.
// 			 updateGimbalAngles(Vector3D newAngles): Updates the gimbal angles based on control inputs


class Engine
{

private:
	float neutralAngle = 0; // Declare and initialize before gimbalAngles
	float thrust;
	float specificImpulse;
	Vector3D gimbalAngles;
	float maxGimbalAngle = 5; //degrees

public:

	Engine(float &thrust, float &specificImpulse);
	virtual ~Engine();

	//getters
	float getThrust();
	float getSpecificImpulse();
	float calculateThrustVector();

	//setters
	void setGimbalAngles(float &x, float &y, float &z);
	Vector3D getGimbalAngles();
};

#endif // ENGINE_H
