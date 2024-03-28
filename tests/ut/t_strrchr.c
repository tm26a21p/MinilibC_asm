#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>

char *my_strrchr(char const *s, int c);

Test(my_strrchr, basic)
{
    char const *s = "Hello world";

    /* char *m = my_strrchr(s, 'l'); */
    /* char *t = strrchr(s, 'l'); */
    /* printf("%s | %s\n", m, t); */
    cr_assert(my_strrchr(s, 'w') == strrchr(s, 'w'));
}

Test(my_strrchr, nope)
{
    char const *s = "Hello world";

    cr_assert(my_strrchr(s, '+') == strrchr(s, '+'));
    cr_assert_null(my_strrchr(s, '+'));
}

Test(my_strrchr, last)
{
    char const *s = "Hello world";

    cr_assert(my_strrchr(s, 'd') == strrchr(s, 'd'));
}

Test(my_strrchr, first)
{
    char const *s = "Hello world";

    cr_assert(my_strrchr(s, 'H') == strrchr(s, 'H'));
}

Test(my_strrchr, empty)
{
    char const *s = "";

    cr_assert(my_strrchr(s, 'd') == strrchr(s, 'd'));
}

Test(my_strrchr, multiple)
{
    char const *s = "ollll";

    /* char *t = my_strrchr(s, 'l'); */
    /* if (t) */
    /*     printf("%s\n", t); */
    /* else */
    /*     printf("NULL\n"); */
    cr_assert(my_strrchr(s, 'l') == strrchr(s, 'l'));
}

Test(my_strrchr, zero)
{
    char const *s = "Hello world";

    cr_assert(my_strrchr(s, 0) == strrchr(s, 0));
}
