#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

/**
 * 把b中所有元素全部依次挪到a[l...r]中
 */
template <class T>
void Copy(T a[], T b[], int l, int r)
{
    // 要挪多少个元素
    int sz = r - l + 1;
    for (int i = 0; i < sz; ++i)
    {
        a[l++] = b[i];
    }
}

/**
 * 合并数组
 * a[l...m]和a[m+1...r]分别有序 把他们合并成绝对有序的数组
 * 有序元素拷贝到数组b中
 */
template <class T>
void Merge(T a[], T b[], int l, int m, int r)
{
    int i  = l,          // 指向a[l...]
        j  = m + 1,      // 指向a[m+1...]
        k  = 0;          // 指向b[0...]
    int sz = r - l + 1;  // 整个要合并的数组长度
    for (int p = 0; p < sz; ++p)
    {
        if (i > m)
        {
            // 前半部分已经合完
            b[k++] = a[j++];
            continue;
        }
        if (j > r)
        {
            // 后半部分已经合完
            b[k++] = a[i++];
            continue;
        }
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
}

/**
 * 对数组a[l...r]归并排序
 */
template <class T>
void MergeSort(T a[], int l, int r)
{
    if (l < r)
    {
        int sz  = r - l + 1;
        T*  b   = new T[sz];
        int mid = (l + r) / 2;  // 中点
        // a[l...mid]
        MergeSort(a, l, mid);
        // a[mid+1...r]
        MergeSort(a, mid + 1, r);
        // 合并数组
        Merge(a, b, l, mid, r);
        // 元素复制回原数组
        Copy(a, b, l, r);
    }
}

int main(int argc, char** argv)
{
    int  sz  = 10;
    int* a   = new int[sz];
    int  num = 100;
    for (int i = 0; i < sz; ++i)
    {
        a[i] = num--;
    }
    std::cout << "排序前数组为 ";
    for (int i = 0; i < sz; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    MergeSort(a, 0, sz - 1);
    std::cout << "排序后数组为 ";
    for (int i = 0; i < sz; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}