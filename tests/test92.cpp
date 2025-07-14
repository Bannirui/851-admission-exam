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

// 数组容量
const int N = 1024;

class list
{
   public:
    int array[N];
    /**
     * 初始化数组array
     * @param sz 要初始化数组的长度
     */
    void input(int sz);
    void mergesort(int array[]);
    /**
     * 打印数组内容
     * @param sz 数组长度
     */
    void display(int sz);

   private:
    void merge(int arrayc[], int arrayd[], int l, int m, int r);
    void mergepass(int arrayx[], int arrayy[], int s);
};

void list::input(int sz)
{
    std::cout << "Generate array, and the size is " << sz << std::endl;
    for (int i = 0; i < sz; ++i)
    {
        this->array[i] = sz--;
    }
}

void list::merge(int arrayc[], int arrayd[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while ((i <= m) && (j <= r))
    {
        if (arrayc[i] <= arrayc[j])
        {
            arrayd[k++] = arrayc[i++];
        }
        else
        {
            arrayd[k++] = arrayc[j++];
        }
        if (i > m)
        {
            for (int q = j; q <= r; ++q)
            {
                arrayd[k++] = arrayc[q];
            }
        }
        else
        {
            for (int q = i; q <= m; ++q)
            {
                arrayd[k++] = arrayc[q];
            }
        }
    }
}

/**
 * @param s
 */
void list::mergepass(int arrayx[], int arrayy[], int s)
{
    int i = 0;
    while (i <= N - 2 * s)
    {
        this->merge(arrayx, arrayy, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    if ((i + s) < N)
    {
        this->merge(arrayx, arrayy, i, i + s - 1, N - 1);
    }
    else
    {
        for (int j = i; j < N; ++j)
        {
            arrayy[j] = arrayx[j];
        }
    }
}

void list::mergesort(int array1[])
{
    int array2[N];
    int s = 1;
    while (s < N)
    {
        this->mergepass(array1, array2, s);
        s += s;
        this->mergepass(array2, array1, s);
        s += s;
    }
}

void list::display(int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}

int main(int argc, char** argv)
{
    list f;
    // 数组规模
    int a = 10;
    f.input(a);
    f.mergesort(f.array);
    f.display(a);
    return 0;
}