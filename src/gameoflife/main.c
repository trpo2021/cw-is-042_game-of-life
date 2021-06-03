#include <libgameoflife/life.c>
#include <libgameoflife/life.h>
#include <libgameoflife/menu.h>
#include <libgameoflife/output.c>
#include <libgameoflife/output.h>
#include <libgameoflife/settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    Settings settings;
    settings.width = 30;
    settings.height = 30;
    settings.speed = 2;
}
