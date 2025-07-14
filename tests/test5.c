#include <stdio.h>

#include "MyList.h"

int main(int argc, char** argv)
{
    int sz;
    int i = 1;
    sscanf(argv[i++], "%d", &sz);
    if (sz <= 0)
    {
        printf("数据规模必须正整数\n");
        return -1;
    }
    int arr[sz];
    for (int j = 0; j < sz; j++)
    {
        sscanf(argv[i++], "%d", &arr[j]);
    }
    int m, n;
    sscanf(argv[i++], "%d", &m);
    sscanf(argv[i], "%d", &n);
    printf("m=%d, n=%d\n", m, n);
    MyListNode* list = InitListFromArr(arr, sz);
    ListPrint(list);
    list = ListReverseBased0(list, m, n);
    ListPrint(list);
    return 0;
}