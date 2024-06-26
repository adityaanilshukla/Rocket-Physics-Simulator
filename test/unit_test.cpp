#include <gtest/gtest.h>
#include "../Vector3D.h" 
#include "../Physicalobject.h"
#include "../Rocket.h"
#include "../Engine.h"


TEST(Vector3D, constructor)
{
	Vector3D v(0, 0, 0);
	EXPECT_EQ(0, v.getX());
	EXPECT_EQ(0, v.getY());
	EXPECT_EQ(0, v.getZ());
}


TEST(Vector3D, addition)
{
	Vector3D v1(1, 2, 3);
	Vector3D v2(4, 5, 6);
	Vector3D v3 = v1 + v2;
	EXPECT_EQ(5, v3.getX());
	EXPECT_EQ(7, v3.getY());
	EXPECT_EQ(9, v3.getZ());
}

TEST( Vector3D, subtraction)
{
	Vector3D v1(1, 2, 3);
	Vector3D v2(4, 5, 6);
	Vector3D v3 = v1 - v2;
	EXPECT_EQ(-3, v3.getX());
	EXPECT_EQ(-3, v3.getY());
	EXPECT_EQ(-3, v3.getZ());
}

TEST(Vector3D, scalarMultiplication)
{
	Vector3D v1(1, 2, 3);
	Vector3D v2 = v1 * 2.0f;
	EXPECT_EQ(2, v2.getX());
	EXPECT_EQ(4, v2.getY());
	EXPECT_EQ(6, v2.getZ());
}

TEST(Physicalobject, constructor)
{
	Vector3D position(1, 2, 3);
	Vector3D velocity(4, 5, 6);
	Vector3D acceleration(4, 5, 6);
	float mass = 7;
	Physicalobject p(position ,velocity ,acceleration, mass);
	EXPECT_EQ(mass, p.getMass());
	EXPECT_EQ(position.getX(), p.getPosition().getX());
	EXPECT_EQ(velocity.getY(), p.getVelocity().getY());
	EXPECT_EQ(acceleration.getZ(), p.getAcceleration().getZ());
}

TEST(Physicalobject, updatePosition)
{
	Vector3D position(1, 2, 3);
	Vector3D velocity(4, 5, 6);
	Vector3D acceleration(4, 5, 6);
	float mass = 7;
	float deltaTime = 4;

	// we multipy 0.5f after to prevent commutative property of multiplication of C++
	Vector3D displacement = velocity * deltaTime + acceleration * 0.5f * deltaTime * deltaTime;	
	Physicalobject p(position ,velocity ,acceleration, mass);
	p.updatePosition(deltaTime);
	Vector3D expectedPosition = position + displacement;

	EXPECT_EQ(expectedPosition.getX(), p.getPosition().getX());
	EXPECT_EQ(expectedPosition.getY(), p.getPosition().getY());
	EXPECT_EQ(expectedPosition.getZ(), p.getPosition().getZ());
}

//a method to create a generic Rocket object for testing purposes
//this method is used to create a rocket object with the same specifications as the v2 rocket
//it allows us to not repeat code in the tests as the Rocket constructor is used in multiple tests

Rocket createRocket()
{
	//v2 rocket specifications real values
	Vector3D position(0, 0, 0);
	Vector3D velocity(0, 0, 0);
	Vector3D acceleration(0, 0, 0);
	float dryMass = 5000;
	float fuelMass = (12000-dryMass);
	float thrust = 25000*9.81;
	float dragCoefficient = 0.15f;
	float crossSectionalArea = 15.0f;
	float specificImpulse = 250;

	//constructor
	Rocket r (position, velocity, acceleration, dryMass, fuelMass ,thrust, dragCoefficient, crossSectionalArea, specificImpulse);
	return r;
}

TEST(Rocket, constructor)
{
	//v2 rocket specifications real values
	Vector3D position(0, 0, 0);
	Vector3D velocity(0, 0, 0);
	Vector3D acceleration(0, 0, 0);
	float dryMass = 5000;
	float fuelMass = (12000-dryMass);
	float thrust = 25000*9.81;
	float dragCoefficient = 0.15f;
	float crossSectionalArea = 15.0f;
	float specificImpulse = 250;

	//constructor
	Rocket r (position, velocity, acceleration, dryMass, fuelMass ,thrust, dragCoefficient, crossSectionalArea, specificImpulse);


	EXPECT_EQ(dragCoefficient, r.getDragCoefficient());
	EXPECT_EQ(crossSectionalArea, r.getCrossSectionalArea());
	EXPECT_EQ(fuelMass, r.getFuelMass());
	EXPECT_EQ(dryMass, r.getDryMass());

	//the variables thrust and specificImpulse are stored in the engine object which is created in the rocket constructor
}

