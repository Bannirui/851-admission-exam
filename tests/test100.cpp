#include <cstring>
#include <stdio.h>

int main(int argc, char** argv)
{
    char str[] = {'h', 'e', 'l', 'l', 'o', ' ', '\0', 'w'};
    printf("%zu\n", strlen(str));
    return 0;
}