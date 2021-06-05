#include <libgameoflife/setup.h>

int setup_galaxy(Settings* settings)
{
    settings->width = 20;
    settings->height = 20;
    return 2;
}

int setup_fish(Settings* settings)
{
    settings->width = 100;
    settings->height = 18;
    return 3;
}

int setup_gun(Settings* settings)
{
    settings->width = 50;
    settings->height = 50;
    return 4;
}

int setup_x(Settings* settings)
{
    settings->width = 30;
    settings->height = 30;
    return 5;
}