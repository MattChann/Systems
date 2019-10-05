#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float average(int *array, int size);
int copyVal(int *arr1, int *arr2, int size);
int strLength(char *string);

int main() {
    int ARR_SIZE = 10;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("Problem 1\n");
    printf("Average: %f\n",average(array, ARR_SIZE));

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

float average(int *array, int size) {
    float sum = 0;
    int i;
    for(i=0; i<size; i++) {
        sum += array[i];
    }
    return sum/size;
}

int copyVal(int *arr1, int *arr2, int size) {
    int i;
    for(i=0; i<size; i++) {
        arr2[i] = arr1[i];
    }

    return 0;
}

int strLength(char *string) {
    int length = 0;
    char charToStr[2] = "";
    charToStr[0] = *string;
    while(strcmp(charToStr, "\0") != 0) {
        length++;
        string++;
        charToStr[0] = *string;
    }
    return length;
}