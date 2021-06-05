#include "ctest.h"
#include <libgameoflife/menu.h>

CTEST(unit_test, check)
{
    int size = 100;
    int normal = 50;
    int upper = size ;
    int more = size + 1; 
    int lower = 1;
    int less = 0;
    
    int res_normal = 0;
    int res_upper = 0;  
    int res_more = 0;
    int res_lower = 0;
    int res_less = 0;

    res_normal = check(normal, size);
    res_upper = check(upper, size);
    res_more = check(more, size);
    res_lower = check(lower, size);
    res_less = check(less, size);

    ASSERT_EQUAL(0, res_normal);
    ASSERT_EQUAL(0, res_upper);
    ASSERT_EQUAL(-1, res_more);
    ASSERT_EQUAL(0, res_lower);
    ASSERT_EQUAL(-1, res_less);
}