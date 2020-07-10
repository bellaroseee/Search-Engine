/*
  Copyright 2020 Bella Rose
  name: Bella Rose
  UW email: brose714@uw.edu
*/

#include <string>
#include <cmath>
#include "Polar.h"

Polar::Polar() : r_(0.0), theta_(0.0) {}

Polar::Polar(double r, double theta) : r_(r), theta_(theta) {}

Polar::Polar(const Polar &other) : r_(other.r_), theta_(other.theta_) {}

Polar::~Polar() {}

double Polar::Distance(const Polar &other) const {
  return pow((pow(r_, 2) + pow(other.r_, 2) -
         2 * r_ * other.r_ * cos(theta_ - other.theta_))
         , 0.5);
}

std::string Polar::ToString() const {
  std::string ret = "Polar\nr: " + std::to_string(r_);
  ret += "\ntheta: " + std::to_string(theta_);
  return ret;
}
