#include <string.h>
#include <iostream>
#include <limits>

/**
 * 使用dp[i][j]表示nums数组剩下的部分为下标i和下标j时 当前玩家与另一玩家的分数之差最大值 以此可将问题划分为若干个子问题
 * 当以一种方式使dp[0][n-1]取得分数之差最大值 其中dp[i][j](i>=0 j<n)同样会取得最大值 即具有最优子结构性质 因此可以使用动态规划算法
 * 边界条件
 * <ul>
 *   <li>只有当i<=j时 dp[i][j]才有意义 因此当i>j时dp[i][j]=0</li>
 *   <li>当i==j时 如有一个数 其分数之差最大值就是nums[i]</li>
 * </ul>
 * 递归关系
 * 当i<j时 玩家只有两种可能的选择 即选一条取其端点的数字 最优方案就是两种方式中使分数之差最大的方式 因此dp[i][j]=max(nums[i]-dp[i+1][j], nums[j]-dpp[i][j-1])
 * 最后判断dp[0][n-1]的值 如果大于0 则先手得分大于或等于后手得分 因此玩家1成为赢家 否则玩家2成为赢家
 */

int max(int a, int b)
{
	return a > b ? a : b;
}
int main(int argc, char** argv)
{
	int i = 1;
	int sz = 0;
	sscanf(argv[i++], "%d", &sz);
	if (sz <= 0)
	{
		std::cout << "数组长度" << sz << "必须为unsigned int" << std::endl;
		return -1;
	}
	int arr[sz];
	for (int k = 0; k < sz; k++)
	{
		sscanf(argv[i++], "%d", &arr[k]);
	}
	std::cout << "数组arr为 ";
	for (int j = 0; j < sz; j++) std::cout << arr[j] << " ";
	std::cout << std::endl;
	int dp[sz][sz];
	for (int j = 0; j < sz; j++)
	{
		for (int k = 0; k < sz; k++)
		{
			if (j == k)
				dp[j][k] = arr[j];
			else if (j > k) dp[j][k] = 0;
		}
	}
	for (int j = sz - 2; j >= 0; j--)
	{
		for (int k = j + 1; k < sz; k++)
		{
			dp[j][k] = max(arr[j] - dp[j + 1][k], arr[j] - dp[j][k - 1]);
		}
	}
	if (dp[0][sz - 1] > 0)
		std::cout << "玩家1获胜" << std::endl;
	else
		std::cout << "玩家2获胜" << std::endl;
	return 0;
}