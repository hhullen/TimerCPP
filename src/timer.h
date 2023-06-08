#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

#include <chrono>
#include <string>

namespace hhullen {

using Str = std::string;
using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;
using ElapsCast = std::chrono::duration_cast<std::chrono::milliseconds>;

const int kOneDay = 86400;
const int kOneHour = 3600;
const int kOneMinute = 60;

class DTime {
 public:
  DTime(long long duration) : elapsed_milliseconds_(0) {}
  long long Milliseconds();
  long int Seconds();
  int Minutes();
  int Hours();
  int Days();
  Str Formatted(const Str& format);

 private:
  long long elapsed_milliseconds_;
};

class Timer {
 public:
  Timer() : start_(Clock::now()), end_(Clock::now()) {}

  void Start() { start_ = Clock::now(); }

  void Stop() { end_ = Clock::now(); }

  DTime Elapsed() {
    long long elapded = ElapsCast(end_ - start_).count();
    return DTime(elapded);
  }

 private:
  TimePoint start_;
  TimePoint end_;
};

}  // namespace hhullen

#endif  // SRC_TIMER_H_