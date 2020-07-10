# Copyright 2020 Bella Rose

CC = g++
CXXFLAG = -Wall -g -std=c++11

all: ex16

ex16: ex16.o network.o
	$(CC) $(CXXFLAG) -o ex16 ex16.o network.o

ex16.o: ex16.cc network.h
	$(CC) $(CXXFLAG) -c ex16.cc

network.o: network.cc network.h
	$(CC) $(CXXFLAG) -c network.cc


clean:
	rm -rf ex16 *.o *~ 

