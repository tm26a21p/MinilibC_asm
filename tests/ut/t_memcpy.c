#include <criterion/criterion.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

void *my_memcpy(void *dest, void const *src, size_t n);

Test(my_memcpy, basic)
{
    char my[13] = {0};
    char exp[13] = {0};

    cr_assert(my_memcpy(my, "hello world!", 12) == \
              memcpy(my, "hello world!", 12));
    memcpy(exp, "hello world!", 12);
    cr_assert_str_eq(my, exp);
}

Test(my_memcpy, _struct)
{
    struct {
        int x;
        int c;
        char lol[4];
    } yolo = {4, 5, "hil"};
    size_t lol = sizeof(yolo);
    char my[lol];
    char exp[lol];

    my_memcpy(my, &yolo, lol);
    memcpy(exp, &yolo, lol);
    cr_assert(!memcmp(exp, my, lol));
}

Test(my_memcpy, same_ptr)
{
    char my[13] = {0};
    char exp[13] = {0};

    my_memcpy(my, "helloo", 6);

    my_memcpy(my + 6, my, 6);
    memcpy(exp, "helloo", 6);
    memcpy(exp + 6, exp, 6);
    cr_assert_str_eq(my, exp);
}
