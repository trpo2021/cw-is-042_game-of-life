#pragma once
#include <libgameoflife/settings.h>

int surch_nighbors(char* original, Settings* options, int i, int j);
void generational_change(
        char* original, int cell, char* future, int i, int j, int size);
void copy_world(char* original, char* future, Settings* options);
int cmp_world(char* original, char* future, Settings* options);
int life(char* original, Settings* options);
