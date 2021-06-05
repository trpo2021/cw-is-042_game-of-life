#include "ctest.h"
#include <libgameoflife/life.h>
#include <libgameoflife/settings.h>

CTEST(my_four_test, test4)
{
    Settings options;
    options.width = 5;
    options.height = 5;

    char array1[options.width][options.height];
    char array2[options.width][options.height];
    for (int i = 0; i < options.height; i++) {
        for (int j = 0; j < options.width; j++) {
            array1[i][j] = 0;
            array2[i][j] = 1;
        }
    }
    copy_world(&array1[0][0], &array2[0][0], &options);

    ASSERT_DATA(&array2[0][0], 25, &array1[0][0], 25);
}
