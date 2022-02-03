// Copyright (c) 2022 Ina Tolo All rights reserved.
//
// Created by: Ina Tolo
// Created on: Feb. 2, 2022
// This program uses a while loop to collect input
// from the user. It then calls a function calculate
// the average of the input.

#include <iostream>
#include <list>
#include <iomanip>

// this function calculates the smallest value in the array of elements
float CalcAverage(std::list<int> marks, float sum) {
  float average;

  if (marks.size() == 0) {
    average = 0;
    return average;
  } else {
    average = sum / marks.size();
    return average;
  }
}


// gets input from user and checks for invalid input
int main() {
  // declaring variables
  std::list<int> marksList;
  std::string tempMark;
  int markInt;
  float averageUser;
  float sum_float = 0;

  // display opening message
  std::cout << "This program will calculate the";
  std::cout << " average of all the user's marks.";
  std::cout << std::endl;
  std::cout << std::endl;

  while (tempMark != "-1") {
    std::cout << "Please enter a mark, or -1 to stop: ";
    std::cin >> tempMark;
    try {
      markInt = std::stoi(tempMark);
      if (markInt < -1) {
        std::cout << markInt << " is not between 0 and 100.";
        std::cout << std::endl;
        continue;
      }
      marksList.push_back(markInt);
      sum_float += markInt;
    } catch (std::invalid_argument) {
    // tells user did the input is not a number
    std::cout << tempMark << " is not a number.";
    std::cout << std::endl;
    }
  }

  // removes -1 from end of list
  marksList.pop_back();
  sum_float = sum_float + 1;
  std::cout << "" << std::endl;

  // assigns variable to function call
  averageUser = CalcAverage(marksList, sum_float);
  // displays results to the user
  std::cout << "For the list of marks: [";
  auto iter = marksList.begin();
  auto iterEnd = (++marksList.rbegin()).base();

  while (iter != marksList.end()) {
    markInt = *iter;
    if (iter == iterEnd) {
      std::cout << markInt << "]";
    } else {
      std::cout << markInt << ", ";
    }
    iter++;
  }

  std::cout << std::endl;
  std::cout << "The average is: " << std::fixed;
  std::cout << std::setprecision(2) << averageUser;
  std::cout << "%";
}
