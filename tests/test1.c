#include <stdio.h>

/**
 * 只需要找到每一个C 其前面A的个数与后面M的个数乘积则为当下C可组成的ACM 每个C可组成的累加即为最终结果
 */

// 字符串最大长度
#define MAXSIZE 10000

int main(int argc, char** argv)
{
    char str[MAXSIZE];
    int  i;
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        str[i] = argv[1][i];
    }
    printf("样本: %s\n", str);
    // 分别记录每个C之前的A的数量和之后M的数量 ACM的数量
    int count_a = 0, count_m = 0, count = 0;
    // 所有M的数量
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'M')
        {
            count_m++;
        }
    }
    // 每遇到C就开始结算
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'M')
        {
            count_m--;
        }
        else if (str[i] == 'A')
        {
            count_a++;
        }
        else if (str[i] == 'C')
        {
            count += count_a * count_m;
        }
    }
    printf("结果: 有%d个ACM\n", count);
    return 0;
}