TEST(Rocket, updateMass)
{
	Rocket r = createRocket();
	float deltaTime = 0.7; //seconds

	float thrust = 25000*9.81;
	float specificImpulse = 250;
	float fuelMass = 7000;

	//rocket fuel flow rate is thrust/specificImpulse. After updateMass is called the fuel mass should be reduced
	float fuelFlowRate = thrust/specificImpulse; //per second
	float fuelUsedThisTimeStep = fuelFlowRate * deltaTime;
	r.updateMass(deltaTime);
	float extpectedFuelMass = fuelMass - fuelUsedThisTimeStep;
	EXPECT_EQ(extpectedFuelMass, r.getFuelMass());
}

//rocket should not be able to update mass once fuel is depleted
TEST(Rocket, fuleDepleted)
{
	//v2 rocket specifications real values
	Vector3D position(0, 0, 0);
	Vector3D velocity(0, 0, 0);
	Vector3D acceleration(0, 0, 0);
	float dryMass = 5000;
	float fuelMass = 0; //fuel is depleted
	float thrust = 25000*9.81;
	float dragCoefficient = 0.15f;
	float crossSectionalArea = 15.0f;
	float specificImpulse = 250;
	float deltaTime = 0.5; //seconds

	//constructor
	Rocket r (position, velocity, acceleration, dryMass, fuelMass ,thrust, dragCoefficient, crossSectionalArea, specificImpulse);

	r.updateMass(deltaTime);
	EXPECT_EQ(fuelMass, r.getFuelMass());
}


TEST(Rocket, createsEngine)
{
	Rocket r = createRocket();

	float thrust = 25000*9.81;
	float specificImpulse = 250;

	//return values of the engine to determine if the engine was created correctly
	//these values are referenced from the engine object and are not stored in the rocket object
	EXPECT_EQ(thrust, r.getThrust());
	EXPECT_EQ(specificImpulse, r.getSpecificImpulse());
}

TEST(Rocket, setEngineAngle)
{
	Rocket r = createRocket();

	float xAngle = 2;
	float yAngle = 3;
	float zAngle = 0;

	Vector3D changedEngineAngle(xAngle, yAngle, zAngle); //rocket engines only have x and y axis control 


	r.setGimbalAngles(xAngle, yAngle, zAngle);
	Vector3D currentGimbalAngles = r.getGimbalAngles();

	EXPECT_EQ(changedEngineAngle.getX(), currentGimbalAngles.getX());
	EXPECT_EQ(changedEngineAngle.getY(), currentGimbalAngles.getY());
	EXPECT_EQ(changedEngineAngle.getZ(), currentGimbalAngles.getZ()); //should be 0 as rocket engines only have x and y axis control
}

TEST(Rocket, setgimbalAngleBeyondPositiveLimit)
{
	Rocket r = createRocket();

	float xAngle = 25;
	float yAngle = 25;
	float zAngle = 0;

	float xLimit = r.getMaxGimbalAngle();
	float yLimit = r.getMaxGimbalAngle();

	Vector3D changedEngineAngle(xAngle, yAngle, zAngle); //rocket engines only have x and y axis control
	
	r.setGimbalAngles(xAngle, yAngle, zAngle);
	Vector3D currentGimbalAngles = r.getGimbalAngles();

	EXPECT_EQ(xLimit, currentGimbalAngles.getX());
	EXPECT_EQ(yLimit, currentGimbalAngles.getY());
	EXPECT_EQ(changedEngineAngle.getZ(), currentGimbalAngles.getZ()); //should be 0 as rocket engines only have x and y axis control
}

TEST(Rocket, setGimalAngleBeyondNegativeLimit)
{
	Rocket r = createRocket();

	float xAngle = -25;
	float yAngle = -25;
	float zAngle = 0;
	
	float xLimit = -1 * r.rocketEngine->getMaxGimbalAngle();
	float yLimit = -1 * r.rocketEngine->getMaxGimbalAngle();

	Vector3D changedEngineAngle(xAngle, yAngle, zAngle); //rocket engines only have x and y axis control

	r.setGimbalAngles(xAngle, yAngle, zAngle);
	Vector3D currentGimbalAngles = r.getGimbalAngles();

	EXPECT_EQ(xLimit, currentGimbalAngles.getX());
	EXPECT_EQ(yLimit, currentGimbalAngles.getY());
	EXPECT_EQ(changedEngineAngle.getZ(), currentGimbalAngles.getZ()); //should be 0 as rocket engines only have x and y axis control
}

int main(int argc, char*argv[])
{
 testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

