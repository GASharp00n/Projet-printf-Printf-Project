/*
 * E89 Pedagogical & Technical Lab
 * project: drprintf.main.c
 * created on:  2026-02-25 - 19:19 +0100
 * 1st author:  sacha.juillard
 * description: main for dprintf
 */

#include "printf.h"
#include <stddef.h>
int main(void)
{
    int n;
    char *str;

    n = stu_dprintf(1, "%d\n", 12);
    stu_dprintf(2, "bytes printed %d\n", n);
    stu_dprintf(1, "%+d\n", 56);
    str = NULL;
    stu_dprintf(1, "addr is %p\n", str);
    stu_dprintf(1, "addr is %p and str %s\n", str, str);
    return 0;
}
