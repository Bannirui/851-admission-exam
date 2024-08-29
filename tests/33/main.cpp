#include <string.h>
#include <iostream>
#include <malloc/malloc.h>

#define maxSize 3

/**
 * 队列
 * <ul>
 *   <li>指针的含义
 *     <li>rear指针 指向队尾</li>
 *     <li>front指针 指向队头</li>
 *   </li>
 *   <li>先进先出<ul>
 *     <li>元素入队 rear向高地址移动</li>
 *     <li>元素出队 front向高地址移动</li>
 *   </ul>队列空 </li>
 *   <li>怎么区分队列空还是满 有2种思路<ul>
 *     <li>一种维护元素数量sz 当front==rear的时候通过sz==0或者sz==cap来判断队列是空还是满</li>
 *     <li>另一种是牺牲一个元素空间 数组中只存放cap-1个元素<ul>
 *       <li>front==rear时候队列肯定是空的</li>
 *       <li>不断入对元素 保证rear转了一圈之后不会再跟front相遇 也就是队列满的时候 中间刚好空一个元素位置 rear+1==front</li>
 *     </ul></li>
 *   </ul></li>
 * </ul>
 */
typedef struct SqQueue
{
	int data[maxSize];
	int front, rear;
} SqQueue;

void initSqQueue(SqQueue& q);
int isEmpty(SqQueue& q);
int isFull(SqQueue& q);
int enqueue(SqQueue& q, int ele);
int dequeue(SqQueue& q, int& val);

void initSqQueue(SqQueue& q)
{
	q.front = q.rear = 0;
}
int isEmpty(SqQueue& q)
{
	return q.rear == q.front;
}
int isFull(SqQueue& q)
{
	return (q.rear + 1) % maxSize == q.front;
}
int enqueue(SqQueue& q, int ele)
{
	if (isFull(q)) return -1;
	q.data[q.rear] = ele;
	q.rear = (q.rear + 1) % maxSize;
	return 0;
}
int dequeue(SqQueue& q, int& val)
{
	if (isEmpty(q)) return -1;
	val = q.data[q.front];
	q.front = (q.front + 1) % maxSize;
	return 0;
}

int main(int argc, char** argv)
{
	int ret, val;
	SqQueue q = SqQueue{};
	initSqQueue(q);
	if (isEmpty(q)) std::cout << "队列为空" << std::endl;
	else
	{
		std::cout << "队列不为空" << std::endl;
		dequeue(q, val);
		std::cout << "出队元素是" << val << std::endl;
	}
	for (int i = 0; i < 2; i++)
	{
		ret = enqueue(q, i);
		if (ret == 0) std::cout << i << "入队成功" << std::endl;
		else std::cout << i << "入队失败" << std::endl;
	}
	if (isEmpty(q)) std::cout << "队列为空" << std::endl;
	else
	{
		std::cout << "队列不为空" << std::endl;
		ret = dequeue(q, val);
		if (ret == 0)
			std::cout << "出队元素是" << val << std::endl;
		else std::cout << "出队失败 错误码为" << ret << std::endl;
	}
	for (int i = 3; i < 5; i++)
	{
		ret = enqueue(q, i);
		if (ret == 0) std::cout << i << "入队成功" << std::endl;
		else std::cout << i << "入队失败" << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		ret = dequeue(q, val);
		if (ret == 0)
			std::cout << "出队操作成功 出队元素是" << val << std::endl;
		else std::cout << "出队操作失败" << std::endl;
	}
	enqueue(q, 1);
	dequeue(q, val);
	std::cout << "出队操作成功 出队元素是" << val << std::endl;
	return 0;
}