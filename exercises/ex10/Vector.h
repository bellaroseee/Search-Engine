/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

namespace vector333 {

class Vector {
 public:
    // default constructor
    // initializes a Vector to (0,0,0)
  Vector(): x_(0.0), y_(0.0), z_(0.0) {}

    // constructor with 3 floats parameter
  Vector(const float x, const float y, const float z):
    x_(x), y_(y), z_(z) {}

    // copy constructor
  Vector(const Vector &v):
    x_(v.x_), y_(v.y_), z_(v.z_) {}

    // destructor
    ~Vector();

    // assignment =
    Vector &operator=(const Vector &rhs);

    // perform element-by-element addition or subtraction for
    // vector components
    // assignment u+=v
    Vector &operator+=(const Vector &v);
    // assignment u-=v
    Vector &operator-=(const Vector &v);

    // overload + and - operators
    // returns new Vectors that are the sum and difference of u and v
    Vector operator+(const Vector &v);
    Vector operator-(const Vector &v);

    // dot product
    float operator*(const Vector &v2);

    // scalar product
    Vector operator*(const double k);

    // define a stream output
    // write vector v to stream s as (a,b,c)
    friend std::ostream &operator<<(std::ostream &out, const Vector &v);

 private:
    // Vector is represented by 3 floats, giving the magnitudes
    // in the x, y and z directions
    float x_, y_, z_;
};  // class Vector

}  // namespace vector333

#endif  // _VECTOR_H_
