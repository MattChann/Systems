# Work 03: Enlist Your C Skillz

This will be due **Monday (10/28) morning.**

Write a simple linked list program. You will need a define a node struct with the following data members:
- A piece of data (your choice)
- A pointer to the next node
- Here's an example of what the struct could look like:

        struct node { int i; struct node *next; };

Create the following functions:
- `void print_list(struct node *);`
    - Should take a pointer to a node struct and print out all of the data in the list
- `struct node * insert_front(struct node *, int);`
    - Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
    - The second argument should match whatever data you contain in your nodes.
    - Returns a pointer to the beginning of the list.
- `struct node * free_list(struct node *);`
    - Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).  
- `struct node * remove_node(struct node *front, int data);`
    - Remove the node containing data from the list pointed to by front.
    - If data is not in the list, nothing is changed.
    - Returns a pointer to the beginning of the list.
- Your list functions should be in a .c/.h library, with a separate .c file used for testing.              

Don't forget to test out these various functions to ensure they work correctly. (Just to be clear, when you run the program and get "Segmentation fault" that means it's not working.). Here is a sample run that shows things being tested:
```c
$ ./test_list 
Printing empty list:
[ ]
Adding #s 0-9 to list.
Printing list:
[ 9 8 7 6 5 4 3 2 1 0 ]
Removing 9:
[ 8 7 6 5 4 3 2 1 0 ]
Removing 4:
[ 8 7 6 5 3 2 1 0 ]
Removing 0:
[ 8 7 6 5 3 2 1 ]
Removing -1:
[ 8 7 6 5 3 2 1 ]
Freeing list.
freeing node: 8
freeing node: 7
freeing node: 6
freeing node: 5
freeing node: 3
freeing node: 2
freeing node: 1
Printing list:
[ ]
```

Github link:
https://github.com/mks65/list.git
