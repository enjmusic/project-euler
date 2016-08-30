CC = g++-5
CFLAGS = -Wall -c
LFLAGS = -Wall
STD = -std=c++14

all: p1 p2 p3

p1: problem1.o
	$(CC) $(LFLAGS) problem1.o -o p1 $(STD)

problem1.o: problem1.cpp
	$(CC) $(CFLAGS) problem1.cpp $(STD)

p2: problem2.o
	$(CC) $(LFLAGS) problem2.o -o p2 $(STD)

problem2.o: problem2.cpp
	$(CC) $(CFLAGS) problem2.cpp $(STD)

p3: problem3.o
	$(CC) $(LFLAGS) problem3.o -o p3 $(STD)

problem3.o: problem3.cpp
	$(CC) $(CFLAGS) problem3.cpp $(STD)