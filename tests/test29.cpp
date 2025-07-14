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
void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
 * 快排 降序
 * arr[lo...hi]
 */
void QuickSort(int arr[], int lo, int hi)
{
	if (lo >= hi) return;
	int i = lo, j = hi;
	int tmp = arr[lo];
	while (i < j)
	{
		while (i < j && arr[j] <= tmp) j--;
		swap(arr,i,j);
		while (i < j && arr[i] >= tmp) i++;
		swap(arr,i,j);
	}
	arr[i] = tmp;
	QuickSort(arr, lo, i - 1);
	QuickSort(arr, i + 1, hi);
}

/**
 * 删除数组arr中重复元素 并适应修改数组长度
 * @param arr 数组
 * @param sz arr数组长度
 */
void DelDupelem(int arr[], int& sz)
{
	int k = 1, i;
	for (i = 1; i < sz; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			arr[k] = arr[i];
			k++;
		}
	}
	sz = k;
}

/**
 * 1 对原序列a进行递减排序 采用快排
 * 2 删掉排序后a中重复元素
 * 3 得到的a即为最长递减子序列
 */
void Getsubseq(int arr[], int& sz)
{
	QuickSort(arr, 0, sz-1);
	DelDupelem(arr, sz);
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
		sscanf(argv[++i], "%d", &arr[j]);
	std::cout << "排序前 ";
	Show(arr, sz);
	Getsubseq(arr, sz);
	std::cout << "排序后 ";
	Show(arr, sz);
	return 0;
}