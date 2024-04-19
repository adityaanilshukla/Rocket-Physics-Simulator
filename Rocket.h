#ifndef ROCKET_H
#define ROCKET_H
#include "Physicalobject.h"
#include "Engine.h"

// Inherits: PhysicalObject
// Purpose: Represents the rocket with specific attributes and behaviors
// Additional Attributes: Engine (Engine), drag coefficient (float), cross-sectional area (float)
// Methods:calculateDrag(): Computes drag based on current velocity and environmental data
// updateState(float deltaTime): Override to include engine thrust calculations and fuel consumption

class Rocket : public Physicalobject
{
	private:
		//attributes
		float dragCoefficient;
		float crossSectionalArea;
		float fuelMass;
		float dryMass;

	public:

		Engine *rocketEngine;

		//constructor
		Rocket(Vector3D &position, Vector3D &velocity, Vector3D &acceleration, float &dryMass, float &fuelMass ,float &thrust, float &dragCoefficient, float &crossSectionalArea, float &specificImpulse);

		//destructor
		virtual ~Rocket();

		//methods
		void updateMass(float &deltaTime);
		bool fuelNotDepleted();

		//getters
		float getThrust();
		float getDragCoefficient();
		float getCrossSectionalArea();
		float getFuelMass();
		float getDryMass();
		float getSpecificImpulse();
};

#endif // ROCKET_H
