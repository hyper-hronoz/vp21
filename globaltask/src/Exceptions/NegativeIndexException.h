#pragma once

#include "iostream"

class NegativeIndexException : public std::exception {
public:
  char *what() { return "Custom C++ Exception"; }
};
