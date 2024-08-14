#include <string.h>
#include <iostream>
#include <limits>

#define INF 0x3f3f3f3f
#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

/**
 * 数组arr[lo...hi]中的最大元素max1和次大元素max2
 * 采用分治算法求出最大元素max1和次大元素max2
 * 对于a[lo...hi] 将原问题分为a[lo...mid]和a[mid+1...hi]两个子问题
 * 分别求出子问题的最大元素和次大元素
 */
void MAX(int arr[], int lo, int hi, int& max1, int& max2)
{
	if (lo == hi)
	{
		// 区间中只有一个元素
		max1 = arr[lo];
		max2 = -INF;
	}
	else if (hi == lo + 1)
	{
		// 区间有两个元素
		max1 = max(arr[lo], arr[hi]);
		max2 = min(arr[lo], arr[hi]);
	}
	else
	{
		int mid = lo + ((hi - lo) >> 1);
		int lmax1, lmax2, rmax1, rmax2;
		MAX(arr, lo, mid, lmax1, lmax2);
		MAX(arr, mid + 1, hi, rmax1, rmax2);
		// 子问题合并
		max1 = max(lmax1, rmax1);
		max2 = max(lmax2, rmax2);
	}
}
/**
 * 求数组中第二大的数
 * @param arr 数组
 * @param sz 数组长度
 */
int second(int arr[], int sz)
{
	int max1, max2;
	MAX(arr, 0, sz - 1, max1, max2);
	return max2;
}
int main(int argc, char** argv)
{
	int i = 1;
	int sz = 0;
	sscanf(argv[i++], "%d", &sz);
	if (sz <= 0)
	{
		std::cout << "数组长度" << sz << "必须为unsigned int" << std::endl;
		return -1;
	}
	int arr[sz];
	for (int k = 0; k < sz; k++)
	{
		sscanf(argv[i++], "%d", &arr[k]);
	}
	std::cout << "数组arr为 ";
	for (int j = 0; j < sz; j++) std::cout << arr[j] << " ";
	std::cout << std::endl << "第二大数为" << second(arr, sz) << std::endl;
	return 0;
}