#pragma once

#include <libgameoflife/settings.h>

int menu(Settings* settings);
int set_random(Settings* settings);
int change_size_field(Settings* settings);
int change_speed(Settings* settings);
int com_input(int size);
int check(int data, int size);
int shoose_shape(Settings* settings);