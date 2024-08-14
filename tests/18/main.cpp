#include <string.h>
#include <iostream>
#include <limits>

#define MAX 51
#define max(x, y) ((x)>(y)?(x):(y))

// m行n列
int dp[MAX][MAX];

/**
 * 求两个字符串的公共连续子串
 * 设置二维动态规划数组dp
 * 对于两个字符串s和t 用dp[i][j]表示s的前i个字符[0...i-1]和t的前j个字符[0...j-1]的公共连续子串的长度(并非最大长度)
 * 状态转移方程
 * dp[i][0]=0
 * dp[0][i]=0
 * dp[i][j]=dp[i-1][j-1]+1 若s[i-1]=t[j-1] (1<=i<=m 1<=j<=n)
 */
int maxLen(std::string s, std::string t)
{
	size_t m = s.size(), n = t.size();
	// base
	if (m == 0 || n == 0) return 0;
	// 初始化数组 全部为0
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	// base
	for (int i = 0; i <= m; i++) dp[i][0] = 0;
	for (int j = 0; j <= n; j++) dp[0][j] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	std::string s1 = argv[1];
	std::string s2 = argv[2];
	std::cout << "字符串1为 " << s1 << std::endl
			  << "字符串2为 " << s2 << std::endl
			  << "最长公共子串长度为" << maxLen(s1, s2) << std::endl;
	return 0;
}