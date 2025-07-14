#include <string.h>
#include <iostream>
#include <limits>
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

/**
 * a[s...t]序列的前半子序列
 */
void prepart(int& s, int& t)
{
	int m = s + ((t - s) >> 1);
	t = m;
}
/**
 * a[s...t]序列的后半子序列
 */
void postpart(int& s, int& t)
{
	int m = s + ((t - s) >> 1);
	if ((s + t) % 2 == 0) s = m;
	else s = m + 1;
}

/**
 * 求两个有序序列a[s1...t1]和b[s2...t2]的中位数
 * 二分查找
 * 两个递增有序数组a b的中位数分别为a[m1] b[m2]
 * 若a[m1]=b[m2] 则a[m1]或b[m2]即为所求的中位数
 * 否则舍弃a b中的较小者所在序列较小的一半 同时舍弃较大者所在序列之较大的一半
 * 要求两次舍弃元素的元素个数相同
 * 在保留的两个递增序列中重复上述过程 直到两个序列中均只含一个元素时为止 则较小者即为所求的中位数
 */
int midnum(int a[], int s1, int t1, int b[], int s2, int t2)
{
	// 数组中间位置脚标
	int m1, m2;
	// 两个序列都只有一个元素
	if (s1 == t1 && s2 == t2) return a[s1] < b[s2] ? a[s1] : b[s2];
	// a的中位数
	m1 = s1 + ((t1 - s1) >> 1);
	m2 = s2 + ((t2 - s2) >> 1);
	if (a[m1] == b[m2])
		return a[m1];
	if (a[m1] < b[m2])
	{
		// a取后半部分
		postpart(s1, t1);
		// b取前半部分
		prepart(s2, t2);
		return midnum(a, s1, t1, b, s2, t2);
	}
	else
	{
		// a取前半部分
		prepart(s1, t1);
		// b取后半部分
		postpart(s2, t2);
		return midnum(a, s1, t1, b, s2, t2);
	}
}

int main(int argc, char** argv)
{
	int a[] = { 11, 13, 15, 17, 19 };
	int b[] = { 2, 4, 6, 8, 20 };
	std::sort(a, a + 5);
	std::sort(b, b + 5);
	std::cout << "中位数" << midnum(a, 0, 4, b, 0, 4) << std::endl;
	return 0;
}