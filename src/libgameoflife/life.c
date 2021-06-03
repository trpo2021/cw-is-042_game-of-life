#include "life.h"
#include <libgameoflife/settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Подсчёт соседей
int surch_nighbors(char* original, settings* options, int i, int j)
{
    int cell = 0;
    if ((j - 1) >= 0) {
        if (*(original + i * options->width + (j - 1)) == 1)
            cell++; // mid left
        if ((i - 1) >= 0)
            if (*(original + (i - 1) * options->width + (j - 1)) == 1)
                cell++; // up left
        if ((i + 1) < options->width)
            if (*(original + (i + 1) * options->width + (j - 1)) == 1)
                cell++; // down left
    }
    if ((j + 1) < options->height) {
        if (*(original + i * options->width + (j + 1)) == 1)
            cell++; // mid right
        if ((i - 1) >= 0)
            if (*(original + (i - 1) * options->width + (j + 1)) == 1)
                cell++; // up right
        if ((i + 1) < options->width)
            if (*(original + (i + 1) * options->width + (j + 1)) == 1)
                cell++; // down right
    }
    if ((i - 1) >= 0) {
        if (*(original + (i - 1) * options->width + j) == 1)
            cell++; // up mid
    }
    if ((i + 1) < options->width) {
        if (*(original + (i + 1) * options->width + j) == 1)
            cell++; // down mid
    }
    return cell;
}
//Генерация нового покаления
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
// Копирование игрового мира. Используется для сохранения предыдущего поколения
void copy_world(char* original, char* future, settings* options)
{
    for (int i = 0; i < options->width; i++) {
        for (int j = 0; j < options->height; j++) {
            *(original + i * options->width + j)
                    = *(future + i * options->width + j);
        }
    }
}
// Сравнение игровых миров текущего и предыдущего поколения
int cmp_world(char* original, char* future, settings* options)
{
    for (int i = 0; i < options->width; i++) {
        for (int j = 0; j < options->height; j++) {
            if (*(original + i * options->width + j)
                != *(future + i * options->width + j))
                return -1;
        }
    }
    return 0;
}

void life(char* original, settings* options)
{
    char future[options->width][options->height];
    for (int i = 0; i < options->width; i++) {
        for (int j = 0; j < options->height; j++) {
            future[i][j] = 0;
        }
    }

    for (int i = 0; i < options->width; i++) {
        for (int j = 0; j < options->height; j++) {
            int cell = surch_nighbors(original, options, i, j);
            generational_change(
                    original, cell, &future[0][0], i, j, options->width);
        }
    }
    cmp_world(original ,&future[0][0], options );
    copy_world(original,&future[0][0], options );
}
