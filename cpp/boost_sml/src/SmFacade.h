#include <boost/sml.hpp>

using namespace boost::sml;

namespace fsm2 {


    /**
     * Events
     */
    struct start {
    };
    struct startSucceed{
    };
    struct startFailed{
    };
    struct stop {
    };


    /**
     * States
     */
    struct Initial {
    };
    struct Starting {
    };
    struct Started {
    };
    struct Stopped {
    };

    /**
     * Guards
     */

    /**
     * Actions
     */
    auto doStart = [](auto, auto& sm, auto& deps, auto& subs) { sm.process_event(startSucceed{}, deps, subs);};


/**
 * State Machine
 */
    struct TestStateMachine {
        auto operator()() const {
            return make_transition_table(
            // clang-format off
            //  Current State   + Event                 [Guard] / Action  = Next State
            //------------------+------------------------------------------------------------//
            *state<Initial>   + event < start >                 / doStart = state<Starting>,
            //------------------+------------------------------------------------------------//
            state<Starting>   + event < startSucceed >                    = state<Started>,
            state<Starting>   + event < startFailed >                     = state<Stopped>,
            //------------------+------------------------------------------------------------//
            state<Started>    + event < stop >                            = state<Stopped>
            // clang-format on
            );

        }
    };

} // namespace

class SmFacade {
private:
public:
  template <typename State> bool is(State state) {
    return m_delegate.is(state);
  }

  void start() { return m_delegate.process_event(fsm2::start{}); }

  void stop() {
    return m_delegate.process_event(fsm2::stop{});
  }

private:
  sm<fsm2::TestStateMachine> m_delegate;
};