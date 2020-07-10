/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "./NthPrime.h"

int main(int argc, char** argv) {
  printf("The 1st prime number is %" PRId64 ".\n", NthPrime(1));
  printf("The 7th prime number is %" PRId64 ".\n", NthPrime(7));
  return EXIT_SUCCESS;
}
