//
// Created by rui ding on 2025/8/5.
//

#include <iostream>
// 逆转顺序表中的所有元素
// 算法思想 第一个元素和最后一个元素对调 第二个元素和倒数第二个元素对调 依此类推
/**
 * 翻转数组元素
 * @param arr 数组指针
 * @param n 数组长度
 */
void reverse(int arr[], int n)
{
    int i, t;
    for (i = 0; i < n / 2; i++)
    {
        t              = arr[i];
        arr[i]         = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
}

/**
 * 打印数组内容
 * @param arr 数组指针
 * @param n 数组长度
 */
void print(int arr[], int n)
{
    std::cout << "数组是";
    int i = 0;
    for (i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char** argv)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n     = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    reverse(arr, n);
    print(arr, n);
    return 0;
}