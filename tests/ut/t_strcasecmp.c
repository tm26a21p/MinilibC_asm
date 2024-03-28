#include <criterion/criterion.h>
#include <string.h>

int my_strcasecmp(char const *s1, char const *s2);

Test(my_strcasecmp, less)
{
    char const *s1 = "hello world";
    char const *s2 = "LOL";

    int x, y;
    cr_assert((x = my_strcasecmp(s1, s2)) == (y = strcasecmp(s1, s2)), "%d == %d\n", x, y);
}

Test(my_strcasecmp, equal)
{
    char const *s1 = "hello world";
    char const *s2 = "HELLO WORLD";

    int x, y;
    cr_assert((x = my_strcasecmp(s1, s2)) == (y = strcasecmp(s1, s2)), "%d == %d\n", x, y);
}

Test(my_strcasecmp, greater)
{
    char const *s1 = "hello world";
    char const *s2 = "HELadef";

    int x, y;
    cr_assert((x = my_strcasecmp(s1, s2)) == (y = strcasecmp(s1, s2)), "%d == %d\n", x, y);
}

Test(my_strcasecmp, bite)
{
    char const *s1 = "";
    char const *s2 = "HELadef";

    int x, y;
    cr_assert((x = my_strcasecmp(s1, s2)) == (y = strcasecmp(s1, s2)), "%d == %d\n", x, y);
}

Test(my_strcasecmp, bite2)
{
    char const *s1 = "";
    char const *s2 = "hELadef";

    int x, y;
    cr_assert((x = my_strcasecmp(s1, s2)) == (y = strcasecmp(s1, s2)), "%d == %d\n", x, y);
}
