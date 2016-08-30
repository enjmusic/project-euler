CC = g++-5
CFLAGS = -Wall -c
LFLAGS = -Wall
STD = -std=c++14

all: p1 p2 p3 p4 p5

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

p4: problem4.o
	$(CC) $(LFLAGS) problem4.o -o p4 $(STD)

problem4.o: problem4.cpp
	$(CC) $(CFLAGS) problem4.cpp $(STD)

p5: problem5.o
	$(CC) $(LFLAGS) problem5.o -o p5 $(STD)

problem5.o: problem5.cpp
	$(CC) $(CFLAGS) problem5.cpp $(STD)