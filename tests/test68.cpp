#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

/**
 * arr[lo...hi]快排
 * @return 基准位置的脚标
 */
int randomQuickSort(int arr[], int lo, int hi)
{
    srand((unsigned)time(0));
    // key是在[lo...hi]上的随机值
    int key = rand() % (hi - lo + 1) + lo, t;

    // 基准值
    int tmp = arr[key], i = lo, j = hi;
    t        = arr[key];
    arr[key] = arr[lo];
    arr[lo]  = t;
    while (i < j)
    {
        // 保证右边比基准大
        while (i < j && arr[j] > tmp) --j;
        if (i < j)
        {
            // 右边遇到了比基准小的值 换到左边去
            arr[i] = arr[j];
            ++i;
        }
        // 保证左边比基准小
        while (i < j && arr[i] < tmp) ++i;
        if (i < j)
        {
            // 左边遇到了比基准大的值 换到右边去
            arr[j] = arr[i];
            --j;
        }
    }
    // 当前悬停的脚标位置就是基准应该在的位置
    arr[i] = tmp;
    return i;
}

int select(int arr[], int lo, int hi, int target)
{
    if (lo == hi)
    {
        return arr[lo];
    }
    // arr[lo...hi]排序
    int i = randomQuickSort(arr, lo, hi);
    int j = i - lo + 1;
    if (j >= target)
    {
        return select(arr, lo, i, target);
    }
    else
    {
        return select(arr, i + 1, hi, target - j);
    }
}

int main(int argc, char** argv)
{
    int arr[8] = {1, 4, 2, -4, 3, 99, 5, 7};
    std::cout << "结果为 " << select(arr, 0, 7, 5) << std::endl;

    return 0;
}