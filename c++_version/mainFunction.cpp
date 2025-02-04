#include "mainFunction.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

void changeDoor(double counterLim, int RandValue) {
  int counter = 0;
  int doorDecider;
  int door[3];
  int notWinner[2];
  int decision;
  int randDoorHelper;
  int monteDoor;
  int winCount = 0;
  int lossCount = 0;
  double winPercent;
  double lossPercent;
  srand(RandValue);
  while (counter < counterLim) {
    doorDecider =
        rand() % 3; // There are 3 possibilites for which door the prize could
                    // be behind. We use a random function to decide which
                    // scenario this iteration of the loop will use.
    if (doorDecider == 0) {
      door[0] = 1;
      door[1] = 0;
      door[2] = 0;
      notWinner[0] =
          1; // assign notWinner the door numbers which do not have the prize
      notWinner[1] = 2;
    } else if (doorDecider == 1) {
      door[0] = 0;
      door[1] = 1;
      door[2] = 0;
      notWinner[0] =
          0; // assign notWinner the door numbers which do not have the prize
      notWinner[1] = 2;
    } else {
      door[0] = 0;
      door[1] = 0;
      door[2] = 1;
      notWinner[0] =
          0; // assign notWinner the door numbers which do not have the prize
      notWinner[1] = 1;
    }
    decision = rand() % 3; // The contestant randomly chooses a door.

    if (door[decision] == 1) {
      randDoorHelper = rand() % 2;
      decision =
          notWinner[randDoorHelper]; // Monte Hall decides which of the other
                                     // two doors to reveal. Contestant chooses
                                     // the other door.
    } else {
      for (int i = 0; i < 3;
           i++) { // iterating through the doors to find which door monte will
                  // reveal to the contestant and which door the contestant will
                  // change their decision to.
        if (door[i] == 0 && i != decision) {
          monteDoor = i;
        } else if (i != decision) {
          decision = i;
        }
      }
    }
    if (door[decision] == 1) { // data collection
      winCount++;
    } else {
      lossCount++;
    }
    counter++;
  } // End while
  winPercent = winCount / counterLim * 100.0;
  lossPercent = lossCount / counterLim * 100.0;
  std::cout << "The contestant won " << winPercent
            << "\% of the time by always changing their decision." << std::endl;
  std::cout << "The contestant lost " << lossPercent
            << "\% of the time by always changing their decision." << std::endl;
}

void keepDoor(double counterLim, int RandValue) {
  int counter = 0;
  int doorDecider;
  int door[3];
  int notWinner[2];
  int decision;
  int randDoorHelper;
  int monteDoor;
  int winCount = 0;
  int lossCount = 0;
  double winPercent;
  double lossPercent;

  srand(RandValue);
  while (counter < counterLim) {
    doorDecider =
        rand() % 3; // There are 3 possibilites for which door the prize could
                    // be behind. We use a random function to decide which
                    // scenario this iteration of the loop will use.
    if (doorDecider == 0) {
      door[0] = 1;
      door[1] = 0;
      door[2] = 0;
    } else if (doorDecider == 1) {
      door[0] = 0;
      door[1] = 1;
      door[2] = 0;
    } else {
      door[0] = 0;
      door[1] = 0;
      door[2] = 1;
    }
    decision = rand() % 3; // The contestant randomly chooses a door.

    if (door[decision] == 1) {
      winCount++;
    } else {
      lossCount++;
    }
    counter++;
  } // End While
  winPercent = winCount / counterLim * 100.0;
  lossPercent = lossCount / counterLim * 100.0;
  std::cout << "The contestant won " << winPercent
            << "\% of the time by never changing their decision." << std::endl;
  std::cout << "The contestant lost " << lossPercent
            << "\% of the time by never changing their decision." << std::endl;
}
