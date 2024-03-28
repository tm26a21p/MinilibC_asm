#include <criterion/criterion.h>
#include <string.h>
#include <stdlib.h>

void *my_memset(void *dest, int val, size_t n);

Test(my_memset, basic)
{
    char my[13] = {0};
    char exp[13] = {0};

    my_memset(my, 'a', 12);
    memset(exp, 'a', 12);
    cr_assert_str_eq(my, exp);
}
