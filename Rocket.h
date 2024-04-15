#ifndef ROCKET_H
#define ROCKET_H
#include "Physicalobject.h"

    // Inherits: PhysicalObject
    // Purpose: Represents the rocket with specific attributes and behaviors.
    // Additional Attributes: Thrust (Vector3D), drag coefficient (float), cross-sectional area (float), fuel mass (float), dry mass (float).
    // Methods: Calculate thrust, drag, update mass (fuel consumption), calculate net force, update state (override with specific rocket behaviors).

class Rocket : public Physicalobject
{	
	public:
		//attributes
		float thrust;
		float dragCoefficient;
		float crossSectionalArea;
		float fuelMass;
		float dryMass;

		//constructor
		Rocket(Vector3D &position, Vector3D &velocity, Vector3D &acceleration, float &dryMass, float &fuelMass ,float &thrust, float &dragCoefficient, float &crossSectionalArea);

		//destructor
		virtual ~Rocket();
};

#endif // ROCKET_H
