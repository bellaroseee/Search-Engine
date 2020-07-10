/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include "./NthPrime.h"

// boolean flag. True if number is a prime. False otherwise
bool IsPrime(int64_t n);

// implementation of function prototype from Header file
// algorithm from programiz.com
int64_t NthPrime(int16_t n) {
  // check for negative input
  if (n < 0) {
    printf("invalid argument passed. n should start from 1.\n");
    exit(EXIT_FAILURE);
  }
  // check for n = 0
  if (n == 0) {
    printf("0th prime is called. n should start from 1.\n");
    exit(EXIT_FAILURE);
  }

  // the first prime number starts from 2
  for (int64_t i = 2; i <= INT64_MAX; i++) {
    if (IsPrime(i)) {
      if (n == 1) { return i; }
      n--;
    }
  }

  // this is the case when nth prime is not found.
  // which is when n exceeds INT64_MAX
  printf("n is greater than %" PRIx64 "\n", INT64_MAX);
  exit(EXIT_FAILURE);
}

// n is not a prime if it's divisible by 2
bool IsPrime(int64_t n) {
  if (n == 1) {
    return false;
  }

  if (n == 2) {
    return true;
  }

  // iterate through odd values, incrementing by 2
  // stop at n/2 because if its 0, n is prime
  for (int64_t i = 3; i <= n/2; i+=2) {
      // condition for non prime number
      if (n%i == 0) { return false; }
    }
    return true;
  }
