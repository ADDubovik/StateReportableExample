#pragma once

#include "StateReportable/toFile/State.h"

#include <ostream>


class SomethingAsynchronousReportable
{
public:
  SomethingAsynchronousReportable() : m_state(State::init) {};
  ~SomethingAsynchronousReportable() = default;

  SomethingAsynchronousReportable(const SomethingAsynchronousReportable &) = delete;
  SomethingAsynchronousReportable(SomethingAsynchronousReportable &&) = default;

  SomethingAsynchronousReportable& operator=(const SomethingAsynchronousReportable &) = delete;
  SomethingAsynchronousReportable& operator=(SomethingAsynchronousReportable &&) = default;

  bool isFinished();

private:
  enum class State
  {
    init,
    preparing,
    working,
    finished
  };

  State nextStep(State state);

  StateReportable::toFile::State<State> m_state;

  friend std::ostream &operator<<(std::ostream &stream, const SomethingAsynchronousReportable::State state);
};


std::ostream &operator<<(std::ostream &stream, const SomethingAsynchronousReportable::State state);
