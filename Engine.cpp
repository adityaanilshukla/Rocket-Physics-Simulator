#include "Engine.h"

//engine constructor
Engine::Engine(float &thrust, float &specificImpulse)
    : thrust(thrust), specificImpulse(specificImpulse),
      // TODO: make a gimbalVector class derived from Vector3D that only has x and y components as engine gimbal angles are only in the x and y directions
      gimbalAngles(neutralAngle, neutralAngle, neutralAngle)  // Initialize here in the initializer list
{
}

//engine destructor
Engine::~Engine(){}

//getters
float Engine::getThrust()
{
	return this->thrust;
}

float Engine::getSpecificImpulse()
{
	return this->specificImpulse;
}

void Engine::setGimbalAngles(float &x, float &y, float &z)
{
	//check if the gimbal angles are within the limits
	if (x > maxGimbalAngle)
	{
		x = maxGimbalAngle;
	}
	else if (x < -maxGimbalAngle)
	{
		x = -maxGimbalAngle;
	}
	if (y > maxGimbalAngle)
	{
		y = maxGimbalAngle;
	}
	else if (y < -maxGimbalAngle)
	{
		y = -maxGimbalAngle;
	}
	if (z > maxGimbalAngle)
	{
		z = maxGimbalAngle;
	}
	else if (z < -maxGimbalAngle)
	{
		z = -maxGimbalAngle;
	}
	//set the gimbal angles
	this->gimbalAngles = Vector3D(x, y, z);
}


Vector3D Engine::getGimbalAngles()
{
	return this->gimbalAngles;
}



