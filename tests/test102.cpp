//
// Created by rui ding on 2025/7/14.
//
#include <stdio.h>

int main(int argc, char** argv)
{
    char c;
    for (c = getchar(); getchar() != '#'; c = getchar())
    {
        printf("1-char: %c\n", c);
        putchar(c);
    }
    printf("2-char: %c\n", c);
    return 0;
}