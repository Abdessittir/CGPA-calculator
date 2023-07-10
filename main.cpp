#include "student.h"

#include <random>
#include <iostream>

int generate_id() {
  static std::mt19937 mt {};
  std::uniform_int_distribution die{};
  return die(mt);
};

int main() {
  return 0;
}