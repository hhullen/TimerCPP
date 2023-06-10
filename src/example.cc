
#include <iostream>

#include "timer.h"

int main() {
  // Create Timer object
  hhullen::Timer timer;

  // Start timer, but unnecessary because timer also starts when object created
  timer.Start();

  // Some code
  for (unsigned int i = 3'000'000'000; i != 0; ++i) {
    int a = 21, b = 42;
    a += b;
  }

  // Stop timer
  timer.Stop();

  // Get elapsed time into DTime object
  hhullen::DTime dt = timer.Elapsed();

  // Next few format of elapsed time possible:
  // Methods In* returns whole time converted to one or another measure
  // For example:
  // if 74 seconds passed
  // InMin() method returns 1
  // and InSec() method returns 74
  std::cout << "In* methonds:\n";
  std::cout << dt.InDays() << ":" << dt.InHours() << ":" << dt.InMin() << ":"
            << dt.InSec() << "." << dt.InMs() << "\n";

  // This methods returns values from formatted time line
  // For example:
  // if 74 seconds passed
  // Min() method returns 1
  // and Sec() method returns 14
  std::cout << "Common methonds:\n";
  std::cout << dt.Days() << ":" << dt.Hours() << ":" << dt.Min() << ":"
            << dt.Sec() << "." << dt.Ms() << "\n";

  // Methodt S* returns also values from formatted time line but in string type
  // So, it can be concatenated to one string type variable
  std::cout << "Common methonds returns string:\n";
  std::string time = dt.SDays() + ":" + dt.SHours() + ":" + dt.SMin() + ":" +
                     dt.SSec() + "." + dt.SMs(3);

  // then output elapsed time
  std::cout << time << "\n";
  return 0;
}