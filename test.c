#include <stdio.h>
#include <string.h>

#include "../include/test.h"
#include "../include/result.h"
#include "../include/log.h"

void startTest(struct Student students[], int studentCount,
               struct Question questions[], int questionCount) {

    int studentId;
    int i;
    int foundIndex = -1;
    int score = 0;
    char answer[100];

    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    if (questionCount == 0) {
        printf("No questions available.\n");
        return;
    }
    
    writeLog("Test started");

    printf("Enter student ID for the test: ");
    scanf("%d", &studentId);

    for (i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            foundIndex = i;
        }
    }

    if (foundIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\nStarting test for %s %s\n",
           students[foundIndex].name,
           students[foundIndex].surname);

    for (i = 0; i < questionCount; i++) {

        printf("\nQuestion %d\n", i + 1);
        printf("%s\n", questions[i].text);

        if (questions[i].type == 1) {
            printf("A. %s\n", questions[i].optionA);
            printf("B. %s\n", questions[i].optionB);
            printf("C. %s\n", questions[i].optionC);
            printf("D. %s\n", questions[i].optionD);
        }

        printf("Your answer: ");
        scanf("%99s", answer);

        if (strcmp(answer, questions[i].correctAnswer) == 0) {
            score++;
        }
    }

    printf("\nFinal score: %d/%d\n", score, questionCount);

    saveResult(students[foundIndex], score, questionCount);
}