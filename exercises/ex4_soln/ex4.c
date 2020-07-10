/*
 * Copyright ©2020 Hal Perkins.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2020 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <stdio.h>        // for printf
#include <stdlib.h>       // for EXIT_SUCCESS, malloc, free
#include <inttypes.h>     // for PRId64

#include "./NthPrime.h"  // for NthPrime

int main(int argc, char **argv) {
  printf("The 5th prime is: %" PRId64 ".\n", NthPrime(5));
  printf("The 105th prime is: %" PRId64 ".\n", NthPrime(105));
  return EXIT_SUCCESS;
}