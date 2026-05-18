#include <stdio.h>

#include "../include/student.h"
#include "../include/log.h"


void addStudent(struct Student students[], int *count) {

    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter student name: ");
    scanf("%49s", students[*count].name);

    printf("Enter student surname: ");
    scanf("%49s", students[*count].surname);

    (*count)++;

    printf("Student added successfully.\n");
}

void displayStudents(struct Student students[], int count) {

    int i;

    for (i = 0; i < count; i++) {

        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Surname: %s\n", students[i].surname);
    }
}

void saveStudentsToCSV(struct Student students[], int count) {

    FILE *file = fopen("data/students.csv", "w");

    int i;

    for (i = 0; i < count; i++) {

        fprintf(file, "%d,%s,%s\n",
                students[i].id,
                students[i].name,
                students[i].surname);
    }

    fclose(file);

    printf("Students saved successfully.\n");
}

void loadStudentsFromCSV(struct Student students[], int *count) {

    FILE *file = fopen("data/students.csv", "r");

    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%49s",
                  &students[*count].id,
                  students[*count].name,
                  students[*count].surname) == 3) {

        (*count)++;
    }

    fclose(file);

    printf("Students loaded successfully.\n");
}