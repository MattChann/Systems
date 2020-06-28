#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double average(int *array, int size) {
    double sum = 0;
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