#include <gtest/gtest.h>
#include <boost/sml.hpp>

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


TEST_F(SmlTests, shouldStartFsmInIdleState) {
    ASSERT_TRUE(sm_.is(sml::state<Idle>));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
