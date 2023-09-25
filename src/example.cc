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
  std::cout << dt.InDays() << ":" << dt.InHours() << ":" << dt.InMin() << ":"
            << dt.InSec() << "." << dt.InMs() << "\n";

  // This methods return values from formatted time line
  // For example:
  // if 74 seconds passed
  // Min() method returns 1
  // and Sec() method returns 14
  std::cout << dt.Days() << ":" << dt.Hours() << ":" << dt.Min() << ":"
            << dt.Sec() << "." << dt.Ms() << "\n";

  // Methods S* return also values from formatted time line but in string type
  // So, it can be concatenated to one string type variable
  std::string time = dt.SDays() + ":" + dt.SHours() + ":" + dt.SMin() + ":" +
                     dt.SSec() + "." + dt.SMs();

  // then output elapsed time
  std::cout << time << "\n";
  return 0;
}