#include "life.h"
#include <libgameoflife/settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Counting neighbors
int surch_nighbors(char* original, Settings* options, int i, int j)
{
    int cell = 0;
    if ((j - 1) >= 0) {
        if (*(original + i * options->width + (j - 1)) == 1)
            cell++; // mid left
        if ((i - 1) >= 0)
            if (*(original + (i - 1) * options->width + (j - 1)) == 1)
                cell++; // up left
        if ((i + 1) < options->height)
            if (*(original + (i + 1) * options->width + (j - 1)) == 1)
                cell++; // down left
    }
    if ((j + 1) < options->width) {
        if (*(original + i * options->width + (j + 1)) == 1)
            cell++; // mid right
        if ((i - 1) >= 0)
            if (*(original + (i - 1) * options->width + (j + 1)) == 1)
                cell++; // up right
        if ((i + 1) < options->height)
            if (*(original + (i + 1) * options->width + (j + 1)) == 1)
                cell++; // down right
    }
    if ((i - 1) >= 0) {
        if (*(original + (i - 1) * options->width + j) == 1)
            cell++; // up mid
    }
    if ((i + 1) < options->height) {
        if (*(original + (i + 1) * options->width + j) == 1)
            cell++; // down mid
    }
    return cell;
}

// Generation of a new generation
void generational_change(
        char* original, int cell, char* future, int i, int j, int size)
{
    if (*(original + i * size + j) == 1) {
        if ((cell == 2) || (cell == 3))
            *(future + i * size + j) = 1;
        else
            *(future + i * size + j) = 0;
    } else if (*(original + i * size + j) == 0) {
        if (cell == 3)
            *(future + i * size + j) = 1;
        else
            *(future + i * size + j) = 0;
    }
}

// Copying the game world. Used to save the previous generation
void copy_world(char* original, char* future, Settings* options)
{
    for (int i = 0; i < options->height; i++) {
        for (int j = 0; j < options->width; j++) {
            *(original + i * options->width + j)
                    = *(future + i * options->width + j);
        }
    }
}

// Comparison of current and previous generation game worlds
int cmp_world(char* original, char* future, Settings* options)
{
    for (int i = 0; i < options->height; i++) {
        for (int j = 0; j < options->width; j++) {
            if (*(original + i * options->width + j)
                != *(future + i * options->width + j))
                return -1;
        }
    }
    return 0;
}

int life(char* original, Settings* options)
{
    char future[options->height][options->width];
    for (int i = 0; i < options->height; i++) {
        for (int j = 0; j < options->width; j++) {
            future[i][j] = 0;
        }
    }

    for (int i = 0; i < options->height; i++) {
        for (int j = 0; j < options->width; j++) {
            int cell = surch_nighbors(original, options, i, j);
            generational_change(
                    original, cell, &future[0][0], i, j, options->width);
        }
    }
    if (cmp_world(original, &future[0][0], options) == 0)
        return -1;
    copy_world(original, &future[0][0], options);
    return 0;
}
