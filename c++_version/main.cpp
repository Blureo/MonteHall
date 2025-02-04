#include "functions.hpp"
#include "mainFunction.hpp"
#include <cstdlib>
#include <iostream>
#include <string.h>

int main() {
  double counterLim;
  int tempCounter;
  int randValue;

  begin();

  std::cout << "Enter a random seed: ";
  randValue = integerInput();
  srand(randValue);

  std::cout
      << "Enter how many Monte Carlo cycles you'd like to run: "; // Monte Carlo
                                                                  // is not
                                                                  // related to
                                                                  // Monte Hall.
  tempCounter = integerInput();
  counterLim = tempCounter;

  changeDoor(counterLim, randValue);
  std::cout << "\n\n";
  starbar();
  std::cout << "\n\n";

  keepDoor(counterLim, randValue);

  return 0;
}
