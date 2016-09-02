CC = g++-5
CFLAGS = -Wall -c
LFLAGS = -Wall
STD = -std=c++14

all: firsttwenty secondtwenty

firsttwenty: p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 p15 p16 p17 p18 p19 p20
secondtwenty: p21 p22 p23 p24 p25

#
# FIRST TWENTY
#
p1: object_files/problem1.o
	$(CC) $(LFLAGS) object_files/problem1.o -o p1 $(STD)

object_files/problem1.o: solutions/problem1.cpp
	$(CC) $(CFLAGS) solutions/problem1.cpp $(STD)

p2: object_files/problem2.o
	$(CC) $(LFLAGS) object_files/problem2.o -o p2 $(STD)

object_files/problem2.o: solutions/problem2.cpp
	$(CC) $(CFLAGS) solutions/problem2.cpp $(STD)

p3: object_files/problem3.o
	$(CC) $(LFLAGS) object_files/problem3.o -o p3 $(STD)

object_files/problem3.o: solutions/problem3.cpp
	$(CC) $(CFLAGS) solutions/problem3.cpp $(STD)

p4: object_files/problem4.o
	$(CC) $(LFLAGS) object_files/problem4.o -o p4 $(STD)

object_files/problem4.o: solutions/problem4.cpp
	$(CC) $(CFLAGS) solutions/problem4.cpp $(STD)

p5: object_files/problem5.o
	$(CC) $(LFLAGS) object_files/problem5.o -o p5 $(STD)

object_files/problem5.o: solutions/problem5.cpp
	$(CC) $(CFLAGS) solutions/problem5.cpp $(STD)

p6: object_files/problem6.o
	$(CC) $(LFLAGS) object_files/problem6.o -o p6 $(STD)

object_files/problem6.o: solutions/problem6.cpp
	$(CC) $(CFLAGS) solutions/problem6.cpp $(STD)

p7: object_files/problem7.o
	$(CC) $(LFLAGS) object_files/problem7.o -o p7 $(STD)

object_files/problem7.o: solutions/problem7.cpp
	$(CC) $(CFLAGS) solutions/problem7.cpp $(STD)

p8: object_files/problem8.o
	$(CC) $(LFLAGS) object_files/problem8.o -o p8 $(STD)

object_files/problem8.o: solutions/problem8.cpp
	$(CC) $(CFLAGS) solutions/problem8.cpp $(STD)

p9: object_files/problem9.o
	$(CC) $(LFLAGS) object_files/problem9.o -o p9 $(STD)

object_files/problem9.o: solutions/problem9.cpp
	$(CC) $(CFLAGS) solutions/problem9.cpp $(STD)

p10: object_files/problem10.o
	$(CC) $(LFLAGS) object_files/problem10.o -o p10 $(STD)

object_files/problem10.o: solutions/problem10.cpp
	$(CC) $(CFLAGS) solutions/problem10.cpp $(STD)

p11: object_files/problem11.o
	$(CC) $(LFLAGS) object_files/problem11.o -o p11 $(STD)

object_files/problem11.o: solutions/problem11.cpp
	$(CC) $(CFLAGS) solutions/problem11.cpp $(STD)

p12: object_files/problem12.o
	$(CC) $(LFLAGS) object_files/problem12.o -o p12 $(STD)

object_files/problem12.o: solutions/problem12.cpp
	$(CC) $(CFLAGS) solutions/problem12.cpp $(STD)

p13: object_files/problem13.o
	$(CC) $(LFLAGS) object_files/problem13.o -o p13 $(STD)

object_files/problem13.o: solutions/problem13.cpp
	$(CC) $(CFLAGS) solutions/problem13.cpp $(STD)

p14: object_files/problem14.o
	$(CC) $(LFLAGS) object_files/problem14.o -o p14 $(STD)

object_files/problem14.o: solutions/problem14.cpp
	$(CC) $(CFLAGS) solutions/problem14.cpp $(STD)

p15: object_files/problem15.o
	$(CC) $(LFLAGS) object_files/problem15.o -o p15 $(STD)

object_files/problem15.o: solutions/problem15.cpp headers/bigint.h
	$(CC) $(CFLAGS) solutions/problem15.cpp $(STD)

p16: object_files/problem16.o
	$(CC) $(LFLAGS) object_files/problem16.o -o p16 $(STD)

object_files/problem16.o: solutions/problem16.cpp headers/bigint.h
	$(CC) $(CFLAGS) solutions/problem16.cpp $(STD)

p17: object_files/problem17.o
	$(CC) $(LFLAGS) object_files/problem17.o -o p17 $(STD)

object_files/problem17.o: solutions/problem17.cpp
	$(CC) $(CFLAGS) solutions/problem17.cpp $(STD)

p18: object_files/problem18.o
	$(CC) $(LFLAGS) object_files/problem18.o -o p18 $(STD)

object_files/problem18.o: solutions/problem18.cpp
	$(CC) $(CFLAGS) solutions/problem18.cpp $(STD)

p19: object_files/problem19.o
	$(CC) $(LFLAGS) object_files/problem19.o -o p19 $(STD)

object_files/problem19.o: solutions/problem19.cpp
	$(CC) $(CFLAGS) solutions/problem19.cpp $(STD)

p20: object_files/problem20.o
	$(CC) $(LFLAGS) object_files/problem20.o -o p20 $(STD)

object_files/problem20.o: solutions/problem20.cpp headers/bigint.h
	$(CC) $(CFLAGS) solutions/problem20.cpp $(STD)

#
# SECOND TWENTY
#
p21: object_files/problem21.o
	$(CC) $(LFLAGS) object_files/problem21.o -o p21 $(STD)

object_files/problem21.o: solutions/problem21.cpp
	$(CC) $(CFLAGS) solutions/problem21.cpp $(STD)

p22: object_files/problem22.o
	$(CC) $(LFLAGS) object_files/problem22.o -o p22 $(STD)

object_files/problem22.o: solutions/problem22.cpp
	$(CC) $(CFLAGS) solutions/problem22.cpp $(STD)

p23: object_files/problem23.o
	$(CC) $(LFLAGS) object_files/problem23.o -o p23 $(STD)

object_files/problem23.o: solutions/problem23.cpp
	$(CC) $(CFLAGS) solutions/problem23.cpp $(STD)

p24: object_files/problem24.o
	$(CC) $(LFLAGS) object_files/problem24.o -o p24 $(STD)

object_files/problem24.o: solutions/problem24.cpp
	$(CC) $(CFLAGS) solutions/problem24.cpp $(STD)

p25: object_files/problem25.o
	$(CC) $(LFLAGS) object_files/problem25.o -o p25 $(STD)

object_files/problem25.o: solutions/problem25.cpp headers/bigint.h
	$(CC) $(CFLAGS) solutions/problem25.cpp $(STD)



