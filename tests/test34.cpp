#include <iostream>

struct QNode;
struct LiQueue;

typedef struct LiQueue
{
	QNode* front;
	QNode* rear;
} LiQueue;

typedef struct QNode
{
	int val;
	struct QNode* next;
} QNode;

int initQueue(LiQueue& q);
int isEmpty(LiQueue& q);
/**
 * 入队
 * @param ele 入队元素
 * @return 0-成功
 */
int enqueue(LiQueue& q, int ele);
/**
 * 出队
 * @param val 出队的元素
 * @return 0-成功
 */
int dequeue(LiQueue& q, int& val);

int initQueue(LiQueue& q)
{
	q.front = q.rear = nullptr;
	return 0;
}
int isEmpty(LiQueue& q)
{
	return q.front == nullptr;
}
int enqueue(LiQueue& q, int ele)
{
	// 节点
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->val = ele;
	p->next = nullptr;
	if (!q.front)
	{
		// 空队列
		q.front = q.rear = p;
	}
	else
	{
		// 非空队列 链表加上新节点
		q.rear->next = p;
		q.rear = p;
	}
	return 0;
}
int dequeue(LiQueue& q, int& val)
{
	QNode* p;
	if (isEmpty(q)) return -1;
	else
	{
		// 出队的节点
		p = q.front;
		if (q.front == q.rear)
		{
			// 队列中只有一个节点 之后队列会变成空队列
			q.front = q.rear = nullptr;
		}
		else
		{
			q.front = p->next;
			p->next = nullptr;
		}
		val = p->val;
		free(p);
		return 0;
	}
}

int main(int argc, char** argv)
{
	LiQueue q;
	initQueue(q);
	int val;
	if (dequeue(q, val) != 0)
	{
		std::cout << "出队失败 ";
		if (isEmpty(q)) std::cout << "队列为空" << std::endl;
		else std::cout << "队列不为空" << std::endl;
	}
	else std::cout << "出队成功 值为" << val << std::endl;
	if (enqueue(q, 1) != 0)
		std::cout << "1入队失败" << std::endl;
	else std::cout << "1入队成功" << std::endl;
	std::cout << (isEmpty(q) ? "队列为空" : "队列不为空") << std::endl;
	if (enqueue(q, 2) != 0)
		std::cout << "2入队失败" << std::endl;
	else std::cout << "2入队成功" << std::endl;
	std::cout << (isEmpty(q) ? "队列为空" : "队列不为空") << std::endl;
	for (int i = 0; i < 2; i++)
	{
		if (dequeue(q, val) != 0)
		{
			std::cout << "出队失败 ";
			if (isEmpty(q)) std::cout << "队列为空" << std::endl;
			else std::cout << "队列不为空" << std::endl;
		}
		else std::cout << "出队成功 值为" << val << std::endl;
	}
	if (dequeue(q, val) != 0)
	{
		std::cout << "出队失败 ";
		if (isEmpty(q)) std::cout << "队列为空" << std::endl;
		else std::cout << "队列不为空" << std::endl;
	}
	else std::cout << "出队成功 值为" << val << std::endl;
	return 0;
}