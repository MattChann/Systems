ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: control.c write.c
	$(CC) -o control control.c
	$(CC) -o write write.c

clean:
	rm write
	rm control
	rm *~