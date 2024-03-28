#include <criterion/criterion.h>
#include <string.h>
#include <stddef.h>

size_t my_strlen(char const *s);

Test(my_strlen, basic)
{
    char const *s = "Hello world!";
    cr_assert(my_strlen(s) == strlen(s));
}

Test(my_strlen, one)
{
    char const *s = "H";
    cr_assert(my_strlen(s) == strlen(s));
}

Test(my_strlen, lol)
{
    char const *s = "Hello world!          zeozaejozajeoz \t\toizjeiezojroiezr";
    cr_assert(my_strlen(s) == strlen(s));
}
