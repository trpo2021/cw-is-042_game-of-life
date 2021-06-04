#pragma once
#include <libgameoflife/settings.h>

int first_gen(char* field, Settings* settings, int num_gen);
int reading_from_file(char* array, Settings* settings, char* namefile);
int random_gen(char* array, Settings* settings);
