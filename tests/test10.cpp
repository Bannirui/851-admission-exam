//
// Created by dingrui on 2024/7/9.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>

int min(int a, int b)
{
	return a < b ? a : b;
}

/**
 * 数组中存储了每个人过河所要花费的时长.
 * @param t 数组
 * @param n 数组长度
 * @return 所有人过河时间
 */
int crossRiver(int n, int t[])
{
	// 数组升序
	std::sort(t, t + n);
	int sum = 0;
	for (int i = n - 1; i > 2; i -= 2)
	{
		sum += min(t[0] + 2 * t[1] + t[i], 2 * t[0] + t[i - 1] + t[i]);
		if (i == 2)
			sum += t[0] + t[1] + t[i];
		else if (i == 1)
			sum += t[1];
		else
			sum += t[0];
	}
	return sum;
}

int main(int argc, char* argv[])
{
	int i = 1;
	int sz;
	sscanf(argv[i++], "%d", &sz);
	if (sz < 0)
	{
		std::cout << "数组arr的长度不能为负数" << std::endl;
		return -1;
	}
	if (sz == 0)
	{
		std::cout << "数组arr的长度为0 终止程序" << std::endl;
		return 0;
	}
	int arr[sz];
	for (int j = 0; j < sz; j++)
	{
		sscanf(argv[i++], "%d", &arr[j]);
	}
	std::cout << "数组arr的长度为" << sz << " 各元素为";
	for (int x : arr) std::cout << x << " ";
	std::cout << std::endl;
	int sum = crossRiver(sz, arr);
	std::cout << "花费的时间为" << sum << std::endl;
	return 0;
}