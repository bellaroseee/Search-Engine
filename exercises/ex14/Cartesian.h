/*
  Copyright 2020 Bella Rose
  name: Bella Rose
  UW email: brose714@uw.edu
*/

#ifndef CARTESIAN_H_
#define CARTESIAN_H_

#include <string>
#include "Coordinate.h"

class Cartesian : public Coordinate {
 public:
  Cartesian();   // default constructor
  Cartesian(double x, double y);  // constructor with 2 parameter
  Cartesian(const Cartesian &other);  // copy constructor
  virtual ~Cartesian();  // destructor

  double Distance(const Cartesian &other) const;
  std::string ToString() const override;

 private:
  double x_, y_;
};

#endif  // CARTESIAN_H_
