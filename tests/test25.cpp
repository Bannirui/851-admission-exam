#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

/**
 * 输出一个子集
 */
void disppath(int path[], int sz, int& retCnt)
{
	retCnt++;
	std::cout << "输出一个子集 ";
	if (sz > 0)
	{
		for (int i = 0; i < sz; i++) std::cout << path[i] << " ";
	}
	else std::cout << " 为空";
	std::cout << std::endl;
}

/**
 * 全排列
 * @param arr 源数组
 * @param arrSz 源数组长度
 * @param visited 标识数组
 * @param path 子集
 * @param pathSz path大小
 * @param cnt 结果个数
 */
void dfs(int arr[], int arrSz, bool visited[], int path[], int pathSz, int& cnt)
{
	// 收集结果
	if (pathSz == arrSz)
	{
		disppath(path, pathSz, cnt);
		return;
	}
	for (int i = 0; i < arrSz; i++)
	{
		// 不能重复
		if (visited[i] || (i > 0 && !visited[i - 1] && arr[i] == arr[i - 1])) continue;
		visited[i] = true;
		path[pathSz++] = arr[i];
		dfs(arr, arrSz, visited, path, pathSz, cnt);
		// 恢复现场
		visited[i] = false;
		pathSz--;
	}
}

/**
 * 原地排序
 * @param arr 目标数组
 * @param sz 目标数组长度
 * @return 排序好的数组长度
 */
int sort(int arr[], int sz)
{
	std::sort(arr, arr + sz);
	/**
	 * [0...i] 排序好的
	 */
	int i = -1;
	int k = 0;
	while (k < sz)
	{
		if (i + 1 > 0 && arr[k] == arr[i]) k++;
		else arr[++i] = arr[k++];
	}
	return i + 1;
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
	std::cout << std::endl;
	// sort 保证相邻元素在一起
	std::cout << "数组排序 ";
	int len = sort(arr, sz);
	for (int j = 0; j < len; j++) std::cout << arr[j] << " ";
	std::cout << std::endl;
	// 存放子集
	int path[sz];
	// path中最后一个元素的下标
	std::cout << "结果子集" << std::endl;
	int retCnt = 0;
	bool visited[sz];
	memset(visited, false, sz * sizeof(bool));
	dfs(arr, len, visited, path, 0, retCnt);
	std::cout << "结果子集个数" << retCnt << std::endl;
	return 0;
}