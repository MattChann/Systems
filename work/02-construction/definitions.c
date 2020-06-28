#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

struct StuyStudent exampleStudent() {
    char *exampleNames[] = {"Kazi", "Michael", "Eric", "Ray", "Ace Ventura", "Shaggy", "Jo"};
    
    struct StuyStudent student;
    struct StuyStudent *pStudent = &student;

    srand(time(NULL));
    pStudent -> name = exampleNames[rand() % 6];
    pStudent -> mentalStability = (rand() % 101);
    pStudent -> visitsToFerrys = (rand() % 1000001);
    return student;
}

void structPrint(struct StuyStudent *student) {
    printf("|%s\n", student -> name);
    printf("|-------\n");
    printf("|Mental Stability Level: %d/100\n", student -> mentalStability);
    printf("|Amount of Visits to Ferry's: %d\n", student -> visitsToFerrys);
}

void changeStudent(struct StuyStudent *student, char *newName, int newStability, int newVisitAmount) {
    student -> name = newName;
    student -> mentalStability = newStability;
    student -> visitsToFerrys = newVisitAmount;
}