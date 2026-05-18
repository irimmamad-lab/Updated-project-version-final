#include <stdio.h>

#include "../include/result.h"
#include "../include/log.h"

void saveResult(struct Student student, int score, int total) {

    FILE *file = fopen("results.txt", "a");

    if (file == NULL) {
        printf("Error opening results file.\n");
        return;
    }

    fprintf(file, "%d,%s,%s,%d/%d\n",
            student.id,
            student.name,
            student.surname,
            score,
            total);

    fclose(file);

    printf("Result saved successfully.\n");
    writeLog("Result saved");
}