#include <iostream>

#define INF 1000

int test_1[10] = { 0, 1, 5, 6, 8, 9, -INF, -INF, -INF, -INF },
	n_1 = 6,
	test_2[8] = { -3, 1, 2, 3, -INF, -INF, -INF, -INF },
	n_2 = 4;
/**
 * 递归求数组最大值元素 arr[i...]
 * @param arr 数组
 * @param sz 数组长度
 * @param i 当前递归深度 0-based 数组脚标
 */
int getMax(int arr[], int sz, int i)
{
	if (i == sz - 1) return arr[i];
	int ans = getMax(arr, sz, i + 1);
	return (ans > arr[i]) ? ans : arr[i];
}
/**
 * 递归数组求和 arr[i...]
 * @param arr 数组
 * @param sz 数组长度
 * @param i 当前递归深度 0-based 数组脚标
 */
int getSum(int arr[], int sz, int i)
{
	if (i == sz - 1) return arr[i];
	return getSum(arr, sz, i + 1) + arr[i];
}
/**
 * 递归求数组arr[i...sz-1]的均值
 */
float getAverage(float arr[], int sz, int i)
{
	if (i == sz - 1) return arr[i];
	return (getAverage(arr, sz, i + 1) * ((sz - 1) - (i + 1) + 1) + arr[i]) / ((sz - 1) - i + 1);
}
void change(int arr[], int sz)
{
	int i = 0, j = sz - 1;
	while (i < j)
	{
		while (i < j && arr[i] % 2 == 1) ++i;
		while (i < j && arr[j] % 2 == 0) --j;
		if (i < j)
		{
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			++i;
			--j;
		}
	}
}
int main(int argc, char** argv)
{
	std::cout << "数组 ";
	for (int i = 0; i < n_1; ++i) std::cout << test_1[i] << " ";
	std::cout << std::endl;

	change(test_1, 6);

	std::cout << "数组 ";
	for (int i = 0; i < n_1; ++i) std::cout << test_1[i] << " ";
	std::cout << std::endl;
	return 0;
}