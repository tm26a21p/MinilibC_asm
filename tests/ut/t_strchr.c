#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>

char *my_strchr(char const *s, int c);

Test(my_strchr, basic)
{
    char const *s = "Hello world";


    cr_assert(my_strchr(s, 'w') == strchr(s, 'w'));
}

Test(my_strchr, nope)
{
    char const *s = "Hello world";

    cr_assert(my_strchr(s, '+') == strchr(s, '+'));
    cr_assert_null(my_strchr(s, '+'));
}

Test(my_strchr, last)
{
    char const *s = "Hello world";

    cr_assert(my_strchr(s, 'd') == strchr(s, 'd'));
}

Test(my_strchr, first)
{
    char const *s = "Hello world";

    cr_assert(my_strchr(s, 'H') == strchr(s, 'H'));
}

Test(my_strchr, empty)
{
    char const *s = "";

    cr_assert(my_strchr(s, 'd') == strchr(s, 'd'));
}

Test(my_strchr, multiple)
{
    char const *s = "ollll";

    cr_assert(my_strchr(s, 'l') == strchr(s, 'l'));
}

Test(my_strchr, zero)
{
    char const *s = "Hello world";
    /* char *t = my_strchr(s, 0); */

    cr_assert(my_strchr(s, 0) == strchr(s, 0));
}
