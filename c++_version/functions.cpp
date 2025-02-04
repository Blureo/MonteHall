#include "functions.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

void starbar() {
  std::string x = "*********************************************";
  std::cout << x << x << std::endl;
  std::cout << x << x << std::endl;
}

void explain() {
  std::cout
      << "The Monte Hall Problem describes a scenario \nfrom the TV show "
         "\"Let's Make a Deal!\", which was hosted by Monte Hall."
      << "\nThe problem prompts a contestant with a choice of 3 doors. "
         "\nBehind 1 door is a prize; there is nothing of value behind the "
         "other 2 doors."
      << "\nThe contestant chooses a door (but doesn't open it). Monte Hall "
         "then opens a door without a prize (not the one you chose). \nHe "
         "then asks you whether or not you would like to change your choice."
      << "\n(You do not know what is behind the door you chose yet)"
      << "\nAt first glance, it seems like changing your answer does not "
         "change your odds of winning."
      << "\nHowever, statistics professionals have indicated this is false, "
         "\nas changing your answer increases your chances of winning the "
         "prize from approximately 33.3 percent to approximately 66.6 percent."
      << "\nThe goal of this simulation is to demonstrate that by changing "
         "your answer every time Monte Hall opens a wrong door, your chances "
         "of winning increase."
      << "\nThis program will further demonstrate that by keeping your "
         "choice, you only win 33.3 percent of the time, as opposed to 66.6 "
         "percent of the time if you change your answer."
      << std::endl;
}

void begin() {
  starbar();
  explain();
  starbar();
  std::cout << "\n\n";
}

int integerInput() {
  std::string inputStr;
  int userInput;

  while (true) {
    std::getline(std::cin, inputStr);
    std::stringstream ss(inputStr);
    if (ss >> userInput) {

      break;
    } else {
      std::cout << "Invalid input. Please enter an integer." << std::endl;
      std::cin.clear();
    }
  }
  std::cout << "You entered: " << userInput << std::endl;
  return userInput;
}