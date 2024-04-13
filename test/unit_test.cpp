#include <gtest/gtest.h>
#include "../Vector3D.h" 
#include "../Physicalobject.h"


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
	Vector3D v2 = v1 * 2;
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
}


int main(int argc, char*argv[])
{
 testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}


	
