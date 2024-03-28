#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strrchr(char *str, char c);
int my_strlen(char *str);
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *restrict dest, const void *restrict src, size_t n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);
int my_strcasecmp(const char *s1, const char *s2);
size_t my_strcspn(const char *s, const char *accept);
// tolower
int tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int my_strcasecmp2(char *s1, char *s2)
{
    for (; *s1 && *s2; s1++, s2++) {
        if (*s1 != *s2) {
            if (tolower(*s1) != tolower(*s2))
                return tolower(*s1) - tolower(*s2);
        }
    }
    return tolower(*s1) - tolower(*s2);
}

/* int main(void) */
/* { */
/*     /1* int size = 20; *1/ */
/*     /1* char *str = malloc(sizeof(char) * size); *1/ */
/*     char str[12] = "hello world"; */
/*     char str2[12] = "HELLo WorlD"; */
/*     int a = strcasecmp(str, str2); */
/*     int b = my_strcasecmp2(str, str2); */
/*     int c = my_strcasecmp(str, str2); */
/*     printf("the true [strcasecmp]: %d\n", a); */
/*     printf("recoded in C -> [my_strcasecmp2]: %d\n", b); */
/*     printf("recoded in asm -> [my_strcasecmp]: %d\n", c); */
/*     return 1; */
/* } */

int main(void)
{
    char *str = "hello world";
    /* printf("basic len is %d\n", strlen(str)); */
    /* printf("basic strcspn is %d\n", strcspn("toto", "a")); */
}
