#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

/**
 * 对于有序序列a[lo...hi]
 * 若元素的个数少于3个 直接比较
 * 若有更多的元素 将其分为a[lo...mid-1] a[mid+1...hi] 对每个子序列递归查找
 * @param arr 待查找的序列
 * @param lo 起始脚标
 * @param hi 结束脚标
 * @param target 要查找的元素
 * @return 查找到的元素的脚标 -1标识没有找到
 */
int search(int arr[], int lo, int hi, int target)
{
	if (lo > hi) return -1;
	else if (lo == hi)
	{
		// 只有1个元素
		return arr[lo] == target ? lo : -1;
	}
	if (hi - lo < 2)
	{
		// 有2个元素
		return arr[lo] == target ? lo : arr[hi] == target ? hi : -1;
	}
	int mid = lo + ((hi - lo) >> 1);
	if (arr[mid] == target) return mid;
	else if (target < arr[mid]) return search(arr, lo, mid - 1, target);
	else return search(arr, mid + 1, hi, target);
}

int main(int argc, char** argv)
{
	int i = 1;
	int sz;
	sscanf(argv[i++], "%d", &sz);
	if (sz <= 0)
	{
		std::cout << "数组长度必须为unsigned" << std::endl;
		return -1;
	}
	int arr[sz];
	std::cout << "原始数组元素为 ";
	for (int j = 0; j < sz; j++)
	{
		sscanf(argv[i++], "%d", &arr[j]);
		std::cout << arr[j] << " ";
	}
	std::cout << std::endl;
	// sort
	std::sort(arr,arr+sz);
	std::cout << "排序数组元素为 ";
	for (int j = 0; j < sz; j++)
	{
		std::cout << arr[j] << " ";
	}
	std::cout << std::endl;
	int target;
	sscanf(argv[i++], "%d", &target);
	std::cout << "要查找的数字为" << target << " 从数组中查找的脚标为" << search(arr, 0, sz - 1, target);
	return 0;
}