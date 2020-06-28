ifeq ($(DEBUG), true)
	CC = gcc -g
else 
	CC = gcc
endif

dependencies = library_methods.o list_methods.o

all: main.o
	$(CC) -o program main.o

main.o: main.c
	$(CC) -c main.c

val:
	valgrind --leak-check=yes --track-origins=yes ./program

run: 
	./program

clean:
	rm *.o
	rm output
	rm program