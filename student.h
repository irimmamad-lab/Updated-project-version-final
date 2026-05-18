#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct Student {
    int id;
    char name[50];
    char surname[50];
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void saveStudentsToCSV(Student students[], int count);
void loadStudentsFromCSV(Student students[], int *count);

#endif