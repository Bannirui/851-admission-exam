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
 * 输入的时候标记一下未丢失的数字 没出现的输出就好了
 */
int main(int argc, char** argv)
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;
		int m;
		m = n + 2;
		bool check[1024];
		memset(check, false, sizeof(check));
		while (n--)
		{
			int a;
			std::cin >> a;
			// 将没有丢失的元素置为1
			check[a] = 1;
		}
		int ans[10];
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			// 将丢失的元素打印输出
			if (check[i] == 0)
				ans[cnt++] = i;
			std::cout << ans[0] << " " << ans[1] << std::endl;
		}
	}
	return 0;
}