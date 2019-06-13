#include "SomethingAsynchronous.h"

#include <cstdlib>


SomethingAsynchronous::State SomethingAsynchronous::nextStep(State state)
{
  return static_cast<State>(static_cast<int>(state) + 1);
}


bool SomethingAsynchronous::isFinished()
{
  if ( (rand() & 0xff) == 0 )
    m_state = nextStep(m_state);

  return m_state == State::finished;
}
