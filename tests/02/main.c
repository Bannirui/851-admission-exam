#include<stdio.h>
#include<math.h>

/**
 * 读取所有的数据 依次判断是否为非法数字 最终对所有合法数字求平均值
 */

// 单个数字最大长度
#define MAX_SIZE 10

int main(int argc, char** argv)
{
	int n;
	sscanf(argv[1], "%d", &n);
	if (n <= 0)
	{
		printf("参数必须>0");
		return -1;
	}
	// 字符串数组
	char str[n][MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		// 读取每个字符串
		sscanf(argv[i + 2], "%s", str[i]);
	}
	float sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		// 字符串转换为数字
		float num = 0;
		/**
		 * 数字是否合法标识
		 * 0标识非法数字
		 * 1标识当前数字为整数
		 * 2标识当前数字为小数
		 */
		int flag = 1;
		// 当前数字是小数 记录小数点后有几位
		int precision = 0;
		// 标识数字的正负 1标识当前数字是负数 0标识当前数字是正数
		int negative = 0;
		// 轮询每个字符
		char ch;
		for (int j = 0; (ch = str[i][j]) != '\0'; j++)
		{
			if (ch >= '0' && ch <= '9')
			{
				if (flag == 1)
				{
					// 整数 需要分正负
					num = num * 10;
					if (negative)
					{
						num -= (ch - '0');
					}
					else
					{
						num += (ch - '0');
					}
				}
				else if (flag == 2 && precision < 2)
				{
					// 小数
					num += pow(10, -1 * (++precision)) * (ch - '0');
				}
				else
				{
					flag = 0;
					break;
				}
			}
			else if (str[i][j] == '-' && !negative)
			{
				// 负数
				negative = 1;
			}
			else if (str[i][j] == '.' && flag == 1)
			{
				// 遇到了小数点 标识当前数字是小数
				flag = 2;
				precision = 0;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			// 合法数字求和
			sum += num;
			printf("flag:%s, num:%.2f sum:%.2f\n", flag == 1 ? "整数" : flag == 2 ? "小数" : "未知", num, sum);
			cnt++;
		}
	}
	if (cnt > 0)
	{
		printf("结果: %.2f\n", sum / cnt);
	}
	else
	{
		printf("结果: %.2f\n", 0.0);
	}
	return 0;
}