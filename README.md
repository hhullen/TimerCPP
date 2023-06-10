# TimerCPP

Simple one-header library for measuring time in C++ code execution. C++ Timer.

## Classes definition
```c++
namespace hhullen {

class Timer {
 public:
  Timer();

  void Reset();
  DTime Elapsed();
  ...
};

}
```
```c++
namespace hhullen {

class DTime {
 public:
  DTime(const long long duration);

  long long InMs();
  long long InSec();
  int InMin();
  int InHours();
  int InDays();

  long long Ms();
  long int Sec();
  int Min();
  int Hours();
  int Days();

  std::string SMs(const unsigned char width = 3);
  std::string SSec();
  std::string SMin();
  std::string SHours();
  std::string SDays();
  ...
};

}
```

## Installation
It is one-header library. Just copy `timer.h` from `src` directory to your project and include it.
```c++
#include "../path_to_file/timer.h"
```

## Usage

```c++
#include <iostream>

#include "timer.h"

int main() {
  // Create Timer object. Note, timer starts at the moment
  hhullen::Timer timer;

  // Reset timer - start from 0 now
  timer.Reset();

  // Some code
  for (unsigned int i = 4'294'000'000; i != 0; ++i) {
    std::cout << i << "\n";
  }

  // Get elapsed time into DTime object
  hhullen::DTime dt = timer.Elapsed();

  // Next few format of elapsed time possible:
  // Methods In* return whole time converted to one or another measure
  // For example:
    // if 74 seconds passed
    // InMin() method returns 1
    // and InSec() method returns 74
  std::cout << dt.InDays() << ":" <<
               dt.InHours() << ":" <<
               dt.InMin() << ":" <<
               dt.InSec() << "." <<
               dt.InMs() << "\n";

  // This methods return values from formatted time line
  // For example:
    // if 74 seconds passed
    // Min() method returns 1
    // and Sec() method returns 14
  std::cout << dt.Days() << ":" <<
               dt.Hours() << ":" <<
               dt.Min() << ":" <<
               dt.Sec() << "." <<
               dt.Ms() << "\n";

  // Methods S* return also values from formatted time line but in string type
  // So, it can be concatenated to one string type variable
  std::string time = dt.SDays() + ":" +
                     dt.SHours() + ":" +
                     dt.SMin() + ":" +
                     dt.SSec() + "." +
                     dt.SMs();

  // then output elapsed time
  std::cout << time << "\n";
  return 0;
}
```
To build and run an example, run command `make example` in `src` directory. Then run `make clean` to remove executable example file.
