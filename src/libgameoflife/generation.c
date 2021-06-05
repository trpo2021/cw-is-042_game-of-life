#include <libgameoflife/generation.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int first_gen(char* field, Settings* settings, int num_gen)
{
    char namefile[20] = "../shapes/";
    if (num_gen == 1)
        random_gen(field, settings);
    else if (num_gen == 2) {
        strcat(namefile, "galaxy");
    } else if (num_gen == 3) {
        strcat(namefile, "fish");
    } else if (num_gen == 4) {
        strcat(namefile, "gun");
    } else if (num_gen == 5) {
        strcat(namefile, "x");
    } else if (num_gen == 6) {
        strcat(namefile, "R-penta");
    } else if (num_gen == 7) {
        strcat(namefile, "pulsar");
    } else if (num_gen == 8) {
        strcat(namefile, "portraitor");
    } else if (num_gen == 9) {
        strcat(namefile, "eight");
    }

    return reading_from_file(field, settings, &namefile[0]);
}

int reading_from_file(char* array, Settings* settings, char* namefile)
{
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

void random_gen(char* array, Settings* settings)
{
    int max = 1, min = 0;
    srand(time(NULL));
    for (int i = 0; i < settings->height * settings->width; i++) {
        array[i] = min + rand() % (max - min + 1);
    }
}
