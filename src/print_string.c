/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-02-25
* description: prints a string
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int print_string(int fd, va_list *args, int plus_flag)
{
    char *str;
    unsigned int len;

    (void) plus_flag;
    str = va_arg(*args, char *);
    if (!str)
        return write(fd, "(null)", 6);
    len = stu_strlen_token(str, '\0');
    write(fd, str, len);
    return len;
}
