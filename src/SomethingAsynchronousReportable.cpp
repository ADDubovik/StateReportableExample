#include "SomethingAsynchronousReportable.h"

#include <cstdlib>


SomethingAsynchronousReportable::State SomethingAsynchronousReportable::nextStep(State state)
{
  return static_cast<State>(static_cast<int>(state) + 1);
}


bool SomethingAsynchronousReportable::isFinished()
{
  if ( (rand() & 0xff) == 0 )
    m_state = nextStep(m_state);

  return m_state == State::finished;
}


std::ostream &operator<<(std::ostream &stream, const SomethingAsynchronousReportable::State state)
{
  switch (state)
  {
    case SomethingAsynchronousReportable::State::init: return stream << "init"; break;
    case SomethingAsynchronousReportable::State::preparing: return stream << "preparing"; break;
    case SomethingAsynchronousReportable::State::working: return stream << "working"; break;
    case SomethingAsynchronousReportable::State::finished: return stream << "finished"; break;
    default : return stream << "unknown";
  };
}
