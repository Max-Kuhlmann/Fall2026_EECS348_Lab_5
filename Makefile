# This is a comment line
CC=g++
# CFLAGS will be the options passed to the compiler.
CFLAGS=-c -Wall
OBJECTS=Lab5.cpp
all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o prog

