#include <boost/sml.hpp>

using namespace boost::sml;

namespace fsm2 {
// Events
    struct run {
    };

    struct stop {
        stop(const std::size_t &timeout) : timeout(timeout) {}

        std::size_t timeout;
    };

// States
    struct Idle {
    };
    struct Running {
    };

// Guards
    const auto timeIsUp = [](const auto &event) { return event.timeout == 0; };

    struct TestStateMachine {
        auto operator()() const {
            return make_transition_table(
                    //  Current State   + Event       [Guard] / Action = Next State
                    //------------------+------------------------------------------------//
                    *state<Idle> + event < run > = state<Running>,
                    //------------------+------------------------------------------------//
                    state<Running> + event < stop >[timeIsUp] = state<Idle>
            //------------------+------------------------------------------------//
            );
        }
    };

} // namespace

class SmFacade {
private:
  // Transition table

public:
  template <typename State> bool is(State state) {
    return m_delegate.is(state);
  }

  void run() { return m_delegate.process_event(fsm2::run{}); }

  void stop(const size_t &timeout) {
    return m_delegate.process_event(fsm2::stop{timeout});
  }

private:
  sm<fsm2::TestStateMachine> m_delegate;
};