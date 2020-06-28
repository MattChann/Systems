struct StuyStudent {
    char *name;
    int mentalStability;
    int visitsToFerrys;
};

struct StuyStudent exampleStudent();
void structPrint(struct StuyStudent *student);
void changeStudent(struct StuyStudent *student, char *newName, int newStability, int newVisitAmount);