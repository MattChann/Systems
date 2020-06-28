all: main.o definitions.o
	gcc -o program main.o definitions.o

main.o: main.c headers.h
	gcc -c main.c

definitions.o: definitions.c
	gcc -c definitions.c

run:
	./program

clean:
	rm *.o
	rm program