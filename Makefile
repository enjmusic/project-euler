CC = g++-5
CFLAGS = -Wall -c
LFLAGS = -Wall
STD = -std=c++14

all: p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 p15 p16 p17

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

p6: problem6.o
	$(CC) $(LFLAGS) problem6.o -o p6 $(STD)

problem6.o: problem6.cpp
	$(CC) $(CFLAGS) problem6.cpp $(STD)

p7: problem7.o
	$(CC) $(LFLAGS) problem7.o -o p7 $(STD)

problem7.o: problem7.cpp
	$(CC) $(CFLAGS) problem7.cpp $(STD)

p8: problem8.o
	$(CC) $(LFLAGS) problem8.o -o p8 $(STD)

problem8.o: problem8.cpp
	$(CC) $(CFLAGS) problem8.cpp $(STD)

p9: problem9.o
	$(CC) $(LFLAGS) problem9.o -o p9 $(STD)

problem9.o: problem9.cpp
	$(CC) $(CFLAGS) problem9.cpp $(STD)

p10: problem10.o
	$(CC) $(LFLAGS) problem10.o -o p10 $(STD)

problem10.o: problem10.cpp
	$(CC) $(CFLAGS) problem10.cpp $(STD)

p11: problem11.o
	$(CC) $(LFLAGS) problem11.o -o p11 $(STD)

problem11.o: problem11.cpp
	$(CC) $(CFLAGS) problem11.cpp $(STD)

p12: problem12.o
	$(CC) $(LFLAGS) problem12.o -o p12 $(STD)

problem12.o: problem12.cpp
	$(CC) $(CFLAGS) problem12.cpp $(STD)

p13: problem13.o
	$(CC) $(LFLAGS) problem13.o -o p13 $(STD)

problem13.o: problem13.cpp
	$(CC) $(CFLAGS) problem13.cpp $(STD)

p14: problem14.o
	$(CC) $(LFLAGS) problem14.o -o p14 $(STD)

problem14.o: problem14.cpp
	$(CC) $(CFLAGS) problem14.cpp $(STD)

p15: problem15.o
	$(CC) $(LFLAGS) problem15.o -o p15 $(STD)

problem15.o: problem15.cpp bigint.h
	$(CC) $(CFLAGS) problem15.cpp $(STD)

p16: problem16.o
	$(CC) $(LFLAGS) problem16.o -o p16 $(STD)

problem16.o: problem16.cpp bigint.h
	$(CC) $(CFLAGS) problem16.cpp $(STD)

p17: problem17.o
	$(CC) $(LFLAGS) problem17.o -o p17 $(STD)

problem17.o: problem17.cpp bigint.h
	$(CC) $(CFLAGS) problem17.cpp $(STD)



