/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06
* description: prints unsigned long in base 16
*/

#include <unistd.h>
#include "printf.h"

int print_base16(int fd, unsigned long nb)
{
    char *digits;
    char buffer[16];
    int i;
    int count;

    digits = "0123456789abcdef";
    i = 0;
    count = 0;
    if (nb == 0)
        return write(fd, "0", 1);
    while (nb > 0) {
        buffer[i] = digits[nb % 16];
        nb = nb / 16;
        i += 1;
    }
    while (i > 0) {
        i -= 1;
        count += write(fd, &buffer[i], 1);
    }
    return count;
}
