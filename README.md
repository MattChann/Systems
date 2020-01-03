# Work 08: Semaphone!

This will be due **Friday, 1/3**

Write a telephone style game! It will use a semaphore to control access to a file and shared memory. 

The main program should work as follows:
1. Print a message that it will check if resources are available.
2. When they are, display the last line added to the story (or none, if it is new).
3. Prompt the user to enter the next line
4. Update the story
5. quit

This game will require 2 files 
1. A control program
    - Take a command line argument to determine if it is creating or removing the resources or viewing the story.
    - If creating (**command line argument**: -c):
        - Should make the shared memory, semaphore and file (open the file with the truncate flag). 
        - Set any values that are needed.
    - If removing (**command line argument**: -r)
        - Remove the shared memory, the semaphore and the story.
        - Display the full contents of the story.
        - This should wait until the semaphore is available.
    - If viewing (**command line argument**: -v)
        - Output the contents of the story file. 
        - This mode does not need to interact with the semaphore
2. A main writing program
    - Will attempt to access the resources using the semaphore
        - Once in, it should display the last line added to the file (use shared memory to contain the size of the last line).
        - Prompt the use for the next line.
        - Once a new line is read, write that to the file, update the shared memory and then release the semaphore
3. You do not need a **run** target in your makefile

github link:
https://github.com/mks65/semaphone.git

Example Interactions:
```
$ ./control -c
semaphore created
shared memory created
file created

$ ./control -v
The story so far:

$ ./write 
trying to get in
Last addition: 
Your addition: A long time ago

$ ./write 
trying to get in
Last addition: A long time ago

Your addition: in a galaxy far, far away.

$ ./control -v
The story so far:
A long time ago
in a galaxy far, far away.

$ ./control -r
trying to get in
The story so far:
A long time ago
in a galaxy far, far away.

shared memory removed
file removed
semaphore removed
```
