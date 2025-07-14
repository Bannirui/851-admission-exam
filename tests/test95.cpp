#include <iostream>

#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

/**
 * 数组一分为二
 * a[l...m]和a[m+1...r]已经排好序
 * 把两个子数组元素合并到新数组b中
 */
void Merge(int a[], int b[], int l, int m, int r)
{
    int i = l,      // 前半部分
        j = m + 1,  // 后半部分
        k = 0;      // 新数组
    while ((i <= m) && (j <= r))
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > m)
    {
        // 前半部分已经全部合并完 剩下后半部分直接追加
        for (int q = j; q <= r; ++q)
        {
            b[k++] = a[q];
        }
    }
    else
    {
        // 后半部分已经全部合并完 剩下前半部分直接追加
        for (int q = i; q <= m; ++q)
        {
            b[k++] = a[q];
        }
    }
}

/**
 * b中元素全部复制到a[l...r]中
 */
void Copy(int a[], int b[], int l, int r)
{
    int sz = r - l + 1;
    for (int i = 0; i < sz; ++i)
    {
        a[l++] = b[i];
    }
}

/**
 * a[left...right]排序
 */
void MergeSort(int a[], int left, int right)
{
    int i;
    if (left < right)
    {
        // 中间脚标
        i = (left + right) / 2;
        int b[100];
        // 左半边
        MergeSort(a, left, i);
        // 右半边
        MergeSort(a, i + 1, right);
        // a[left...right]中a[left...mid和a[mid+1...right]作为两个子数组合并到数组中
        Merge(a, b, left, i, right);
        // b数组中放了排序结果 再拷贝回a数组中
        Copy(a, b, left, right);
    }
}

int main(int argc, char** argv)
{
    int a[100];
    int sz  = 10;
    int num = 100;
    for (int i = 0; i < sz; ++i) a[i] = num--;
    // display
    std::cout << "排序前 ";
    for (int i = 0; i < sz; ++i) std::cout << a[i] << " ";
    std::cout << std::endl;
    // sort
    MergeSort(a, 0, sz - 1);
    std::cout << "排序后 ";
    for (int i = 0; i < sz; ++i) std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}