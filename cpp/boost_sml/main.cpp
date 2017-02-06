#include <gtest/gtest.h>
#include <boost/sml.hpp>

#include <string>

namespace sml = boost::sml;

// Events
struct run {};

// States
struct Idle {};
struct Running {};

//Transition table
struct TestStateMachine {
    auto operator()() const {
	using namespace sml;
	return make_transition_table(
				     *state<Idle> + event<run> = state<Running>
				     );
    }
};

class SmlTests : public ::testing::Test { 
protected:
    void SetUp( ) { 

    }
    void TearDown( ) { 

    }
    sml::sm<TestStateMachine> sm_;
};

bool returnTrue(){
    return true;
}


TEST_F(SmlTests, shouldStartFsmInIdleState) {
    ASSERT_TRUE(returnTrue());    
    //    ASSERT_TRUE(sm_.is(sml::state<Idle>));
    ASSERT_TRUE(true == true);
    //    ASSERT_EQ("hi", "hello");
    std::string foo("foobar");
    std::string bar("foobar");
    ASSERT_STREQ(foo.c_str(), bar.c_str()); // working
    EXPECT_FALSE(false); // error
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
