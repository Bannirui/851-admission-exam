#include <stdio.h>

int main(int argc, char** argv)
{
    int m, n, a, b, c, d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    m = 2;
    n = 2;
    if ((m = a > b) && (n = c < d)) n = -2;
    printf("m=%d, n=%d\n", m, n);
    return 0;
}