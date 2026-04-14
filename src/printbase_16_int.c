/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06
* description: prints unsigned int in base 16
*/

#include <stdarg.h>
#include "printf.h"

int print_base16_int(int fd, va_list *args, int plus_flag)
{
    unsigned int nb;

    (void) plus_flag;
    nb = va_arg(*args, unsigned int);
    return print_base16(fd, nb);
}
