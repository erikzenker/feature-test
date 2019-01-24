#include <gtest/gtest.h>
#include <boost/sml.hpp>

#include <string>

#include "src/SmFacade.h"

namespace sml = boost::sml;

namespace fsm {
// Events
    struct run {
    };
    struct stop {
        stop(const std::size_t& timeout) : timeout(timeout){}
        std::size_t timeout;
    };

// States
    struct Idle {
    };
    struct Running {
    };

// Guards
    const auto timeIsUp = [](const auto &event) { return event.timeout == 0; };

// Transition table
    struct TestStateMachine {
        auto operator()() const {
            using namespace sml;
            return make_transition_table(
                    //  Current State   + Event       [Guard] / Action = Next State
                    //------------------+------------------------------------------------//
                    *state<Idle> + event<run> = state<Running>,
                    //------------------+------------------------------------------------//
                    state<Running> + event<stop>[timeIsUp] = state<Idle>
                    //------------------+------------------------------------------------//
            );
        }
    };

}

using namespace fsm;

class SmlTests : public ::testing::Test { 
protected:
    void SetUp( ) { 

    }
    void TearDown( ) { 

    }
    sml::sm<TestStateMachine> m_sm;

};


TEST_F(SmlTests, should_start_in_idle_state) {
    ASSERT_TRUE(m_sm.is(sml::state<Idle>));
}

TEST_F(SmlTests, should_transit_to_running_state) {
    m_sm.process_event(run{});
    ASSERT_TRUE(m_sm.is(sml::state<Running>));
}

TEST_F(SmlTests, should_transit_to_idle) {
    m_sm.process_event(run{});
    m_sm.process_event(stop{0});
    ASSERT_TRUE(m_sm.is(sml::state<Idle>));
}

TEST_F(SmlTests, should_not_idle_when_timeout_not_up) {
    m_sm.process_event(run{});
    m_sm.process_event(stop{1000});
    ASSERT_TRUE(m_sm.is(sml::state<Running>));
}

class SmlFacadeTests : public ::testing::Test {
protected:
    void SetUp( ) {

    }
    void TearDown( ) {

    }

    SmFacade m_sm;

};

TEST_F(SmlFacadeTests, should_start_in_idle_state) {
    ASSERT_TRUE(m_sm.is(sml::state<fsm2::Idle>));
}

TEST_F(SmlFacadeTests, should_transit_to_running_state) {
    m_sm.run();
    ASSERT_TRUE(m_sm.is(sml::state<fsm2::Running>));
}

TEST_F(SmlFacadeTests, should_transit_to_idle) {
    m_sm.run();
    m_sm.stop(0);
    ASSERT_TRUE(m_sm.is(sml::state<fsm2::Idle>));
}

TEST_F(SmlFacadeTests, should_not_idle_when_timeout_not_up) {
    m_sm.run();
    m_sm.stop(1000);
    ASSERT_TRUE(m_sm.is(sml::state<fsm2::Running>));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
