#include <string.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <queue>

typedef struct BTNode
{
	int data;
	struct BTNode* left;
	struct BTNode* right;

	BTNode(int data) : data(data), left(NULL), right(NULL)
	{
	}
} BTNode;

// UDT 存放二叉树节点和树高
typedef struct QuType
{
	struct BTNode* node;
	int level;
} QuType;

#define MAX 1024

/**
 * 层序遍历
 * 在层序遍历中结点是一层一层处理的 结点进入队列时记录其记录其层次level
 * 根结点属于第一层
 * h=1 队列不空时循环 出队结点p
 * 若其层次等于h 将其存入ans数组 否则输出ans数组为上一层结点 将ans清空 处理第h+1层 将p结点进队 最后输出最后一层的所有结点
 * @param root 二叉树
 */
void LevelOutput(BTNode* root)
{
	if (root == NULL) return;
	// 存放二叉树节点
	std::queue<QuType> q;
	QuType cur, next;
	// 搜索过程中 二叉树节点
	BTNode* p;
	// 存放每一层节点的数据
	int ans[MAX];
	/**
	 * h 处理到了第几层 1-based
	 * idx 数组中待存放元素的脚标
	 */
	int h=1, idx = 0;
	// 封装UDT
	cur.node = root;
	cur.level = h;
	q.push(cur);
	while (!q.empty())
	{
		// 出队
		cur = q.front();
		q.pop();
		p = cur.node;
		if (cur.level == h)
		{
			// 跟上一个结点是同一层元素 都放到数组中缓存
			ans[idx++] = p->data;
		}
		else
		{
			/**
			 * 新的一层遇到的第一个结点
			 * 这个时机
			 * <ul>
			 *   <li>打印上一层的所有元素</li>
			 *   <li>清空缓存数组 准备放新一层的结点</li>
			 * </ul>
			 */
			std::cout << "当前层为" << h << " 元素有 ";
			for (int i = 0; i < idx; i++) std::cout << ans[i] << " ";
			std::cout << std::endl;
			// 清空数组缓存
			idx = 0;
			// 新的一层
			h++;
			ans[idx++] = p->data;
		}
		if (p->left != NULL)
		{
			next.node = p->left;
			next.level = cur.level + 1;
			q.push(next);
		}
		if (p->right != NULL)
		{
			next.node = p->right;
			next.level = cur.level + 1;
			q.push(next);
		}
	}
	// 最后一层
	std::cout << "当前层为" << h << " 元素有 ";
	for (int i = 0; i < idx; i++) std::cout << ans[i] << " ";
	std::cout << std::endl;
}
int main(int argc, char** argv)
{
	BTNode n1(1);
	BTNode n2(2);
	BTNode n3(3);
	BTNode n4(4);
	BTNode n5(5);
	BTNode n6(6);
	BTNode n7(7);
	BTNode n8(8);
	n5.left = &n3;
	n3.left = &n1;
	n1.right = &n2;
	n3.right = &n4;
	n5.right = &n7;
	n7.left = &n6;
	n7.right = &n8;
	LevelOutput(&n5);
	return 0;
}