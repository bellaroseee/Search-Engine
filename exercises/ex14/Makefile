ex14: ex14.o Polar.o Cartesian.o
	g++ -Wall -g -std=c++11 -o ex14 ex14.o Polar.o Cartesian.o

ex14.o: ex14.cc
	g++ -Wall -g -std=c++11 -c ex14.cc

Cartesian.o: Coordinate.h Cartesian.h Cartesian.cc 
	g++ -Wall -g -std=c++11 -c Cartesian.cc

Polar.o: Coordinate.h Polar.h Polar.cc
	g++ -Wall -g -std=c++11 -c Polar.cc

clean:
	rm -f ex14 *.o *~
