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
 * 交换
 */
void Swap(int* num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * 双向冒泡 升序
 * 改进版的冒泡排序
 * 奇数趟时 从前向后比较相邻元素的关键字 遇到逆序即交换 直到把序列中关键字最大的元素移到序列尾部
 * 偶数趟时 从后往前比较相邻元素的关键字 遇到逆序即交换 直到把序列中关键字最小的元素移到序列前端
 */
void BidBubbleSort(int arr[], int sz)
{
	/**
	 * <ul>
	 *   <li>arr数组待排序的区间是[lo...hi]<ul>
	 *     <li>正向考察时 把最大的值冒泡到最后 然后收缩区间右边界</li>
	 *     <li>反向考察时 把最小的值冒泡到最前 然后收缩区间左边界</li>
	 *   </ul></li>
	 *   <li>flag 标识有数据交换</li>
	 * </ul>
	 */
	int lo, hi, flag, i;
	lo = 0;
	hi = sz - 1;
	while (lo < hi)
	{
		flag = 0;
		// 正向冒泡
		for (i = lo; i < hi; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
				flag = 1;
			}
		}
		if (!flag) break;
		hi--;
		// 反向冒泡
		for (i = hi; i > lo; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
			}
		}
		lo++;
	}
}

int main(int argc, char** argv)
{
	/**
	 * 命令行参数解析
	 * 数组大小
	 */
	int i = 0, sz;
	sscanf(argv[++i], "%d", &sz);
	if (sz <= 0)
	{
		std::cout << "数组规模必须unsigned" << std::endl;
		return -1;
	}
	// 数组
	int arr[sz];
	for (int j = 0; j < sz; j++)
	{
		sscanf(argv[++i], "%d", &arr[j]);
	}
	// sort, before
	Show(arr, sz);
	// sort
	BidBubbleSort(arr, sz);
	// sort, after
	Show(arr, sz);
	return 0;
}