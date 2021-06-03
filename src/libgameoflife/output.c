#include "output.h"
#include <libgameoflife/settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char c = 'o';

void output(char* original, settings* options)
{
    system("clear");

    for (int i = 0; i < options->height; i++) {
        for (int j = 0; j < options->width; j++) {
            if (*(original + i * options->height + j) == 1)
                printf("%c", c);
            else
                printf(" ");
            printf(" ");
        }
        printf("\n");
    }

    usleep((1 / options->speed) * 1000000);
}
