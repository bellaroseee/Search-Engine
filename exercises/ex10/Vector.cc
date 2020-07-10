/*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <iostream>

#include "Vector.h"

namespace vector333 {

  Vector::~Vector() {}

  Vector &Vector::operator=(const Vector &rhs) {
    if (this != &rhs) {
      this->x_ = rhs.x_;
      this->y_ = rhs.y_;
      this->z_ = rhs.z_;
    }
    return *this;
  }

  Vector &Vector::operator+=(const Vector &v) {
    this->x_ += v.x_;
    this->y_ += v.y_;
    this->z_ += v.z_;
    return *this;
  }

  Vector &Vector::operator-=(const Vector &v) {
    this->x_ -= v.x_;
    this->y_ -= v.y_;
    this->z_ -= v.z_;
    return *this;
  }

  Vector Vector::operator+(const Vector &v) {
    return Vector(x_ + v.x_, y_ + v.y_, z_ + v.z_);
  }

  Vector Vector::operator-(const Vector &v) {
    return Vector(x_ - v.x_, y_ - v.y_, z_ - v.z_);
  }

  float Vector::operator*(const Vector &v2) {
    return (x_*v2.x_ + y_*v2.y_ + z_*v2.z_);
  }

  Vector Vector::operator*(const double k) {
    return Vector(x_ * k, y_ * k, z_ * k);
  }

  std::ostream &operator<<(std::ostream &out, const Vector &v) {
    out << "(" << v.x_ << "," << v.y_ << "," << v.z_ << ")";
    return out;
  }

}  // namespace vector333
