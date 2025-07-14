#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

int maxSum1(int arr[], int n, int& besti, int& bestj)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int nowSum = 0;
            for (int k = i; k <= j; ++k)
            {
                nowSum += arr[k];
            }
            if (nowSum > sum)
            {
                sum   = nowSum;
                besti = i;
                bestj = j;
            }
        }
    }
    return sum;
}

int maxSum2(int arr[], int n, int& besti, int& bestj)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int nowSum = 0;
        for (int j = i; j < n; ++j)
        {
            nowSum += arr[j];
            if (nowSum > sum)
            {
                sum   = nowSum;
                besti = i;
                bestj = j;
            }
        }
    }
    return sum;
}

/**
 * 最大子段和
 * 数组arr中arr[i...j]和最大
 * @param sz 数组长度
 */
int maxSum3(int arr[], int sz)
{
    // b用于缓存求和结果
    int sum = 0, b = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (b > 0)
        {
            // 当前子序列的求和已经大于0 最优策略是继续累加
            b += arr[i];
        }
        else
        {
            // 子序列的和已经小于0了 当前最优策略肯定是重置子序列
            // 当前数作为新序列的开头
            b = arr[i];
        }
        if (b > sum)
        {
            sum = b;
        }
    }
    return sum;
}

int main(int argc, char** argv)
{
    int arr[6] = {-2, 11, -4, 13, -5, -2};
    std::cout << "数组" << arr << "的最大子序列和为" << maxSum3(arr, 6);
    return 0;
}