/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <inttypes.h>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// print out all integers that are factors of that integer.
// i.e. all the divisors of the integer
void PrintFactors(uint64_t i);

int main(int argc, char** argv) {
  // prompts the user for a positive integer
  uint64_t i;
  cout << "Which positive integer would you like me to factorize? ";
  cin >> i;

  // check for bogus input: non integer
  if (!cin) {
    cerr << "Invalid input. Please enter integer" << endl;
    return EXIT_FAILURE;
  }

  // check for bogus input: 0
  if (i == 0) {
    cerr << "Invalid input. Cannot factorize 0." << endl;
  }

  PrintFactors(i);
  return EXIT_SUCCESS;
}


void PrintFactors(uint64_t i) {
  for (uint64_t d = 1; d <= i; d++) {
    if (i%d == 0) {
      cout << d << (d == i ? '\n' : ' ');
    }
  }
  exit(EXIT_SUCCESS);
}
