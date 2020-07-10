/*
  Copyright 2020 Bella Rose
  name: Bella Rose
  UW email: brose714@uw.edu
*/

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <string>

class Coordinate {
 public:
  virtual std::string ToString() const = 0;

  virtual ~Coordinate() {}
};

#endif  // COORDINATE_H_
