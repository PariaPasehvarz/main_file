#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <stdlib.h>
/*C program to get a string from user in stdin and store it*/
char *InputString(FILE *fp, size_t size)
{
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str) * size);
    if (!str)
    {
        return str;
    }
    while (((ch = fgetc(fp)) != EOF) && (ch != '\n'))
    {
        str[len++] = ch;
        if (len == size)
        {
            str = realloc(str, sizeof(*str) * (size += 1));
            if (!str)
                return str;
        }
    }
    str[len++] = '\0';
    return realloc(str, sizeof(*str) * len);
}