#include "ctest.h"
#include <libgameoflife/generation.h>
#include <libgameoflife/settings.h>

CTEST(my_tree_test, test3)
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

    char namefile1[15] = "testgameoflife";
    char namefile2[5] = "tex";

    int result1 = reading_from_file(&array[0][0], &options, &namefile1[0]);
    int result2 = reading_from_file(&array[0][0], &options, &namefile2[0]);

    ASSERT_EQUAL(0, result1);
    ASSERT_EQUAL(-1, result2);
}
