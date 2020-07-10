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

#include <stdio.h>   // for printf, sscanf
#include <stdlib.h>  // for EXIT_SUCCESS / EXIT_FAILURE and exit
#include <stdint.h>  // for uint64_t
#include <string.h>  // for strtol

// Print out the usage of the program and exit.
void Usage(void);

// Return the nth fractional term in the Nilakantha series.
double NthNilakantha(int32_t n);

int main(int argc, char **argv) {
  // Make sure the user provided us with a command line argument
  // and exit if not.
  if (argc != 2)
    Usage();

  // Try to convert the command line argument to an integer >= 0
  // and exit if unable.
  char *arg_end;
  int num_terms = strtol(argv[1], &arg_end, 10);
  // NOTE: the return type of strtol is long, which can be larger than
  // the largest possible int. We'll ignore this case for this exercise.
  // NOTE: after strtol, arg_end now stores the pointer to the character
  // immediately after the last character successfully parsed as
  // integer.  Input is invalid if there are additional characters after
  // the integer or if the conversion failed (not an integer).
  if (arg_end != argv[1] + strlen(argv[1]) ||
      num_terms < 0) {
    Usage();
  }

  // Calculate and print the estimate.
  double estimate = 3.0;
  for (uint32_t i = 1; i<= num_terms; i++) {
    estimate += NthNilakantha(i);
  }
  printf("Our estimate of Pi is %.20f\n", estimate);

  // Quit.
  return EXIT_SUCCESS;
}

double NthNilakantha(int32_t n) {
  // Calculate the Nth term in the Nilantha series using the formula
  // given in the exercise description.
  double term = 4.0;
  term /= 2.0 * n;
  term /= 2.0 * n + 1.0;
  term /= 2.0 * n + 2.0;
  if (n % 2 == 0)
    term *= -1.0;

  return term;
}

void Usage(void) {
  fprintf(stderr,
          "usage: ./ex0 n, where n>=0.  Prints pi estimated " \
          "to n terms of the Nilakantha series.\n");
  exit(EXIT_FAILURE);
}
