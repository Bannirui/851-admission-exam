//
// Created by dingrui on 2024/7/9.
//
#include <string.h>
#include <iostream>

/**
 * 求最小值.
 */
int min(int a, int b, int c);
/**
 * 将w1和w2的长度记为m和n 使用二维数组dp[m][n]记录w1和w2的距离
 * dp[i][j]表示w1的前i个字符修改为w2的前j个字符需要的操作次数
 * 最后一个字符不同
 * <ul>
 *   <li>添加</li>
 *   <li>删除</li>
 *   <li>更新</li>
 * </ul>
 */
int minOp(char* w1, char* w2);

int main(int argc, char** argv)
{
	char w1[] = "i am dingrui";
	char w2[] = "I am dingrui";
	int ans = minOp(w1, w2);
	std::cout << "w1=" << w1 << ", w2=" << w2 << ", 编辑距离为" << ans;
	return 0;
}

int minOp(char* w1, char* w2)
{
	int sz1 = strlen(w1);
	int sz2 = strlen(w2);
	// corner
	if (sz1 == 0) return sz2;
	if (sz2 == 0) return sz1;
	int dp[sz1 + 1][sz2 + 1];
	// base
	int i, j;
	// i==0 insert
	for (j = 0; j <= sz2; j++) dp[0][j] = j;
	// j==0 insert
	for (i = 0; i <= sz1; i++) dp[i][0] = i;
	for (i = 1; i <= sz1; i++)
	{
		char ch1 = w1[i - 1];
		for (j = 1; j <= sz2; j++)
		{
			char ch2 = w2[j - 1];
			if (ch1 == ch2)
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				// 可以选择 [0...i-1 i] [0...j-1 j]
				// insert dp[i][j-1]+1
				// delete dp[i-1][j]+1
				// replace dp[i-1][j-1]+1
				dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
			}
		}
	}
	return dp[sz1][sz2];
}
int min(int a, int b, int c)
{
	if (a < b)
	{
		return a < c ? a : c;
	}
	else
	{
		return b < c ? b : c;
	}
}