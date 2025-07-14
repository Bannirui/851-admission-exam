#include <string.h>
#include <iostream>

// 二叉树结点
typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* next;
} Node;

// 二叉树元素最大数量
#define MAX_SIZE 7000

/**
 * 使用队列对二叉树使用层序遍历 在每一层结点后放置一个空指针标识各层元素
 * 遍历前设置一个前置结点pre 初始为NULL
 * 每次出队后判断pre是否为NULL 若不为NULL 则将pre->next指向当前出队结点 然后将当前结点设置为pre
 */
void bfs(Node* root)
{
	Node* empty = NULL, * p;
	Node* queue[MAX_SIZE];
	int front = 0, rear = 0;
	// 入队
	if (root != NULL)
	{
		queue[rear++] = root;
		// 每一层遍历的分隔标识
		queue[rear++] = empty;
	}
	while (front <= rear)
	{
		// 出队
		p = queue[front++];
		if (p == empty && front < rear)
		{
			std::cout << "---层分隔符---" << std::endl;
			// 出队元素是层分割标识 此时队列中还有待考察的结点 也就是说此时队列中的元素就是下一层的所有元素 放上一个层分割标识
			queue[rear++] = empty;
		}
		else if (p != empty)
		{
			std::cout << "当前遍历到的结点元素值为" << p->val << std::endl;
			if (p->left != NULL)
				queue[rear++] = p->left;
			if (p->right != NULL)
				queue[rear++] = p->right;
		}
	}
}

int main(int argc, char** argv)
{
	// 结点
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 4;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 7;
	Node* n8 = (Node*)malloc(sizeof(Node));
	n8->val = 8;
	Node* n9 = (Node*)malloc(sizeof(Node));
	n9->val = 9;
	Node* n10 = (Node*)malloc(sizeof(Node));
	n10->val = 10;
	// 树
	n7->left = n4;
	n4->left = n1;
	n7->right = n9;
	n9->left = n8;
	n9->right = n10;
	// bfs
	bfs(n7);
	return 0;
}