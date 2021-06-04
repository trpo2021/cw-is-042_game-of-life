#include <libgameoflife/generation.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void first_gen(char* field, Settings* settings, int num_gen)
{
    if (num_gen == 1)
        reading_from_file(field, settings);
    else if (num_gen == 2)
        random_gen(field, settings);
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

int random_gen(char* array, Settings* settings)
{
    int max = 1, min = 0;
    srand(time(NULL));
    for (int i = 0; i < settings->height * settings->width; i++) {
        array[i] = min + rand() % (max - min + 1);
    }
    return 0;
}
