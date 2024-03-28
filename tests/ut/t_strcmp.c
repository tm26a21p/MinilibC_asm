#include <criterion/criterion.h>
#include <string.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, less)
{
    char const *s1 = "hello world";
    char const *s2 = "lol";

    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
}

Test(my_strcmp, equal)
{
    char const *s1 = "hello world";
    char const *s2 = "hello world";

    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
}

Test(my_strcmp, greater)
{
    char const *s1 = "hello world";
    char const *s2 = "heladef";

    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
}
