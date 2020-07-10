# copyright 2020 Bella Rose
# name : Bella Rose
# UW email : brose714@uw.edu

# define commands, flags, and dependencies
CXX = g++
CFLAGS += -g -Wall -std=c++11
HEADER = IntPair.h

ex9: ex9.o IntPair.o
	$(CXX) $(CFLAGS) -o ex9 ex9.o IntPair.o

%.o: %.cc $(HEADER)
	$(CXX) $(CFLAGS) -c $<

clean:
	rm -rf ex9 *.o *~
