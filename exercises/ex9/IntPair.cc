/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/


// implementationo of IntPair class in IntPair.h

#include "./IntPair.h"
#include <iostream>

IntPair::IntPair(int a, int b) {
  a_ = a;
  b_ = b;
}

void IntPair::Get(int *a, int *b) {
  *a = a_;
  *b = b_;
}

void IntPair::Set(int a, int b) {
  a_ = a;
  b_ = b;
}
