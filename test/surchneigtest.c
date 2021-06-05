#include "ctest.h"
#include <libgameoflife/life.h>
#include <libgameoflife/settings.h>

CTEST(my_first_test, test1)
{
    Settings options;
    options.width = 5;
    options.height = 5;

    char array[options.width][options.height];
    for (int i = 0; i < options.height; i++) {
        for (int j = 0; j < options.width; j++) {
            array[i][j] = 0;
        }
    }

    int i = 2;
    int j = 2;

    int result = surch_nighbors(&array[0][0], &options, i, j);

    ASSERT_INTERVAL(0, 8, result);
}
