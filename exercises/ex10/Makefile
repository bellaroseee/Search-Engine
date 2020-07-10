# Copyright 2020 Bella Rose
# name : Bella Rose
# UW email : brose714@uw.edu

ex10: Vector.o ex10.o
	g++ -Wall -g -std=c++11 -o ex10 Vector.o ex10.o

Vector.o: Vector.h Vector.cc
	g++ -Wall -g -std=c++11 -c Vector.cc

ex10.o: Vector.h ex10.cc
	g++ -Wall -g -std=c++11 -c ex10.cc

clean: 
	rm -rf ex10 *.o *~
