#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/**
 * n个整数要整合成一个最大的整数 用数组s[]保存这n个数
 * 由于要找出最大的整数 所以要进行组合也就是尝试各种情况
 * 能否在不比较最终结果的情况下(即不知道最大数是多少) 每次找出一个数放到它应该放的合适的位置上
 * 例如可以从这个数的高位开始放 如果一个数和另一个数两两组合 当这个数做高位其他数做低位时比其他数做高位这个数做低位均大的时候 则这个数一定是放在最终结果的高位上 每次选择一个数放到合适的位置上 经过n-1趟便可以得到最终的最大数
 * 比如 2个数字为12 34 组合可以是1234 也可以是3412 那么第2种组合方式是较大数
 *
 * 比较两个数组合的大小 将使得组合结果较大的数放在a中
 */
void sort(int& a, int& b)
{
	int num_a = 1, num_b = 1;
	while (a / num_a) num_a *= 10;
	while (b / num_b) num_b *= 10;
	// ab vs ba
	if (a * num_b + b < b * num_a + a)
	{
		swap(a, b);
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
	std::cout << "数组长度为" << sz << " 数组元素为 ";
	for (int j = 0; j < sz; j++)
	{
		sscanf(argv[++i], "%d", &arr[j]);
		std::cout << arr[j] << " ";
	}
	// sort 冒泡
	for (int j = 0; j < sz - 1; j++)
	{
		for (int k = 0; k < sz - 1 - j; k++)
		{
			sort(arr[k], arr[k + 1]);
		}
	}
	std::cout << std::endl << "数组排序后为 ";
	for (int j = 0; j < sz; j++) std::cout << arr[j] << " ";
	std::cout << std::endl;
	return 0;
}