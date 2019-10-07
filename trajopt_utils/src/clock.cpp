#include <trajopt_utils/macros.h>
TRAJOPT_IGNORE_WARNINGS_PUSH
//#include <sys/time.h>
//#include <time.h>
#include<chrono>
TRAJOPT_IGNORE_WARNINGS_POP

#include <trajopt_utils/clock.hpp>

namespace util
{
static std::chrono::steady_clock::time_point startTime;

/*
 * Starts the clock!  Call this once at the beginning of the program.
 * Calling again will reset the clock to 0;  but doing so is not
 * thread-safe if other threads may be calling GetClock(); (which
 * is thread-safe since it only reads values and calls thread-safe
 * functions in the kernel).
 */
// time in units of seconds since some time in the past
void StartClock()
{
  // determine start time
  startTime = std::chrono::steady_clock::now();
}

/*
 * Returns the current time since the call to StartClock();
 */
double GetClock()
{
  std::chrono::steady_clock::duration diff = std::chrono::steady_clock::now() - startTime;
  return (1e-6) * static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(diff).count());
}
}  // namespace util
