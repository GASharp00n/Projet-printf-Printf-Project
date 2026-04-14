/*
 * E89 Pedagogical & Technical Lab
 * project: strlen_token.c
 * created on:  2026-02-14 - 19:47 +0100
 * 1st author:  sacha.juillard
 * description: strlen like function, stops when it encounters the token
 */
unsigned int stu_strlen_token(const char *str, char token)
{
    unsigned int i;

    i = 0;
    while (str[i] != '\0' && str[i] != token) {
        i += 1;
    }
    return i;
}

