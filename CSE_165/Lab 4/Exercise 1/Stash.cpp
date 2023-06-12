#include <string>
#include <iostream>
#include <vector>
#include "Stash.h"
#include <fstream>

const int increment = 100;

int main() {
  int N;
  std::cin >> N;

  Stash stash;
  stash.initialize(sizeof(double));
  for (int i = 0; i < N; i++) {
    double val;
    std::cin >> val;

    stash.add(&val);
  }
  std::cout << std::endl;
  for (int i = 0; i < stash.count(); i++) {
    double *p = (double *)stash.fetch(i);
    std::cout << *p << std::endl;
  }

  stash.cleanup();

  return 0;
}