#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Coordinate.h"
#include "Cartesian.h"
#include "Polar.h"

int main(int argc, char** argv) {
  // TESTING CARTESIAN COORDINATES
  Cartesian c1;
  Cartesian c2(1, 1);
  Cartesian c3(c2);

  std::cout << "testing cartesian default constructor. a point of (0, 0) is created\nc1\n" << c1.ToString() << std::endl;

  std::cout << "testing cartesian constructor. a point of (1, 1) is created\nc2\n" << c2.ToString() << std::endl;

  std::cout << "testing cartesian copy constructor. a copy of point (1, 1) is created\nc2\n" << c3.ToString() << std::endl;

  std::cout << "testing the distance between 2 points.\nthe distance between c1 and c2 should be 1.414214\nthe distance between c2 and c3 should be 0." << std::endl;
  std::cout << "calculating distance between c1 and c2: " << std::to_string(c1.Distance(c2)) << std::endl;
  std::cout << "calculating distance between c2 and c1: " << std::to_string(c2.Distance(c1)) << std::endl;
  std::cout << "calculating distance between c2 and c3: " << std::to_string(c2.Distance(c3)) << std::endl;
  std::cout << "calcualting distance between c3 and c2: " << std::to_string(c3.Distance(c2)) << std::endl;


  // TESTING POLAR COORDINATES
  Polar p1;
  Polar p2(6, 60.0/180.0 * M_PI);
  Polar p3(p2);

  std::cout <<"\ntesting polar default constructor. a point of (0, 0) is created\n" << p1.ToString() << std::endl;

  std::cout <<"testing polar constructor. a point of (6, 1.0472) is created\n" << p2.ToString() << std::endl;

  std::cout <<"testing polar copy constructor. a copy of point (6. 1.0472) is created\n" << p3.ToString() << std::endl;

  std::cout << "testing the distance between 2 points.\nthe distance between p1 and p2 should be 6\nthe distance between p2 and p3 should be 0." << std::endl;
  std::cout << "calculating distance between p1 and p2: " << std::to_string(p1.Distance(p2)) << std::endl;
  std::cout << "calculating distance between c2 and c1: " << std::to_string(p2.Distance(p1)) << std::endl;
  std::cout << "calculating distance between c2 and c3: " << std::to_string(p2.Distance(p3)) << std::endl;
  std::cout << "calcualting distance between c3 and c2: " << std::to_string(p3.Distance(p2)) << std::endl;

  Polar p4(10, 10.0/180.0 * M_PI);
  Polar p5(20, 20.0/180.0 * M_PI);
    std::cout << "Calculating distance: " << std::to_string(p4.Distance(p5)) << std::endl;

  std::cout << "\nend of testing." << std::endl;
}
