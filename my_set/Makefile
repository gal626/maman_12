CC = gcc
CFLAGS = -Wall -ansi -pedantic

all: my_set

my_set: my_set.o
	$(CC) $(CFLAGS) -o my_set my_set.o

my_set.o: my_set.c
	$(CC) $(CFLAGS) -c my_set.c

clean:
	rm -f my_set my_set.o

