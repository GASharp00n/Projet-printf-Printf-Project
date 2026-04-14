/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06
* description: prints integers
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

static int print_number(int fd, int nb)
{
    int count;
    char c;

    count = 0;
    if (nb >= 10)
        count += print_number(fd, nb / 10);
    c = (nb % 10) + '0';
    count += write(fd, &c, 1);
    return count;

}

int print_int(int fd, va_list *args, int plus_flag)
{
    int nb;
    int count;

    nb = va_arg(*args, int);
    count = 0;
    if (nb < 0) {
        count += write(fd, "-", 1);
        nb = -nb;
    } else if (plus_flag) {
        count += write(fd, "+", 1);
    }
    count += print_number(fd, nb);
    return count;
}
