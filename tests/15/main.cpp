#include <string.h>
#include <iostream>
#include <limits>

/**
 * 分治法
 * 将数组分为两部分 分别计算两部分的众数
 * 如果两部分众数一致 那么这个数就是众数
 * 如果两部分众数不一致 否则遍历两部分 出现次数最多的那个数为众数
 * 求解过程就是不断将数组二分依次来求解的过程 当所求部分长度为1时返回这一元素
 */

/**
 * 统计数组nums从lo到hi 元素x出现的次数
 */
int rangeCount(int nums[], int x, int lo, int hi)
{
	int cnt = 0;
	for (int i = lo; i <= hi; i++)
		if (nums[i] == x) cnt++;
	return cnt;
}

/**
 * nums[lo...hi]中的众数
 */
int findMode(int nums[], int lo, int hi)
{
	if (lo == hi) return nums[lo];
	int mid = lo + ((hi - lo) >> 1);
	// [lo...mid]
	int leftMode = findMode(nums, lo, mid);
	// (mid...hi]
	int rightMode = findMode(nums, mid + 1, hi);
	return (rangeCount(nums, leftMode, lo, hi) >= rangeCount(nums, rightMode, lo, hi)) ? leftMode : rightMode;
}

int main(int argc, char** argv)
{
	int sz = 0;
	int i = 1;
	sscanf(argv[i++], "%d", &sz);
	if (sz <= 0)
	{
		std::cout << "数组规模" << sz << "必须uint" << std::endl;
		return -1;
	}
	int arr[sz];
	for (int j = 0; j < sz; j++)
	{
		sscanf(argv[i++], "%d", &arr[j]);
	}
	std::cout << "数组为 ";
	for (int k = 0; k < sz; k++) std::cout << arr[k] << " ";
	int ans = findMode(arr, 0, sz - 1);
	std::cout << "众数为" << ans << std::endl;
	return 0;
}