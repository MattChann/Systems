# Notes for Systems Level Programming Class

------------------------------------------------------------
### Monday, October 21, 2019

#### Stack Memory
- as a data structure
	- first in, last out
	- terminology: push, pop
- associated with function calls
- stores all normally declared variables (including pointers and structs), arrays, and function calls
- functions are pushed onto the stack in the order they are called, and popped off when completed
- when a function is popped off the stack, the staclk memory associated with it is released
- only **one** stack

#### Heap Memory
- stores dynamically allocated memory
	- **allocated at runtime**
- data will remain in the eap until it is manually released (or the program terminates)
	- hence no garbage collector like in Java


------------------------------------------------------------
### Friday, October 18, 2019

```c
struct login u = new_account(4190);
```
Order of operations when run:
1. allocates memory necessary for `u`
2. runs `new_account(4190)`
3. copies the values of the returned struct into space allocated for `u`
4. returned struct goes away and `u` persists because it is in the `main()` function

Using struct as a parameter vs. pointer:
- copies argument into parameter variable
- edits the copy
- only in scope of the function

------------------------------------------------------------
### Tuesday, October 15, 2019

#### `struct` - creates a new type that is a collection of values
```c
struct {int a; char x;} s;
```
- (kind of like objects, but not advised to think of it this way)
- in this example, `s` is a variable of type `struct {int a; char x;}`
- we use the `.` operator to access values inside a struct

		s.a = 10;
		s.x = '@';
- size of `struct` may not necessarily equal the sum of sizes of the values, might be a little more
- "anonymous" struct, no name
```c
struct foo {int a; char x;};
```
```c
struct foo {
	int a;
	char x;
};
```
- `foo` is a **prototype** for the `struct`

		struct foo s;
- gcc will appropriately copy values between same non-anonymous `struct`s
- common practice (in standard C libraries) to not `typedef` a `struct` because it hides stuff
- normally don't declare `struct`s in main, typically outside all functions
- can also declare `struct`s in header files
- `.` binds before `*`
- to access data from a `struct` pointer you would do:
```c
struct foo *p;
p = &s;
		
(*p).x;
		
p->x; //c shorthand for (*p).x
```

------------------------------------------------------------
### Thursday, October 10, 2019

[Mr.Zamansky and Hunter Daedalus Program Talk](https://zamansky.github.io/presentations/navigating-hs-to-college-in-tech/index.html)

------------------------------------------------------------
### Thursday, October 10, 2019

Google Mentorship Talk

------------------------------------------------------------
### Tuesday, October 8, 2019

#### makefiles
- used to make executable
- works for not only C
- Java Compiler and JVM do stuff for you, so it doesn't give you executables (gives machine code instead)
- good practices
	- separate compilations steps for each \*.c file
	- run
	- clean
- only recompiles modified files
- dependencies should only be one \*.c file and other header \*.h files
- example makefile:

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

- make will stop at first error

In `char *strncpy(char *dest, const char *src, size_t n);` what is the type `size_t`?

#### `typedef` - provides a new name for an existing data type
Usage:
```c
typedef real_type new_name;
```
Examples:
```c
typedef unsigned long size_t;
size_t x = 139; //x is really an unsigned long
```
Why?
- allows code to work on different machines (known as portability)
- defines appropriately for every machine
- technically: can `typedef` a `typedef`

------------------------------------------------------------
### Friday, October 4, 2019

#### Pointers
- variable type for storing memory addresses
    - unsigned integer type
- 8 bytes large

#### Pointers in Functions
- when used as parameter
    - pass by value
        - address copied into the parameter and points to the same thing
    - argument remains **unchanged**
    - parameter's memory allocated in space allocated for the associated function


#### Primitive Types
|Types  |Size    |
|-------|--------|
|char   |1 byte  |
|int    |4 bytes |
|short  |2 bytes |
|long   |8 bytes |
|float	|4 bytes |
|double |8 bytes |


#### CPU
- Instructions go in (in bits)
- Stuff happens in the middle
- Out comes the result
- 2GHz = 2 billion input/output cycles per second
    - Gets hot because electrical signals all go through the same pathway
- Reads bits instruction, all 64-bits **at once**
    - Cannot break up memory addresses
    - This is why a memory address can only be 8 bytes at most (8 * 8 = 64)

------------------------------------------------------------
### Thursday, October 3, 2019

#### Java
.java --> .class --> JVM --> OS --> Hardware


#### C
.c --> Executable --> OS --> Hardware


#### Protected Memory
- OS allocates memory for programs and keeps track
- Programs cannot access memory outside of their allocation
    - If the program tries to --> Segmentation Fault
 
------------------------------------------------------------
