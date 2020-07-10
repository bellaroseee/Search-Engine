 /*
  Copyright 2020 Bella Rose
  name : Bella Rose
  UW email : brose714@uw.edu
*/

#include <iostream>
#include <cstdlib>
#include <vector>       // std::vector
#include <algorithm>    // std::sort

using namespace std;

// helper function
// read each input value
// detects conversion and EOF condiions
// returns a T from reading from stream
template <class T> T ReadValue(istream& in);

int main(int argc, char **argv) {
  // check for bogus imput
  if (argc != 1) {
    cerr << "invalid args," << endl;
    return EXIT_FAILURE;
  }

  // store the floats in std::vector
  vector<float> input;
  int i;

  // prompts user to type in 8 floats
  cout << "Input 8 floats:"  << endl;
  for (i = 0; i < 8; i++) {
    float f = ReadValue<float>(cin);
    input.push_back(f);
  }

  // sorts the vector using std::sort
  sort(input.begin(), input.end());

  // prints out the sorted vector
  cout << "Your sorted floats are:" << endl;
  for (i = 0; i < 8; i++) {
    cout << input[i] << endl;
  }

  return EXIT_SUCCESS;
}

template <class T> T ReadValue(istream& in) {
  T f;

  in >> f;   // cin >> f

  // using istream member function .good to check for errors
  if  (!cin.good()) {
    cerr << "error in reading input." << endl;
    exit(EXIT_FAILURE);
  }

  return f;
}
