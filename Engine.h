#ifndef ENGINE_H 
#define ENGINE_H 
#include "Rocket.h"


// Purpose: Represents the rocket's engine, capable of gimbaling to adjust thrust direction.
// Attributes: Thrust magnitude (float), gimbal angles (Vector3D where x, y, z represent angles in respective axes).
// Methods:
// calculateThrustVector(): Uses the gimbal angles to compute the vector direction of the thrust.
// 			 updateGimbalAngles(Vector3D newAngles): Updates the gimbal angles based on control inputs


class Engine : private Rocket {

private:
	//attributes
	float thrustMagnitude;
	float specificImpulse;
	Vector3D gimbalAngles(0,0,0);

	//the constructor for Engine should be called by the constructor for Rocket
	//it should then set the thrustMagnitude and specificImpulse to the values passed to
	//the constructor for Rocket
	
public:
	//methods
	Vector3D calculateThrustVector();
	void updateGimbalAngles(Vector3D newAngles);
	
	//constructor
	Engine(float thrustMagnitude, float specificImpulse);
	
	//destructor
	~Engine();


};



#endif // ENGINE_H
