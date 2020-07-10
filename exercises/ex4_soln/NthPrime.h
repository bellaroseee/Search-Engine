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

#ifndef EX4_NTHPRIME_H_
#define EX4_NTHPRIME_H_

#include <stdint.h>  // for int64_t etc.

// Return the nth prime number; for example:
//
//   NthPrime(1) --> 2
//   NthPrime(2) --> 3
//   NthPrime(3) --> 5
//   NthPrime(4) --> 7
//   etc.
//
// n must be >0.
int64_t NthPrime(int16_t n);

#endif   // EX4_NTHPRIME_H_