// Stl
#include <cassert>
#include <iostream>

// Gtest
#include <gtest/gtest.h>

// Boost::sml
#include <boost/sml.hpp>

// build: pip install conan && mkdir build && cd build && conan install .. && cmake .. && make

namespace sml = boost::sml;

// Events
struct lala {};
struct stop {};

// States
struct Idle {};
struct Processing {};

//sml::state<class finished> Finished;

// // Guards
// const auto is_ack_valid = [](const ack&) { return true; };
// const auto is_fin_valid = [](const fin&) { return true; };

// // Actions
const auto send_fin = [] {};
const auto send_ack = [] {};


//Transition table
struct TestStateMachine {
    auto operator()() const {
	using namespace sml;
	return make_transition_table(
				     *state<Idle> + event<lala> = state<Processing>
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

    
TEST_F (SmlTests, shouldStartInIdleState) {
    ASSERT_TRUE(sm_.is(sml::state<Idle>));
}
    
TEST_F (SmlTests, shouldProcessEvent) {
    sm_.process_event(sml::event<lala>);
    ASSERT_TRUE(sm_.is(sml::state<Processing>));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// int main() {
//   using namespace sml;
  
//   sm<MyStateMachine> sm;
//   static_assert(1 == sizeof(sm), "sizeof(sm) != 1b");
//   assert(sm.is("established"_s));

//   sm.process_event(release{});
//   assert(sm.is("fin wait 1"_s));

//   sm.process_event(ack{});
//   assert(sm.is("fin wait 2"_s));

//   sm.process_event(fin{});
//   assert(sm.is("timed wait"_s));

//   sm.process_event(unexpected{});
  
//   sm.process_event(timeout{});
//   assert(sm.is(X));  // released
// }
