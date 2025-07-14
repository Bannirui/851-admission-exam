#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>

/**
 * 将两个栈的栈顶分别设在两端位置
 * s0栈顶在0处
 * s1栈顶在maxsize-1处
 * 当两栈栈顶相遇时即为栈满
 * <ul>
 *   <li>s0栈<ul>
 *     <li>入栈 栈顶指针+1</li>
 *     <li>出栈 栈顶指针-1</li>
 *   </ul></li>
 *   <li>s1栈<ul>
 *     <li>入栈 栈顶指针-1</li>
 *     <li>出栈 栈顶指针+1</li>
 *   </ul></li>
 * </ul>
 */

#define maxsize 2

// 栈结构定义
typedef struct
{
	int element[maxsize];
	/**
	 * top[0]是s0栈顶
	 * top[1]是s1栈顶
	 */
	int top[2];
} Stack;

/**
 * 入栈.
 * @param st 栈
 * @param num 操作哪一个栈
 * @param x 要入栈的元素
 * @return 0标识成功
 */
int push(Stack& st, int num, int x)
{
	if (st.top[0] + 1 < st.top[1])
	{
		if (num == 0)
		{
			st.element[++st.top[num]] = x;
			return 0;
		}
		if (num == 1)
		{
			st.element[--st.top[num]] = x;
			return 0;
		}
	}
	return -1;
}
/**
 * 出栈
 * @param st 栈
 * @param num 操作哪个栈
 * @return -1标识失败
 */
int pop(Stack& st, int num)
{
	if (num == 0)
	{
		if (st.top[num] != -1)
		{
			return st.element[st.top[num]--];
		}
	}
	if (num == 1)
	{
		if (st.top[num] != maxsize)
		{
			return st.element[st.top[num]++];
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	Stack st;
	// 两个栈的栈顶脚标
	st.top[0] = -1;
	st.top[1] = maxsize;
	push(st, 0, 1);
	push(st, 0, 2);
	push(st, 0, 3);
	std::cout << "出栈元素为 " << pop(st, 0) << std::endl;
	std::cout << "出栈元素为 " << pop(st, 0) << std::endl;
	std::cout << "出栈元素为 " << pop(st, 0) << std::endl;
	return 0;
}