#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

// Takes a pointer to a node struct and prints out all of the data in the list
void print_list(struct node *node) {
    printf("[");
    struct node *currentNode = node;
    for(; currentNode != NULL; currentNode = currentNode->next) {
        printf("%d,", currentNode->i);
    }
    printf("]\n");
}

// Takes a pointer to the existing list and the data to be added
// Creates a new node and puts it at the beginning of the list
// Returns a pointer to the beginning of the list.
struct node * insert_front(struct node *node, int value) {
    struct node *newNode;
    newNode = malloc(sizeof(struct node));

    newNode -> i = value;
    newNode -> next = node;
    return newNode;
}

// Takes a pointer to a list and then goes through the entire list freeing each node
// Returns a pointer to the beginning of the list (which should be NULL by then)
struct node * free_list(struct node *node) {
    while(node != NULL) {
        printf("Freeing Node: %d\n", node->i);

        struct node *nullifyNode = node;
        free(nullifyNode);
        nullifyNode = NULL;

        node = node->next;
    }
    return node;
}

// Removes the node containing data from the list pointed to by front
// If data is not in the list, nothing is changed
// Returns a pointer to the beginning of the list
struct node * remove_node(struct node *front, int data) {
    printf("Removing Node: %d\n", data);
    struct node *currentNode, sentinelNode;
    sentinelNode.next = front;
    for(currentNode=&sentinelNode; currentNode!=NULL; currentNode=currentNode->next) {
        if(currentNode->next == NULL) {
            currentNode->next = NULL;
        }
        else {
            if(currentNode->next->i == data) {
                struct node *nullifyNode = currentNode->next;
                free(nullifyNode);
                nullifyNode = NULL;
                currentNode->next = currentNode->next->next;
                return sentinelNode.next;
            }
        }
    }
    return front;
}