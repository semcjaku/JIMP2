//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

bool checkPositiveRange(int value);

int Factorial(int value) {
    if (value == 0 || value == 1)
        return 1;
    if (checkPositiveRange(value))
        return value * Factorial(value - 1);
    if (value < 0)
        return value * Factorial(value + 1);
  return 0;
}

bool checkPositiveRange(int value) { return value > 1 && value < 13; }