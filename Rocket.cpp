
#include "Rocket.h"

//rocket constructor
Rocket::Rocket(Vector3D &position, Vector3D &velocity, Vector3D &acceleration, float &dryMass, float &fuelMass ,float &thrust, float &dragCoefficient, float &crossSectionalArea, float &specificImpuse) : Physicalobject(position, velocity, acceleration, dryMass)
{
	this->thrust = thrust;
	this->dragCoefficient = dragCoefficient;
	this->crossSectionalArea = crossSectionalArea;
	this->fuelMass = fuelMass;
	this->dryMass = dryMass;
	this->specificImpulse = specificImpuse;
}

Rocket::~Rocket(){}

bool Rocket::fuelNotDepleted()
{
	if(this->fuelMass > 0){
		return true;
	}
	else{
		return false;
	}
}


void Rocket::updateMass(float &deltaTime)
{
	if(fuelNotDepleted()){
	//rocket fuel flow rate is thrust/specificImpulse. After updateMass is called the fuel mass should be reduced
	float fuelFlowRate = (this->thrust/this->specificImpulse);
	float fuelUsedThisTimeStep = fuelFlowRate * deltaTime;
	this->fuelMass -= fuelUsedThisTimeStep;
	}
}
