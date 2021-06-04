#include <libgameoflife/generation.c>
#include <libgameoflife/generation.h>
#include <libgameoflife/life.c>
#include <libgameoflife/life.h>
#include <libgameoflife/menu.c>
#include <libgameoflife/menu.h>
#include <libgameoflife/output.c>
#include <libgameoflife/output.h>
#include <libgameoflife/settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    Settings options;
    options.width = 20;
    options.height = 20;
    options.speed = 5;

    int res_menu;
    res_menu = menu(&options);
    if (res_menu == -1)
        return 0;

    char field[options.height][options.width];
    for (int i = 0; i < options.height; i++) {
        for (int j = 0; j < options.width; j++) {
            field[i][j] = 0;
        }
    }

    first_gen(&field[0][0], &options, res_menu);
    output(&field[0][0], &options);
    while (life(&field[0][0], &options) == 0)
        output(&field[0][0], &options);
}
