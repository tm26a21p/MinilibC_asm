#include <criterion/criterion.h>
#include <string.h>

char *my_strpbrk(char const *s, char const *accepted);

Test(my_strpbrk, basic)
{
    char const *s = "Hello world";
    char const *a = "321-'l";

    cr_assert(my_strpbrk(s, a) == strpbrk(s, a));
}

Test(my_strpbrk, nope)
{
    char const *s = "Hello world";
    char const *a = "nup";

    cr_assert(my_strpbrk(s, a) == strpbrk(s, a));
    cr_assert_null(my_strpbrk(s, a));
}
