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
    int x = 42;

    n = stu_dprintf(1, "%d\n", 12);
    stu_dprintf(2, "bytes printed %d\n", n);
    stu_dprintf(1, "%+d\n", 56);
    str = NULL;
    stu_dprintf(1, "addr is %p\n", str);
    stu_dprintf(1, "addr is %p and str %s\n", str, str);
    stu_dprintf(1, "%c\n", 'A');
    stu_dprintf(1, "%x\n", 255);
    stu_dprintf(1, "%b\n", 10);
    stu_dprintf(1, "%o\n", 64);
    stu_dprintf(1, "%%\n");
    stu_dprintf(1, "%d %p %s\n", 0, &x, "OK");
    return 0;
}
