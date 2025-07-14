//
// Created by dingrui on 2024/7/8.
//
#include <iostream>

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char* argv[])
{
	// 预算
	int n;
	sscanf(argv[1], "%d", &n);
	/**
	 * 动态规划
	 * dp[i]表示预算为i时可购买的零食数量
	 * <ul>
	 *   <li>预算小于17时无法进行任何购买</li>
	 *   <li>预算在17到33之间可购买3包的零食</li>
	 *   <li>预算等于34时可购买7包零食</li>
	 * </ul>
	 */
	int dp[n + 1];
	int i;
	// 初始化
	for (i = 0; i < 17; i++) dp[i] = 0;
	for (i = 17; i < 34; i++) dp[i] = 3;
	if (n >= 34) dp[34] = 7;
	for (i = 35; i <= n; i++)
		dp[i] = max(dp[i - 17] + 3, dp[i - 34] + 5);
	std::cout << n << "元最多可以购买" << dp[n] << "包零食\n";
	return 0;
}