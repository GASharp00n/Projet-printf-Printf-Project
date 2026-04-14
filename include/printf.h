/*
* E89 Pedagogical & Technical Lab
* project: printf
* created on: 2026-03-06 - 16:44 +0100
* 1st author: sacha.juillard
* description: header for printf project
*/

#ifndef PRINTF_H_
#define PRINTF_H_
#include <stdarg.h>

struct printf_row {
char specifier;
int (*function)(int, va_list *, int);
};

unsigned int stu_strlen_token(const char *str, char token);
int stu_dprintf(int fd, const char *pattern, ...);
int run_format(int fd, char specifier, va_list *args,int plus_flag);
int print_char(int fd, va_list *args, int plus_flag);
int print_string(int fd, va_list *args, int plus_flag);
int print_int(int fd, va_list *args, int plus_flag);
int print_ptr(int fd, va_list *args, int plus_flag);
int print_base2(int fd, va_list *args, int plus_flag);
int print_base8(int fd, va_list *args, int plus_flag);
int print_base16_int(int fd, va_list *args, int plus_flag);
int print_base16(int fd, unsigned long nb);

#endif
