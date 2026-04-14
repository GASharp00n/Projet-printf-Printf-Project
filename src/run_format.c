/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06
* description: decision table for format specifiers
*/
#include <unistd.h>
#include "printf.h"

static int print_modulo(int fd, va_list *args, int plus_flag)
{
    (void) args;
    (void) plus_flag;
    return write(fd, "%", 1);
}

static const struct printf_row PRINTF_TABLE[] = {
    {'c', print_char},
    {'s', print_string},
    {'d', print_int},
    {'p', print_ptr},
    {'x', print_base16_int},
    {'b', print_base2},
    {'o', print_base8},
    {'%', print_modulo}
};

static const unsigned int PRINTF_TABLE_LEN =
    sizeof(PRINTF_TABLE) / sizeof(struct printf_row);

int run_format(int fd,
               char specifier,
               va_list *args,
               int plus_flag)
{
    unsigned int i;
    i = 0;
    while (i < PRINTF_TABLE_LEN) {
        if (PRINTF_TABLE[i].specifier == specifier)
            return PRINTF_TABLE[i].function(fd, args, plus_flag);
        i += 1;
    }
    return 0;
}
