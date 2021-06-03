#include <libgameoflife/life.c>
#include <libgameoflife/life.h>
#include <libgameoflife/settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int size = 15;
    settings options;
    options.width = size;
    options.height = size;
    char original[options.width][options.height];

    for (int i = 0; i < options.width; i++) {
        for (int j = 0; j < options.height; j++) {
            original[i][j] = 0;
        }
    }
    original[3][3] = 1;
    original[3][4] = 1;
    original[4][3] = 1;
    original[4][4] = 1;
    original[5][3] = 1;
    original[5][4] = 1;
    original[6][3] = 1;
    original[6][4] = 1;
    original[7][3] = 1;
    original[7][4] = 1;
    original[8][3] = 1;
    original[8][4] = 1;

    original[6][10] = 1;
    original[6][11] = 1;
    original[7][10] = 1;
    original[7][11] = 1;
    original[8][10] = 1;
    original[8][11] = 1;
    original[9][10] = 1;
    original[9][11] = 1;
    original[10][10] = 1;
    original[10][11] = 1;
    original[11][10] = 1;
    original[11][11] = 1;

    original[3][6] = 1;
    original[4][6] = 1;
    original[3][7] = 1;
    original[4][7] = 1;
    original[3][8] = 1;
    original[4][8] = 1;
    original[3][9] = 1;
    original[4][9] = 1;
    original[3][10] = 1;
    original[4][10] = 1;
    original[3][11] = 1;
    original[4][11] = 1;

    original[10][3] = 1;
    original[11][3] = 1;
    original[10][4] = 1;
    original[11][4] = 1;
    original[10][5] = 1;
    original[11][5] = 1;
    original[10][6] = 1;
    original[11][6] = 1;
    original[10][7] = 1;
    original[11][7] = 1;
    original[10][8] = 1;
    original[11][8] = 1;

    while (1) {
        system("clear"); // linux

        for (int i = 0; i < options.height; i++) {
            for (int j = 0; j < options.width; j++) {
                if (original[i][j] == 1)
                    printf("a%c", original[i][j]);
                else
                    printf(" ");
                printf(" ");
            }
            printf("\n");
        }
        life(&original[0][0], &options);
        usleep(500000);
    }
}
