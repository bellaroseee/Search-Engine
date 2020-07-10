/*
  Copyright 2020 Bella Rose
  name: Bella Rose
  UW emai: brose714@uw.edu
*/

#include <string>
#include <cmath>
#include "Cartesian.h"

Cartesian::Cartesian() : x_(0.0), y_(0.0) {}

Cartesian::Cartesian(double x, double y) : x_(x), y_(y) {}

Cartesian::Cartesian(const Cartesian &other) : x_(other.x_) , y_(other.y_) {}

Cartesian::~Cartesian() {}

double Cartesian::Distance(const Cartesian &other) const {
  return pow((pow((x_ - other.x_), 2) + pow((y_ - other.y_), 2)), 0.5);
}

std::string Cartesian::ToString() const {
  std::string ret = "Cartesian\nx: " + std::to_string(x_) +  "\ny: ";
  ret += std::to_string(y_);
  return ret;
}
