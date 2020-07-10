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

#include <stdio.h>    // for printf
#include <stdlib.h>   // for exit, EXIT_SUCCESS
#include <stdbool.h>  // for bool
#include <stdint.h>   // for int64_t etc.

#include "./NthPrime.h"

// Return true if "factor" is a factor of num, otherwise false.
static bool IsFactor(int64_t factor, int64_t num);

// Return true if "num" is prime, otherwise false.
static bool IsPrime(int64_t num);

int64_t NthPrime(int16_t n) {
  // error check: terminate program if n is 0
  if (n == 0) {
    fprintf(stderr, "error: NthPrime(0) called!\n");
    exit(EXIT_FAILURE);
  }

  int64_t checknext = 2;
  // Advance checknext and count prime values as they are discovered.
  // When the nth one is found, return it.
  while (1) {
    // If checknext is prime, return it if it is the requested one,
    // otherwise decrease count of primes remaining to be discovered
    if (IsPrime(checknext)) {
      if (n == 1) {
        return checknext;
      }
      n--;
    }

    // terminate program if we've reached the largest positive integer
    if (checknext == INT64_MAX) {
      fprintf(stderr, "Hit the largest int64_t, aborting.\n");
      exit(EXIT_FAILURE);
    }

    // advance to next trial number
    checknext++;
  }

  // Should never get here.
  return 0;
}


static bool IsFactor(int64_t factor, int64_t num) {
  if (num % factor == 0UL)
    return true;
  return false;
}

static bool IsPrime(int64_t num) {
  for (int64_t i = 2L; i < num; i++) {
    if (IsFactor(i, num))
      return false;
  }
  return true;
}