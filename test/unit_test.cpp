#include <gtest/gtest.h>
#include "../Vector3D.h" 
#include "../Physicalobject.h"
#include "../Rocket.h"


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

TEST(Rocket, constructor)
{
	//v2 rocket specifications real values
	Vector3D position(0, 0, 0);
	Vector3D velocity(0, 0, 0);
	Vector3D acceleration(0, 0, 0);
	float dryMass = 5000;
	float fuelMass = (1200-dryMass);
	float thrust = (25000*9.81f);
	float dragCoefficient = 0.15f;
	float crossSectionalArea = 15.0f;

	//constructor
	Rocket r (position, velocity, acceleration, dryMass, fuelMass ,thrust, dragCoefficient, crossSectionalArea);

}



int main(int argc, char*argv[])
{
 testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}


	
