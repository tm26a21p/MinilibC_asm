#include <criterion/criterion.h>
#include <string.h>
#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, size_t n);

Test(my_strncmp, less)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello world";

    cr_assert(my_strncmp(s1, s2, 12) == strncmp(s1, s2, 12));
}

Test(my_strncmp, less_bigsz)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello world";

    cr_assert(my_strncmp(s1, s2, 200) == strncmp(s1, s2, 200));
}

Test(my_strncmp, less_smallsz)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello world";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

Test(my_strncmp, equal)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello World";

    cr_assert(my_strncmp(s1, s2, 12) == strncmp(s1, s2, 12));
}

Test(my_strncmp, equal_bigsz)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello World";

    cr_assert(my_strncmp(s1, s2, 200) == strncmp(s1, s2, 200));
}

Test(my_strncmp, equal_smallsz)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello World";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

Test(my_strncmp, greater)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello Aorld";

    cr_assert(my_strncmp(s1, s2, 12) == strncmp(s1, s2, 12));
}

Test(my_strncmp, greater_bigsz)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello Aorld";

    cr_assert(my_strncmp(s1, s2, 200) == strncmp(s1, s2, 200));
}

Test(my_strncmp, greater_smallsz)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello Aorld";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

Test(my_strncmp, zero)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello Aorld";

    cr_assert(my_strncmp(s1, s2, 0) == strncmp(s1, s2, 0));
}

Test(my_strncmp, totally_diff)
{
    char const *s1 = "Hello World";
    char const *s2 = "yob itch nigga";

    cr_assert(my_strncmp(s1, s2, 100) == strncmp(s1, s2, 100));
}


Test(my_strncmp, partial_match)
{
    char const *s1 = "Hello World";
    char const *s2 = "Hello lol World";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

Test(my_strncmp, zero_s1)
{
    char const *s1 = "";
    char const *s2 = "Hello lol World";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

Test(my_strncmp, zero_s2)
{
    char const *s1 = "Hello World";
    char const *s2 = "";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

Test(my_strncmp, wtf)
{
    char const *s1 = "lutpat\
at suscipit in, accumsan at massa. Donec eros felis, interdum ac dolor vel, fi\
nibus accumsan orci. Integer at suscipit arcu. Proin pellentesque felis id orc\
i commodo fermentum. Suspendisse ultricies dolor ipsum, vitae pulvinar orci s\
agittis non. Vivamus accumsan erat non nisl lobortis aliquam vel sed turpis.\
Donec ut tempus orci. Nam eget rhoncus mauris, sed gravida orci. Ut at justo \
sapien. Aenean eget feugiat enim. Nunc sed nibh nec lectus mollis suscipit. \
Nunc volutpat urna ac tellus suscipit placerat condimentum id.";
    char const *s2 = "lezalpe";

    cr_assert(my_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}
