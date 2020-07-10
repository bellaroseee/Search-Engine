# Copyright 2020 Bella Rose

CC = g++
CXXFLAG = -Wall -g -std=c++11

all: ex15

ex15: ex15.o network.o
	$(CC) $(CXXFLAG) -o ex15 ex15.o network.o

ex15.o: ex15.cc network.h
	$(CC) $(CXXFLAG) -c ex15.cc

network.o: network.cc network.h
	$(CC) $(CXXFLAG) -c network.cc


clean:
	rm -rf ex15 *.o *~ 

