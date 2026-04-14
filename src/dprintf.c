/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-02-25
* description: implementation of stu_dprintf
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"
static int handle_format(int fd,
                         const char *pattern,
                         int *i,
                         va_list *args)
{
    int plus_flag;


    plus_flag = 0;
    *i = *i + 1;
    if (pattern[*i] == '+') {
        plus_flag = 1;
        *i = *i + 1;
    }
    return run_format(fd, pattern[*i], args, plus_flag);
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    va_list args;
    int i;
    int written;


    if (!pattern)
        return 0;
    va_start(args, pattern);
    i = 0;
    written = 0;
    while (pattern[i] != '\0') {
        if (pattern[i] == '%' && pattern[i + 1] != '\0')
            written += handle_format(fd, pattern, &i, &args);
        else
            written += write(fd, &pattern[i], 1);
        i += 1;
    }
    va_end(args);
    return written;
}

