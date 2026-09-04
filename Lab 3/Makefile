CC=gcc
CFLAGS=-g -Wall

all: wc map main

wc: main.c wc.c
	$(CC) $(CFLAGS) -o wc main.c wc.c

map: map.c
	$(CC) $(CFLAGS) -o map map.c

main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f wc map main *.o

