#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main() {
    struct node *testNode;
    
    printf("Printing Empty List:\n");
    print_list(testNode);
    
    printf("\nAdding #s 0-9 to list\n");
    int i;
    for(i=0; i<=9; i++) {
        testNode = insert_front(testNode, i);
    }
    
    printf("Printing List:\n");
    print_list(testNode);

    printf("\nFreeing List:\n");
    testNode = free_list(testNode);

    printf("\nPrinting List:\n");
    print_list(testNode);

    return 0;
}