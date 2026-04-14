/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06
* description: prints pointers
*/

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"

int print_ptr(int fd, va_list *args, int plus_flag)
{
    void *ptr;
    unsigned long addr;
    int count;

    (void) plus_flag;
    ptr = va_arg(*args, void *);
    if (!ptr)
        return write(fd, "(null)", 6);
    addr = (unsigned long) ptr;
    count = 0;
    count += write(fd, "0x", 2);
    count += print_base16(fd, addr);
    return count;
}
