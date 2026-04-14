/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06
* description: prints numbers in base 2
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int print_base2(int fd, va_list *args, int plus_flag)
{
    unsigned int nb;
    char buffer[32];
    int i;
    int count;

    (void) plus_flag;
    nb = va_arg(*args, unsigned int);
    i = 0;
    count = 0;
    if (nb == 0)
        return write(fd, "0", 1);
    while (nb > 0) {
        buffer[i] = (nb % 2) + '0';
        nb = nb / 2;
        i += 1;
    }
    while (i > 0) {
        i -= 1;
        count += write(fd, &buffer[i], 1);
    }
    return count;
}

