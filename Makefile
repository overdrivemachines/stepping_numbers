# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

stepping_numbers: stepping_numbers.o
	$(CC) $(CFLAGS) -o stepping_numbers stepping_numbers.o

stepping_numbers.o: stepping_numbers.cpp
	$(CC) $(CFLAGS) -c stepping_numbers.cpp

clean:
	rm -rf stepping_numbers stepping_numbers.o
