#include "Engine.h"

//engine constructor
Engine::Engine(float thrust, float specificImpulse)
    : thrust(thrust), specificImpulse(specificImpulse),
      gimbalAngles(neutralAngle, neutralAngle, neutralAngle)  // Initialize here in the initializer list
{
}

//engine destructor
Engine::~Engine(){}
