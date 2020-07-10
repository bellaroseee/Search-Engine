ex5: ex5.o Vector.o
	gcc -Wall -g -std=c11 -o ex5 ex5.o Vector.o

Vector.o: Vector.c
	gcc -Wall -g -std=c11 -c -o Vector.o Vector.c

ex5.o: ex5.c 
	gcc -Wall -g -std=c11 -c -o ex5.o ex5.c


clean: 
	rm -rf *.o *~ ex5
