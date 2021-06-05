#include "ctest.h"
#include <libgameoflife/setup.h>
#include <libgameoflife/settings.h>

CTEST(unit_test, setup)
{
    Settings options;

    int width = 20;
    int height = 20;
    int speed = 10;

    setup(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(speed, options.speed);
}

CTEST(unit_test, setup_galaxy)
{
    Settings options;

    int width = 20;
    int height = 20;

    int result;

    result = setup_galaxy(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(2, result);
}

CTEST(unit_test, setup_fish)
{
    Settings options;

    int width = 100;
    int height = 18;

    int result;

    result = setup_fish(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(3, result);
}

CTEST(unit_test, setup_gun)
{
    Settings options;

    int width = 43;
    int height = 43;

    int result;

    result = setup_gun(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(4, result);
}

CTEST(unit_test, setup_x)
{
    Settings options;

    int width = 30;
    int height = 30;

    int result;

    result = setup_x(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(5, result);
}

CTEST(unit_test, setup_r)
{
    Settings options;

    int width = 30;
    int height = 30;

    int result;

    result = setup_r(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(6, result);
}

CTEST(unit_test, setup_pulsar)
{
    Settings options;

    int width = 20;
    int height = 20;

    int result;

    result = setup_pulsar(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(7, result);
}

CTEST(unit_test, setup_portraitor)
{
    Settings options;

    int width = 30;
    int height = 30;

    int result;

    result = setup_portraitor(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(8, result);
}

CTEST(unit_test, setup_eight)
{
    Settings options;

    int width = 20;
    int height = 20;

    int result;

    result = setup_eight(&options);

    ASSERT_EQUAL(width, options.width);
    ASSERT_EQUAL(height, options.height);
    ASSERT_EQUAL(9, result);
}