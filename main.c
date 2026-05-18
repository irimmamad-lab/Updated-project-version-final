#include <stdio.h>
#include "student.h"
#include "question.h"
#include "test.h"

int main() {

    struct Student students[MAX_STUDENTS];
    struct Question questions[MAX_QUESTIONS];

    int studentCount = 0;
    int questionCount = 0;
    int choice;

    do {
        printf("\n===== QUIZ MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save Students to CSV\n");
        printf("4. Load Students from CSV\n");
        printf("5. Add Question\n");
        printf("6. Display Questions\n");
        printf("7. Save Questions\n");
        printf("8. Load Questions\n");
        printf("9. Start Test\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                displayStudents(students, studentCount);
                break;

            case 3:
                saveStudentsToCSV(students, studentCount);
                break;

            case 4:
                loadStudentsFromCSV(students, &studentCount);
                break;

            case 5:
                addQuestion(questions, &questionCount);
                break;

            case 6:
                displayQuestions(questions, questionCount);
                break;

            case 7:
                saveQuestions(questions, questionCount);
                break;

            case 8:
                loadQuestions(questions, &questionCount);
                break;

            case 9:
                startTest(students, studentCount, questions, questionCount);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
