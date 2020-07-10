/*
  Copyright 2020 Bella Rose
  name: Bella Rose
  UW email: brose714@uw.edu
*/

#ifndef POLAR_H_
#define POLAR_H_

#include <string>
#include "Coordinate.h"

class Polar : public Coordinate {
 public:
  Polar();  // default constructor
  Polar(double r, double theta);  // constructor with 2 arguments
  Polar(const Polar &other);  // copy constructor
  virtual ~Polar();  // destructor

  double Distance(const Polar &other) const;
  std::string ToString() const override;

 private:
  double r_, theta_;
};

#endif  // POLAR_H_
