/*
 * E89 Pedagogical & Technical Lab
 * project: strlen_token.test.c
 * created on:  2026-02-14 - 19:42 +0100
 * 1st author:  sacha.juillard
 * description: test file for the strlen_token function
 */

#include <criterion/criterion.h>
#include "printf.h"
Test(stu_strlen_token, empty_string)
{
    cr_assert_eq(stu_strlen_token("", '0'), 0);
}

Test(stu_strlen_token, no_token_in_string)
{
    cr_assert_eq(stu_strlen_token("hello world", '0'), 11);
}

Test(stu_strlen_token, token_at_start)
{
    cr_assert_eq(stu_strlen_token("0hello", '0'), 0);
}

Test(stu_strlen_token, token_in_middle)
{
    cr_assert_eq(stu_strlen_token("hello0world", '0'), 5);
}

Test(stu_strlen_token, token_at_end)
{
    cr_assert_eq(stu_strlen_token("hello0", '0'), 5);
}

