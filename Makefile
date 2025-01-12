CFLAGS=-Wall -g

all:
	gcc $(CFLAGS) ex1.c -o ex1
	gcc $(CFLAGS) ex3.c -o ex3

clean:
	rm -f ex1
	rm -f ex3
