/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <iostream>
#include <sstream>

#include "./Vector.h"

using namespace vector333;
using namespace std;

int main(int argc, char **argv) {
  // TEST CONSTRUCTOR
  cout << "Testing Constuctors" << endl;
  Vector v1;
  cout << "Default constructor. Construct a (0,0,0) vector : "
       << v1 << endl;

  Vector v2(1, 2, 3);
  cout << "Constructor with 3 float parameter of 1, 2, and 3 : "
       << v2 << endl;

  Vector v3(v2);
  cout << "Copy constuctor. Copy the previous vector : "
       << v3 << endl;

  // TEST ASSIGNMENT =
  cout << "\nTesting Assignment =" << endl;
  Vector v(2, 2, 2);
  Vector u = v;
  cout << "Vector v is " << v << endl;
  cout << "u=v. Vector u should have the same value as vector v."
       << "\nVector u is " << u << endl;

  // TEST ASSIGNMENT += AND -=
  cout << "\nTesting Assignment += and -=" << endl;
  cout << "u+=v should be (4,4,4) and u-=v should be (2,2,2)" << endl;
  cout << "u+=v is " << (u += v) << endl;
  cout << "u-=v is " << (u -= v) << endl;

  // TEST OPERATOR + AND -
  cout << "\nTesting Operators + and -" << endl;
  cout << "u+v should be (4,4,4) and u-v should be (0,0,0)" << endl;
  cout << "u + v is " << (u+v) << endl;
  cout << "u - v is " << (u-v) << endl;

  // TESTING DOT PRODUCT AND SCALAR PRODUCT
  cout << "\nTesting dot product and scalar product." << endl;
  cout << "u*v should be 12" << endl;
  cout << "u*v is " << (u*v) << endl;
  cout << "u*4.0 should be (8,8,8)" << endl;
  cout << "u*4.0 is " << (u*4.0) << endl;

  cout <<"\nDone testing" << endl;

  return EXIT_SUCCESS;
}
