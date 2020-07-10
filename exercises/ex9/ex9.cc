/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <iostream>
#include <cstdlib>

#include "./IntPair.h"

using std::cout;
using std::endl;

// uses Get() and Set() to incremenet each of the two integers in intPair
void Test(IntPair intPair);

int main(int argc, char **argv) {
  // create instance of IntPair as an ordirary local variable
  IntPair p(0, 0);
  // calls Test() with the p
  Test(p);

  // determine if IntPair instance was passed by value or passed by reference
  int p_a, p_b;
  p.Get(&p_a, &p_b);
  if ((p_a != 0) || (p_b != 0)) {
    cout << "Is pass by refence\n" << endl;
  } else {
    cout << "Is pass by value" << endl;
  }

  return EXIT_SUCCESS;
}

void Test(IntPair intPair) {
  int a, b;

  intPair.Get(&a, &b);
  intPair.Set(a+1, b+1);
}
