#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

void reverse(int arr[], int s, int e, int k)
{
    int tmp;
    for (int i = s, j = e; i <= j && i < s + k; i++, j--)
    {
        tmp    = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

int main(int argc, char** argv)
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverse(arr, 0, 8, 9);
    std::cout << "数组逆序为 ";
    for (int i = 0; i < 9; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}