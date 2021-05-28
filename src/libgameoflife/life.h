#pragma once
#include <libgameoflife/settings.h>

int surch_nighbors(char* original, settings* options, int i, int j);
void generational_change(
        char* original, int cell, char* future, int i, int j, int size);
void copy_world(char* original, char* future, settings* options);
int cmp_world(char* original, char* future, settings* options);
void life(char* original, settings* options);