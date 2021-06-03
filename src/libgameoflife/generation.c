#include <libgameoflife/generation.h>
#include <stdio.h>
#include <stdlib.h>

char* first_gen(Settings* settings)
{
    char* field;
    field = malloc(sizeof(char) * settings->width * settings->height);
    reading_from_file(field, settings);
    return (field);
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
    while ((element = fgetc(fileofgeneration)) != EOF) {
        if ((element == 10) && (i < settings->height)) {
            i++;
            j = 0;
        } else if ((element == ' ') && (j < settings->width)) {
            *(array + i * settings->width + j) = 0;
            j++;
        } else {
            *(array + i * settings->width + j) = 1;
            j++;
        }
    }
    fclose(fileofgeneration);
    return 0;
}
