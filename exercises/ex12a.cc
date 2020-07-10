/*
  Copyright 2020 Bella Rose
  name : bella rose
  UW email : brose714@uw.edu
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "wrong running args\n" << endl;
    return EXIT_FAILURE;
  }

  map<string, int> tab;
  // open file
  ifstream f(argv[1]);
  if (!f.is_open()) {
    cerr << "Unable to open file" << endl;
    return EXIT_FAILURE;
  }

  string token;
  while (f >> token) {
    if (tab.find(token) == tab.end()) {
      tab[token] = 1;
    } else {
      tab[token] += 1;
    }
  }

  for (auto a : tab) {
    cout << a.first << " " << a.second << endl;
  }

  f.close();
  return EXIT_SUCCESS;
}

