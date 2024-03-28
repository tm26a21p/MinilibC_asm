#include <criterion/criterion.h>
#include <string.h>

char *my_rindex(char const *s, int c);

Test(my_rindex, basic)
{
    char const *s = "Hello world!...l";

    cr_assert(my_rindex(s, 'l') == rindex(s, 'l'));
    cr_assert(my_rindex(s, '.') == rindex(s, '.'));
}
Test(my_rindex, last)
{
    char const *s = "Hello world!...l";

    cr_assert(my_rindex(s, 'l') == rindex(s, 'l'));
}

Test(my_rindex, first)
{
    char const *s = "Hello world!...l";

    cr_assert(my_rindex(s, 'H') == rindex(s, 'H'));
}

Test(my_rindex, zero)
{
    char const *s = "Hello world!";

    cr_assert(my_rindex(s, 0) == rindex(s, 0));
}

Test(my_rindex, not_in_string)
{
    char const *s = "Hello world!";

    cr_assert(my_rindex(s, '+') == rindex(s, '+'));
}

Test(my_rindex, empty)
{
    char const *s = "";

    cr_assert(my_rindex(s, '+') == rindex(s, '+'));
}
