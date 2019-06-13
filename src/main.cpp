#include "SomethingAsynchronousReportable.h"
#include "SomethingAsynchronous.h"

#include <thread>
#include <chrono>


int main()
{
  {
    SomethingAsynchronous something;

    while ( !something.isFinished() )
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  {
    SomethingAsynchronousReportable somethingReportable;

    while ( !somethingReportable.isFinished() )
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

	return 0;
}