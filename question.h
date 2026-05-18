#ifndef QUESTION_H
#define QUESTION_H

#define MAX_QUESTIONS 100

typedef struct Question {
    int id;
    int type;
    char text[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer[100];
} Question;

void addQuestion(Question questions[], int *count);
void displayQuestions(Question questions[], int count);
void saveQuestions(Question questions[], int count);
void loadQuestions(Question questions[], int *count);

#endif