/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-02-25
* description: prints a character
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int print_char(int fd, va_list *args, int plus_flag)
{
    char c;

    (void) plus_flag;
    c = (char) va_arg(*args, int);
    return write(fd, &c, 1);
}
