/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <stdio.h>     /* printf */
#include <stdlib.h>    /* atoll, exit */
#include <stdint.h>    /* uint64_t */
#include <ctype.h>     /* isdigit */

//returns the Pi estimate
double Nilakantha(uint64_t);

int main (int argc, char* argv[]) {
  double pi;
  long long int n;

  if (argc != 2) {
    printf("Please provide the nth term for Nilakantha series estimation.\n");
    exit(EXIT_FAILURE);
  }

  //accepts negative value, maximum is 9 * 10^18 something
  n = atoll(argv[1]); 
  if (n < 0) {
    printf("the number entered must be greater than or equal to 0.\n");
    exit(EXIT_FAILURE);
  }
  //maximum value of signed 64 bit integer
  if (n > 0x7FFFFFFFFFFFFFFF) { 
    printf("the valye is out of range.");
    exit(EXIT_FAILURE);
  }

  pi = Nilakantha(n);
  
  printf("Our estimate of pi is %.20f\n", pi);
  return EXIT_SUCCESS; //or return 0; doesn't matter because same exit code
}


double Nilakantha(uint64_t n) {
  double pi, term; //starting from the 0th term
  pi = 3.0; 
  term = 0.0;
  //i is unsigned integer of width 64 bits (8 bytes)
  //calculating the term with term formula of Nilakantha infinite series
  for(uint64_t i=1; i<=n; i++) { 
    term = ( 4.0 / (2.0*i * (2.0*i + 1) * (2.0*i + 2.0)));
    if (i % 2 == 0) {
      term *= -1.0;
    }
    pi += term;
  }
  return pi;
}


//did not check whether user only inputs number (no characters)
