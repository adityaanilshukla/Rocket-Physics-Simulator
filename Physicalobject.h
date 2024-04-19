#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H

// Purpose: Abstract base class for all physical entities in the simulation.
// Attributes: Position (Vector3D), velocity (Vector3D), acceleration (Vector3D), mass (float).
// Methods: Virtual methods for updating state (e.g., updatePosition(float deltaTime)), and applying forces.

#include "Vector3D.h"

class Physicalobject {

	private:
		// Variables
		Vector3D position_;
		Vector3D velocity_;
		Vector3D acceleration_;
		float mass_;


	public:
		//constructor
		Physicalobject(const Vector3D& position, const Vector3D& velocity ,const Vector3D& acceleration, float& mass);

		//destructor
		virtual ~Physicalobject();

		//getters
		float getMass();
		Vector3D getPosition();
		Vector3D getVelocity();
		Vector3D getAcceleration();

		//virtual methods for updating state
		void updatePosition(float& deltaTime);



};

#endif //PHYSICALOBJECT_H
