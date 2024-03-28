#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>

char my_tolower(char c);

Test(my_tolower, lowercase_char)
{
    printf("here is the char from the test: %c\n", my_tolower('A'));
    cr_assert_eq(my_tolower('A'), 'a');
    cr_assert_eq(my_tolower('Z'), 'z');
    cr_assert_eq(my_tolower('a'), 'a');
    cr_assert_eq(my_tolower('z'), 'z');
    cr_assert_eq(my_tolower('0'), '0');
    cr_assert_eq(my_tolower('9'), '9');
    cr_assert_eq(my_tolower(' '), ' ');
    cr_assert_eq(my_tolower('\t'), '\t');
    cr_assert_eq(my_tolower('\n'), '\n');
    cr_assert_eq(my_tolower('\v'), '\v');
    cr_assert_eq(my_tolower('\f'), '\f');
    cr_assert_eq(my_tolower('\r'), '\r');
    cr_assert_eq(my_tolower('\0'), '\0');
}
