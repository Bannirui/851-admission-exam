#include <string.h>
#include <iostream>
#ifdef __linux__
#include <climits>
#elif  __APPLE__
#include <limits>
#endif
#include <algorithm>
#include <queue>

/**
 * 打印数组元素
 * @param arr 待打印的数组
 * @param sz 数组长度
 */
void Show(int arr[], int sz)
{
	int i;
	std::cout << "数组长度为" << sz << " 数组元素为 ";
	for (i = 0; i < sz; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	int sz, i, j;
	i = 1;
	sscanf(argv[i++], "%d", &sz);
	int arr[sz];
	for (j = 0; j < sz; ++j)
	{
		sscanf(argv[i++], "%d", &arr[j]);
	}
	Show(arr, sz);
	return 0;
}