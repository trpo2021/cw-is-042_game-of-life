#include <libgameoflife/generation.h>
#include <stdio.h>
#include <stdlib.h>

void first_gen(char* field, Settings* settings)
{
    reading_from_file(field, settings);
}

int reading_from_file(char* array, Settings* settings)
{
    char* namefile = "firstgeneration.txt";
    FILE* fileofgeneration;
    if ((fileofgeneration = fopen(namefile, "r")) == NULL) {
        printf("Couldn't open the file\n");
        return -1;
    }
    char element;
    int i = 0;
    int j = 0;

    for (i = 0; i < settings->height; i++) {
        for (j = 0; j < settings->width; j++) {
            element = fgetc(fileofgeneration);
            if (element == '\n') {
                i++;
                j = 0;
                continue;
            }
            if (element == ' ')
                *(array + i * settings->width + j) = 0;
            else if (element == 'o')
                *(array + i * settings->width + j) = 1;
        }
    }
    fclose(fileofgeneration);
    return 0;
}
