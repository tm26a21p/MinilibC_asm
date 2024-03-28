#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>

char *my_strstr(char const *haystack, char const *needle);

Test(my_strstr, basic)
{
    char const *s1 = "hello world";
    char const *s2 = "world";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, _char)
{
    char const *s1 = "hello world";
    char const *s2 = "w";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, begin)
{
    char const *s1 = "hello world";
    char const *s2 = "hello world";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, multiple)
{
    char const *s1 = "hello worlworld";
    char const *s2 = "world";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, middle)
{
    char const *s1 = "hello worlworld";
    char const *s2 = "worl";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, null)
{
    char const *s1 = "hello world";
    char const *s2 = "nope";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
    cr_assert_null(my_strstr(s1, s2));
}

Test(my_strstr, zero_s2)
{
    char const *s1 = "hello world";
    char const *s2 = "";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, zero_s1)
{
    char const *s1 = "";
    char const *s2 = "lol";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
    cr_assert_null(my_strstr(s1, s2));
}

Test(my_strstr, last)
{
    char const *s1 = "hello world";
    char const *s2 = "d";

    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
}

Test(my_strstr, lorem_ipsum)
{
    char const *s1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\
Donec in convallis felis, et condimentum nibh. Phasellus tortor orci, volutpat\
at suscipit in, accumsan at massa. Donec eros felis, interdum ac dolor vel, fi\
nibus accumsan orci. Integer at suscipit arcu. Proin pellentesque felis id orc\
i commodo fermentum. Suspendisse ultricies dolor ipsum, vitae pulvinar orci s\
agittis non. Vivamus accumsan erat non nisl lobortis aliquam vel sed turpis.\
Donec ut tempus orci. Nam eget rhoncus mauris, sed gravida orci. Ut at justo \
sapien. Aenean eget feugiat enim. Nunc sed nibh nec lectus mollis suscipit. \
Nunc volutpat urna ac tellus suscipit placerat condimentum id.";
    char const *s2 = "Nam eget rhoncus mauris";
    char const *s3 = "lezalpe";
    char const *s4 = "agittis non. Vivamus accumsan erat non nisl lobortis \
aliquam vel sed turpis.Donec ut tempus orci. Nam eget rhoncus mauris, sed g\
ravida orci. Ut at justo sapien. Aenean eget feugiat enim. Nunc sed nibh nec \
lectus mollis suscipit. Nunc volutpat urna ac ";
    char const *s5 = "accumsan at massa.l";

    printf("%s\n%s\n", s3, my_strstr(s1, s3));
    cr_assert(my_strstr(s1, s2) == strstr(s1, s2));
    cr_assert(my_strstr(s1, s3) == strstr(s1, s3));
    cr_assert(my_strstr(s1, s4) == strstr(s1, s4));
    cr_assert(my_strstr(s1, s5) == strstr(s1, s5));
}

Test(tests_strstr, strstrs_basic)
{
    cr_assert_str_eq(strstr("boblolbob", "lol"), my_strstr("boblolbob", "lol"));
}

Test(testsmy_strstr, strstrs_nomatch)
{
    cr_assert_str_eq(strstr("boblolbob", ""), my_strstr("boblolbob", ""));
}

Test(testsmy_strstr, my_strstr)
{
    cr_assert_str_eq(my_strstr("abcdef", "cd"), strstr("abcdef", "cd"));
}

Test(testsmy_strstr, my_strstr_not_find)
{
    cr_assert_null(my_strstr("abcdef", "wz"));
}
