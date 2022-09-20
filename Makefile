exec: main.o
	g++ main.o -o exec
test.o: test.c
	g++ -c main.cpp
clean:
	rm *.o exec 

