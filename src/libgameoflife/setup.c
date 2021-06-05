#include <libgameoflife/setup.h>

void setup(Settings* settings)
{
    settings->width = 20;
    settings->height = 20;
    settings->speed = 10;
}

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
    settings->width = 43;
    settings->height = 43;
    return 4;
}

int setup_x(Settings* settings)
{
    settings->width = 30;
    settings->height = 30;
    return 5;
}

int setup_r(Settings* settings)
{
    settings->width = 30;
    settings->height = 30;
    return 6;
}

int setup_pulsar(Settings* settings)
{
    settings->width = 20;
    settings->height = 20;
    return 7;
}

int setup_portraitor(Settings* settings)
{
    settings->width = 30;
    settings->height = 30;
    return 8;
}

int setup_eight(Settings* settings)
{
    settings->width = 20;
    settings->height = 20;
    return 9;
}