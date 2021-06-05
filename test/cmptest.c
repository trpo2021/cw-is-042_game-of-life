#include "ctest.h"
#include <libgameoflife/life.h>
#include <libgameoflife/settings.h>

CTEST(unit_test, cmp_world)
{
    Settings options;
    options.width = 5;
    options.height = 5;

    char array1[options.width][options.height];
    char array2[options.width][options.height];
    char array3[options.width][options.height];
    for (int i = 0; i < options.height; i++) {
        for (int j = 0; j < options.width; j++) {
            array1[i][j] = 0;
            array2[i][j] = 1;
            array3[i][j] = 0;
        }
    }

    int result1 = cmp_world(&array1[0][0], &array2[0][0], &options);
    int result2 = cmp_world(&array1[0][0], &array3[0][0], &options);

    ASSERT_EQUAL(-1, result1);
    ASSERT_EQUAL(0, result2);
}
