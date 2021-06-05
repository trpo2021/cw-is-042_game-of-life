#pragma once

#include <libgameoflife/settings.h>

int menu(Settings* settings);
int set_random(Settings* settings);
int change_size_field(Settings* settings);
int change_speed(Settings* settings);
int check(int size, int command);