#include <stdio.h>

#include "log.h"

void writeLog(char message[]) {

    FILE *file = fopen("log.txt", "a");

    if (file == NULL) {
        return;
    }

    fprintf(file, "%s\n", message);

    fclose(file);
}
