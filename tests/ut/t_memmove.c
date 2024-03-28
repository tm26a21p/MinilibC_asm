#include <criterion/criterion.h>
#include <string.h>

void *my_memmove(void *dest, void const *src, size_t n);

Test(my_memmove, overlap)
{
    char my[13] = "hello world!";
    char exp[13] = "hello world!";

    my_memmove(my, (char const*)my + 5, 5);
    memmove(exp, (char const*)exp + 5, 5);
    cr_assert_str_eq(my, exp);
}

Test(my_memmove, overlap_2)
{
    char my[13] = "hello world!";
    char exp[13] = "hello world!";

    my_memmove(my, (char const*)my + 2, 3);
    memmove(exp, (char const*)exp + 2, 3);
    cr_assert_str_eq(my, exp);
}

Test(my_memmove, overlap_3)
{
    char my[13] = "hello world!";
    char exp[13] = "hello world!";

    my_memmove(my + 2, (char const*)my, 7);
    memmove(exp + 2, (char const*)exp, 7);
    cr_assert_str_eq(my, exp);
}

Test(my_memmove, no_overlap)
{
    char my[13] = {0};
    char exp[13] = {0};

    my_memmove(my, "hello world!", 12);
    memmove(exp, "hello world!", 12);
    cr_assert_str_eq(my, exp);
}

Test(my_memmove, _struct)
{
    struct {
        int x;
        int c;
        char lol[4];
    } yolo = {4, 5, "hil"};
    size_t lol = sizeof(yolo);
    char my[lol];
    char exp[lol];

    my_memmove(my, &yolo, lol);
    memmove(exp, &yolo, lol);
    cr_assert(!memcmp(exp, my, lol));
}


Test(my_memmove, same_ptr)
{
    char my[13] = {0};
    char exp[13] = {0};

    my_memmove(my, "helloo", 6);
    my_memmove(my + 6, my, 6);
    memmove(exp, "helloo", 6);
    memmove(exp + 6, exp, 6);
    cr_assert_str_eq(my, exp);
}
