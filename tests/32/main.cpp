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

int arr[100];

/**
 * 数组排序 升序
 * @param arr 数组
 * @param sz 数组长度
 */
void sort(int* arr, int sz)
{
	int i, j, k;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz; j++)
		{
			if (arr[j] > arr[i])
			{
				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
		}
	}
}
/**
 * 遍历字符串 将5之前数字放到指定数组
 */
void processStr(char* str)
{
	int i, j = 0;
	int sum = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != '5')
			sum = sum * 10 + (str[i] - '0'); // 直到遇到5才收集结果
		else
		{
			if (i != 0 && str[i - 1] != '5')
			{
				// 收集答案 重置sum
				arr[j++] = sum;
				sum = 0;
			}
		}
	}
	/**
	 * 字符串已经遍历完 但是sum结果可能需要收集 如果字符串最后一个字符不是5 也就意味最后一轮的结果需要收集
	 * 比如字符串1512
	 * 5后面的12需要收集
	 */
	if (str[i - 1] != '5') arr[j++] = sum;
	Show(arr, j);
	sort(arr, j);
	Show(arr, j);
}
/**
 * 开辟一个数组用来存放结果
 * <ul>
 *   <li>整个数字按照5分割作为整体放到结果集合中</li>
 *   <li>对数组升序</li>
 * </ul>
 */
int main(int argc, char** argv)
{
	char* str = argv[1];
	std::cout << "字符串为 " << str << std::endl;
	processStr(str);
	return 0;
}