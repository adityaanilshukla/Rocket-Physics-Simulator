
#include "Rocket.h"

//rocket constructor
Rocket::Rocket(Vector3D &position, Vector3D &velocity, Vector3D &acceleration, float &dryMass, float &thrust, float &dragCoefficient, float &crossSectionalArea, float &fuelMass) : Physicalobject(position, velocity, acceleration, dryMass)
{
	this->thrust = thrust;
	this->dragCoefficient = dragCoefficient;
	this->crossSectionalArea = crossSectionalArea;
	this->fuelMass = fuelMass;
}

Rocket::~Rocket(){}
