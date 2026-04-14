/*
 * E89 Pedagogical & Technical Lab
 * project: printf
 * created on: 2026-03-04
 * description: criterion tests for stu_dprintf
 */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "printf.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(stu_dprintf, print_simple_string, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "hello");
    cr_assert_stdout_eq_str("hello");
    cr_assert_eq(ret, 5);
}

Test(stu_dprintf, print_char, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%c", 'A');
    cr_assert_stdout_eq_str("A");
    cr_assert_eq(ret, 1);
}

Test(stu_dprintf, print_string, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%s", "LUIGI");
    cr_assert_stdout_eq_str("LUIGI");
    cr_assert_eq(ret, 5);
}

Test(stu_dprintf, print_null_string, .init = redirect_all_stdout)
{
    int ret;
    char *str;

    str = (char *) 0;
    ret = stu_dprintf(1, "%s", str);
    cr_assert_stdout_eq_str("(null)");
    cr_assert_eq(ret, 6);
}

Test(stu_dprintf, print_int_positive, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%d", 42);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(ret, 2);
}

Test(stu_dprintf, print_int_negative, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%d", -42);
    cr_assert_stdout_eq_str("-42");
    cr_assert_eq(ret, 3);
}

Test(stu_dprintf, print_plus_flag_positive,
     .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%+d", 56);
    cr_assert_stdout_eq_str("+56");
    cr_assert_eq(ret, 3);
}

Test(stu_dprintf, print_plus_flag_negative,
     .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%+d", -56);
    cr_assert_stdout_eq_str("-56");
    cr_assert_eq(ret, 3);
}

Test(stu_dprintf, print_percent, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%%");
    cr_assert_stdout_eq_str("%");
    cr_assert_eq(ret, 1);
}

Test(stu_dprintf, print_pointer_null,
     .init = redirect_all_stdout)
{
    int ret;
    void *ptr;

    ptr = (void *) 0;
    ret = stu_dprintf(1, "%p", ptr);
    cr_assert_stdout_eq_str("(null)");
    cr_assert_eq(ret, 6);
}

Test(stu_dprintf, print_hexadecimal, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%x", 255);
    cr_assert_stdout_eq_str("ff");
    cr_assert_eq(ret, 2);

}

Test(stu_dprintf, print_binary, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%b", 10);
    cr_assert_stdout_eq_str("1010");
    cr_assert_eq(ret, 4);

}

Test(stu_dprintf, print_octal, .init = redirect_all_stdout)
{
    int ret;

    ret = stu_dprintf(1, "%o", 10);
    cr_assert_stdout_eq_str("12");
    cr_assert_eq(ret, 2);

}

