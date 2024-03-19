CC = g++
CFLAGS = -std=c++11 -Wall

all: word_counter

word_counter: main.o word_counter.o
	$(CC) $(CFLAGS) -o word_counter main.o word_counter.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

word_counter.o: word_counter.cpp word_counter.h
	$(CC) $(CFLAGS) -c word_counter.cpp

clean:
	del -rf *.o word_counter
