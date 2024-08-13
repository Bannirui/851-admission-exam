#include <string.h>
#include <iostream>
#include <limits>

/**
 * 数独问题与n皇后问题类似 可以使用回溯法递归求解
 * 问题的解空间就是矩阵a 约束条件是同一行 同一列 同一3*3宫内不包含重复数字
 */
// 数独矩阵 初始时只有已知元素为1-9 其余为0
int a[9][9];
enum solve_flag
{
	UN_SOLVED = 0, SOLVE
};
// 记录问题是否解决 0标识未解决
int solve = solve_flag::UN_SOLVED;

/**
 * 数独a[x][y]被填上了某个数字后进行检查是否符合数独的要求
 * <ul>
 *   <li>行</li>
 *   <li>列</li>
 *   <li>九宫格</li>
 * </ul>
 * @param x 0-based
 * @param y 0-based
 * @return 检查结果 0标识没有通过检查
 */
int fill(int x, int y)
{
	// 检查同行
	for (int i = 0; i < 9; i++) if (a[x][i] == a[x][y] && i != y) return 0;
	// 检查同列
	for (int i = 0; i < 9; i++) if (a[i][y] == a[x][y] && i != x) return 0;
	// 检查3*3
	int xi = x / 3, yi = y / 3;
	for (int i = xi * 3; i < (xi + 1) * 3; i++)
	{
		for (int j = yi * 3; j < (yi + 1) * 3; j++)
		{
			if (a[i][j] == a[x][y] && i != x && j != y) return 0;
		}
	}
	return 1;
}
/**
 * 回溯处理数独.
 * 从x行的y列开始填 填完一个单元格就下一列 整行填完之后继续下一行 直到所有行都填完
 * @param x 当前处理的数独的行 0-based
 * @param y 当前处理的数独的列 0-based
 */
void Backtrack(int x, int y)
{
	// base
	if (x == 9)
	{
		solve = solve_flag::SOLVE;
		return;
	}
	if (a[x][y] == 0)
	{
		for (int j = 1; j <= 9; j++)
		{
			a[x][y] = j;
			if (fill(x, y)) Backtrack(x + (y + 1) / 9, (y + 1) % 9);
			if (solve) break;
			// 恢复现场
			a[x][y] = 0;
		}
	}
	else Backtrack(x + (y + 1) / 9, (y + 1) % 9);
}

/**
 * 打印数独.
 */
void print()
{
	std::cout << "数独内容为" << std::endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
	// 预设数独部分数字
	a[0][0] = 9;
	a[0][4] = 5;
	a[3][5] = 3;
	a[7][4] = 4;
	print();
	// 从第一个位置开始回溯
	Backtrack(0, 0);
	print();
	return 0;
}