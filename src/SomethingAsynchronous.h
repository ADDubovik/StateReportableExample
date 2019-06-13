#pragma once

#include <ostream>


class SomethingAsynchronous
{
public:
  SomethingAsynchronous() : m_state(State::init) {};
  ~SomethingAsynchronous() = default;

  SomethingAsynchronous(const SomethingAsynchronous &) = delete;
  SomethingAsynchronous(SomethingAsynchronous &&) = default;

  SomethingAsynchronous& operator=(const SomethingAsynchronous &) = delete;
  SomethingAsynchronous& operator=(SomethingAsynchronous &&) = default;

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

  State m_state;
};
