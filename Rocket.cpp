#include "Rocket.h"
#include "Engine.h"

//rocket constructor
Rocket::Rocket(Vector3D &position, Vector3D &velocity, Vector3D &acceleration, 
               float &dryMass, float &fuelMass, float &thrust, 
               float &dragCoefficient, float &crossSectionalArea, float &specificImpulse)

    // Call the parent constructor
    : Physicalobject(position, velocity, acceleration, dryMass),
      dragCoefficient(dragCoefficient), crossSectionalArea(crossSectionalArea),
      fuelMass(fuelMass), dryMass(dryMass){
	
    //create engine after all values are properly assigned
    this->rocketEngine = new Engine(thrust, specificImpulse);
}	


Rocket::~Rocket()
{
	delete this->rocketEngine;
}

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
	// float fuelFlowRate = (this->thrust/this->specificImpulse);

	float fuelFlowRate = this->rocketEngine->getThrust()/this->rocketEngine->getSpecificImpulse();

	float fuelUsedThisTimeStep = fuelFlowRate * deltaTime;
	this->fuelMass -= fuelUsedThisTimeStep;
	}
}

//getters
float Rocket::getThrust()
{
	return this->rocketEngine->getThrust();
}

float Rocket::getDragCoefficient()
{
	return this->dragCoefficient;
}

float Rocket::getCrossSectionalArea()
{
	return this->crossSectionalArea;
}

float Rocket::getFuelMass()
{
	return this->fuelMass;
}

float Rocket::getDryMass()
{
	return this->dryMass;
}

float Rocket::getSpecificImpulse()
{
	return this->rocketEngine->getSpecificImpulse();
}

Vector3D Rocket::getGimbalAngles()
{
	return this->rocketEngine->getGimbalAngles();
}

void Rocket::setGimbalAngles(float &x, float &y, float &z)
{
	this->rocketEngine->setGimbalAngles(x, y, z);
}






