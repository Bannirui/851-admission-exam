#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

/**
 * 完成在arr数组[lo...hi]的范围内 对在lo位置上的节点进行调整
 */
void sift(int arr[], int lo, int hi)
{
	/**
	 * j是i左孩子节点
	 */
	int i = lo, j = i * 2;
	// 缓存着可能要调整的父节点
	int tmp = arr[i];
	while (j <= hi)
	{
		/**
		 * j是i的左孩子节点
		 * j+1是i的右孩子节点
		 * 在孩子节点中找到较大元素跟堆顶元素比
		 */
		if (j < hi && arr[j] < arr[j + 1]) j++;
		if (tmp < arr[j])
		{
			// 大根堆 arr[j]调整到双亲节点
			arr[i] = arr[j];
			// 修改i和j的值 继续向下调整
			i = j;
			j = i * 2;
		}
		else break; // 调整结束
	}
	arr[i] = tmp; // 被调整的节点放到最终位置
}

/**
 * 堆排序
 * 将待排序序列构造成一个大顶堆 此时 整个序列的最大值就是堆顶的根节点
 * 将其与末尾元素交换 此时末尾就为最大值 然后将剩余n-1个元素重新构建大根堆 这样会得到n个元素的次小值
 * 如此反复执行便能得到一个有序序列了
 * @param arr
 * @param sz arr数组长度
 */
void heapSort(int arr[], int sz)
{
	int i, tmp;
	/**
	 * 建立初始堆
	 * 堆顶在[0...中间靠前] 然后探测孩子节点 就能覆盖到数组的所有元素
	 */
	for (i = sz / 2 - 1; i >= 0; --i)
		sift(arr, i, sz);
	// 进行n-1次循环 完成堆排序
	for (i = sz - 1; i >= 1; --i)
	{
		/**
		 * 换出根节点的关键字 将其放入最终位置
		 * 大根堆已经有序 此时堆顶元素是最大的 将最大元素换到数组最后 然后重建大根堆
		 */
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		/**
		 * 在减少一个关键字的无序序列中进行调整 重建大根堆
		 */
		sift(arr, 0, i - 1);
	}
}

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
	std::cout << std::endl;
	heapSort(arr, sz);
	std::cout << "排序后 ";
	Show(arr, sz);
	std::cout << std::endl;
	return 0;
}