CC = g++
CFLAGS = -Wall -g

all: main

#tests.o: tests.cpp f_lab2_linkedlistsequence.h f_lab2_arraysequence.h
#	$(CC) $(CFLAFS) -c tests.cpp

main.o: main.cpp graph.h
	$(CC) $(CFLAGS) -c main.cpp

main: main.o
	$(CC) $(CFLAGS) -o main main.o

clean:
	rm -rf *.o main


#-0fast 
