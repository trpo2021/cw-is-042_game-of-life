#include "ctest.h"
#include <libgameoflife/generation.h>
#include <libgameoflife/settings.h>

CTEST(unit_test, random_gen)
{
    Settings options;
    options.height = 5;
    options.width = 5;
    int size = options.height * options.width;

    char array [size];

    random_gen(&array[0], &options);

    for (int i = 0; i < size; i++)
		ASSERT_INTERVAL(0, 1, array[i]);
}