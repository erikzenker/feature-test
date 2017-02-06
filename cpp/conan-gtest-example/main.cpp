#include <iostream>
#include <gtest/gtest.h>

class TestFixture : public ::testing::Test {
protected:
    void SetUp(){
	std::cout << "SetUp()" << std::endl;
    }

    void TearDown(){
	std::cout << "TearDown()" << std::endl;
    }
};



TEST_F (TestFixture, shouldCompile) {
    std::cout << "shouldCompile" << std::endl;
    ASSERT_TRUE(true);
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
