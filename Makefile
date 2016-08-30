OBJS_P1 = problem1.o
OBJS_P2 = problem2.o

CC = g++-5
CFLAGS = -Wall -c -g
LFLAGS = -Wall -g
STD = -std=c++14

all: p1 p2

p1: $(OBJS_P1)
	$(CC) $(LFLAGS) $(OBJS_P1) -o p1 $(STD)

problem1.o: problem1.cpp
	$(CC) $(CFLAGS) problem1.cpp $(STD)

p2: $(OBJS_P2)
	$(CC) $(LFLAGS) $(OBJS_P2) -o p2 $(STD)

problem2.o: problem2.cpp
	$(CC) $(CFLAGS) problem2.cpp $(STD)