#include <stdio.h>

#include "../include/question.h"
#include "../include/log.h"

void addQuestion(struct Question questions[], int *count) {

    if (*count >= MAX_QUESTIONS) {
        printf("Maximum number of questions reached.\n");
        return;
    }

    printf("Enter question ID: ");
    scanf("%d", &questions[*count].id);

    printf("Enter question type (1 = multiple choice, 2 = open answer): ");
    scanf("%d", &questions[*count].type);

    printf("Enter question text: ");
    scanf(" %199[^\n]", questions[*count].text);

    if (questions[*count].type == 1) {
        printf("Enter option A: ");
        scanf(" %99[^\n]", questions[*count].optionA);

        printf("Enter option B: ");
        scanf(" %99[^\n]", questions[*count].optionB);

        printf("Enter option C: ");
        scanf(" %99[^\n]", questions[*count].optionC);

        printf("Enter option D: ");
        scanf(" %99[^\n]", questions[*count].optionD);
    }

    printf("Enter correct answer: ");
    scanf(" %99[^\n]", questions[*count].correctAnswer);

    (*count)++;

    printf("Question added successfully.\n");
    writeLog("Question added");
}

void displayQuestions(struct Question questions[], int count) {

    int i;

    for (i = 0; i < count; i++) {
        printf("\nQuestion %d\n", i + 1);
        printf("ID: %d\n", questions[i].id);
        printf("Type: %d\n", questions[i].type);
        printf("Text: %s\n", questions[i].text);

        if (questions[i].type == 1) {
            printf("A: %s\n", questions[i].optionA);
            printf("B: %s\n", questions[i].optionB);
            printf("C: %s\n", questions[i].optionC);
            printf("D: %s\n", questions[i].optionD);
        }

        printf("Correct answer: %s\n", questions[i].correctAnswer);
    }
}

void saveQuestions(struct Question questions[], int count) {

    FILE *file = fopen("questions.csv", "w");
    int i;

    if (file == NULL) {
        printf("Error opening questions file.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(file, "%d,%d,%s,%s,%s,%s,%s,%s\n",
                questions[i].id,
                questions[i].type,
                questions[i].text,
                questions[i].optionA,
                questions[i].optionB,
                questions[i].optionC,
                questions[i].optionD,
                questions[i].correctAnswer);
    }

    fclose(file);

    printf("Questions saved successfully.\n");
    writeLog("Questions saved to file");
}

void loadQuestions(struct Question questions[], int *count) {

    FILE *file = fopen("questions.csv", "r");

    if (file == NULL) {
        printf("Questions file not found.\n");
        return;
    }

    *count = 0;

    while (fscanf(file,
                  "%d,%d,%199[^,],%99[^,],%99[^,],%99[^,],%99[^,],%99[^\n]\n",
                  &questions[*count].id,
                  &questions[*count].type,
                  questions[*count].text,
                  questions[*count].optionA,
                  questions[*count].optionB,
                  questions[*count].optionC,
                  questions[*count].optionD,
                  questions[*count].correctAnswer) == 8) {

        (*count)++;

        if (*count >= MAX_QUESTIONS) {
            break;
        }
    }

    fclose(file);

    printf("Questions loaded successfully.\n");
    writeLog("Questions loaded from file");
}