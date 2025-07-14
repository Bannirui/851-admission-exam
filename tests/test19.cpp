#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>

/**
 * 由于只关心选择的物品的最大数量(而不是最大重量 最大重量需要考虑DP)
 * 所以装重的物体没有装轻的物体划算
 * 这里只需要对n个物体按照重量递增排序 依次选择每个物体直到装不下为止
 */

const int max = 1005;
// n个物体
// 最大重量C
int n, C;
// 第i种物品的重量
int w[max];

int main(int argc, char** argv)
{
	int i = 1;
	sscanf(argv[i++], "%d", &C);
	if (C <= 0)
	{
		std::cout << "挑选物品的重量总和上限为" << C << "必须unsigned" << std::endl;
		return -1;
	}
	sscanf(argv[i++], "%d", &n);
	if (n <= 0)
	{
		std::cout << "物品数" << n << "必须unsigned" << std::endl;
		return -1;
	}
	if (i > max)
	{
		std::cout << "物品数不能超越上限" << max << std::endl;
		return -1;
	}
	for (int j = 0; j < n; j++) sscanf(argv[i++], "%d", &w[j]);
	std::cout << "总重量为" << C << std::endl;
	std::cout << "共计" << n << "个物品 重量分别为";
	for (int j = 0; j < n; j++) std::cout << w[j] << " ";
	std::cout << std::endl;
	// cnt 选取的物品数
	// weight 当前物品总重量
	int cnt = 0, weight = 0;
	std::sort(w, w + n);
	std::cout << "排序完的数组为";
	for (int j = 0; j < n; j++) std::cout << w[j] << " ";
	std::cout << std::endl;
	for (int j = 0; j < n; j++)
	{
		if (weight + w[j] <= C)
		{
			weight += w[j];
			cnt++;
		}
	}
	std::cout << "最终选择了" << cnt << "个物品 总重量为" << weight << std::endl;
	return 0;
}