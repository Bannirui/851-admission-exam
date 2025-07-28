//
// Created by rui ding on 2025/7/28.
//
#define N 10
#include <iostream>

/**
 * list相对有序 list[lo...hi]
 * @return 分区脚标
 */
int part(int list[], int lo, int hi)
{
    // 比tmp小的往左边放 比tmp大的往右边放
    int tmp = list[lo];
    while (lo < hi)
    {
        while (lo < hi && list[hi] >= tmp) --hi;
        // 右边的这个数字需要挪到左边
        list[lo] = list[hi];
        while (lo < hi && list[lo] <= tmp) ++lo;
        // 左边的这个数字需要挪到右边
        list[hi] = list[lo];
    }
    // 此时lo指向的就是分区位置
    list[lo] = tmp;
    return lo;
}

/**
 * 快排 list[lo...hi]
 * @param list 要排序的数组
 */
void QSort(int list[], int lo, int hi)
{
    if (lo < hi)
    {
        // 相对有序
        int mid = part(list, lo, hi);
        QSort(list, lo, mid);
        QSort(list, mid + 1, hi);
    }
}

void show(int list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char** argv)
{
    int list[N] = {23, 65, 26, 1, 6, 89, 3, 12, 33, 8};
    // 排序前
    show(list, N);
    QSort(list, 0, N - 1);
    // 排序后
    show(list, N);
    return 0;
}