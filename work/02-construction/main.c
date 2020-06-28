#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main() {
    printf("=======Testing Generating and Printing Example Student=======\n");
    struct StuyStudent student = exampleStudent();
    struct StuyStudent *pStudent = &student;
    structPrint(pStudent);

    printf("\n=======Testing Changing Values of Example Student=======\n");
    printf("Expecting: Rick, -1/100, and -1...\n");
    changeStudent(pStudent, "Rick", -1, -1); // since the generated values can never be negative we know if we really changed the values
    structPrint(pStudent);

    return 0;
}