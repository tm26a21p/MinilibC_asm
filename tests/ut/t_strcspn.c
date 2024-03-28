#include <criterion/criterion.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

size_t my_strcspn(char const *s, char const *rejected);

Test(my_strcspn, basic)
{
    char const *s = "Hello World";
    char const *r = "-'%* Wd";

    /* printf("cpsn : %ld\n", strcspn(s, r)); */
    /* printf("my cpsn : %ld\n", my_strcspn(s, r)); */
    cr_assert(my_strcspn(s, r) == strcspn(s, r));
}

Test(my_strcspn, nope)
{
    char const *s = "Hello World";
    char const *r = "-'%*";

    cr_assert(my_strcspn(s, r) == strcspn(s, r));
    cr_assert(my_strcspn(s, r) == strlen(s));
}
