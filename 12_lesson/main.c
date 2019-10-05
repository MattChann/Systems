#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main() {
    int ARR_SIZE = 10;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("Problem 1\n");
    printf("Average: %f\n", average(array, ARR_SIZE));

    printf("\nProblem 2\n");
    int copyArray[10] = {};
    copyVal(array, copyArray, ARR_SIZE);
    printf("Resulting Array: [");
    int i;
    for(i=0; i<ARR_SIZE; i++) {
        printf("%d,", copyArray[i]);
    }
    printf("]\n");

    printf("\nProblem 2\n");
    char testStr[15] = "12345";
    printf("String: %s\n", testStr);
    printf("Length: %d\n", strLength(testStr));
    strcpy(testStr, "123456789");
    printf("String: %s\n", testStr);
    printf("Length: %d\n", strLength(testStr));

    return 0;
}