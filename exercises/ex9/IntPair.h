/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#ifndef _INTPAIR_H_
#define _INTPAIR_H_

class IntPair {
 public:
  // a class constructor that accept two integers and store them in
  // private instance variable
  IntPair(int a, int b);

  // Returns the two integers through output parameters
  void Get(int *a, int *b);

  // sets the two integers
  void Set(int a, int b);

 private:
  int a_, b_;
};

#endif  // _INTPAIR_H_
