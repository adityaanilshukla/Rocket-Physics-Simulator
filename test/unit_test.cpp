#include <gtest/gtest.h>
#include "../Vector3D.h" 

TEST(Vector3D, DefaultConstructor)
{
	Vector3D v(0, 0, 0);
	EXPECT_EQ(0, v.getX());
	EXPECT_EQ(0, v.getY());
	EXPECT_EQ(0, v.getZ());
}



int main(int argc, char*argv[])
{
 testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}


	
