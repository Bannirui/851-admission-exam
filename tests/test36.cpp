#include <iostream>

#define INF 1000
#define maxSize 20

int test_1[10] = { -1, 1, 5, 6, 8, 9, -INF, -INF, -INF, -INF },
	n_1 = 6,
	test_2[8] = { -3, 1, 2, 3, -INF, -INF, -INF, -INF },
	n_2 = 4;

typedef struct LNode
{
	int data;
	struct LNode* next;
} LNode;
typedef struct QNode
{
	int data;
	struct QNode* next;
} QNode;
typedef struct
{
	QNode* front;
	QNode* rear;
} Queue;
void dispnode(LNode* l)
{
	while (l->next != nullptr)
	{
		std::cout << l->next->data << " ";
		l = l->next;
	}
	std::cout << std::endl;
}
/**
 * 根据数组生成链表
 * @param l 创建的链表
 * @param arr 数组
 * @param sz 数组长度
 */
void createLNodeL(LNode*& l, int arr[], int sz)
{
	LNode* s;
	l = (LNode*)malloc(sizeof(LNode));
	l->next = nullptr;
	// 挂载数组元素为链表节点
	for (int i = 0; i < sz; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = arr[i];
		s->next = l->next;
		l->next = s;
	}
}
void pop(LNode* l)
{
	if (l->next == nullptr) return;
	LNode* s = l->next;
	l->next = s->next;
	free(s);
}
void push(LNode* l, int val)
{
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = val;
	s->next = l->next;
	l->next = s;
}
/**
 * 检查括号数组是否合法 合法的语义是闭合的
 * 比如
 * <ul>
 *   <li>{{{}}}</li>
 *   <li>{{}}{}</li>
 * </ul>
 * @param exp 数组
 * @param sz 数组长度
 * @return false标识不合法 true标识合法
 */
bool ischeck(char exp[], int sz)
{
	int top = -1;
	char stack[maxSize];
	int i = 0;
	while (i < sz)
	{
		if (exp[i] == '{') stack[++top] = '{';
		else if (exp[i] == '}')
		{
			if (stack[top] == '{') top--;
			else return false;
		}
		++i;
	}
	if (top == -1) return true;
	else return false;
}
/**
 * 对两个数字进行四则运算.
 * @param op 加减乘除
 * @return -1标识错误码
 */
int operate(int num1, int num2, char op)
{
	if (op == '+') return num1 + num2;
	else if (op == '-') return num1 - num2;
	else if (op == '*') return num1 * num2;
	else if (op == '/')
	{
		if (num2 == 0)
		{
			std::cout << "CANNOT CALCULATE" << std::endl;
			return -1;
		}
		return num1 / num2;
	}
	return -1;
}
int cal(char exp[], int sz)
{
	int stack[maxSize];
	int top = -1, i = 0;
	while (i < sz)
	{
		if (exp[i] >= '0' && exp[i] <= '9') stack[++top] = exp[i] - '0';
		else
		{
			int num2 = stack[top--];
			int num1 = stack[top--];
			char op = exp[i];
			stack[++top] = operate(num1, num2, op);
		}
		++i;
	}
	return stack[0];
}
void enQueue(Queue* q, int x)
{
	QNode* s;
	s = (QNode*)malloc(sizeof(QNode));
	s->data = x;
	s->next = nullptr;
	// 链表结点入队
	if (q->front == nullptr)
		q->front = q->rear = s;
	else
	{
		q->rear->next = s;
		q->rear = s;
	}
}
void deQueue(Queue* q)
{
	// 空队列
	if (q->front == nullptr) return;
	// 队列FIFO 出队首元素
	QNode* s = q->front;
	if (q->front == q->rear)
	{
		// 队列中原本就一个元素 出队完就变成了空队列
		q->front = q->rear = nullptr;
	}
	else q->front = s->next;
	free(s);
}
int main(int argc, char** argv)
{
	LNode* a;
	char exp[9] = { '1', '2', '3', '4', '*', '+', '+', '5', '/' };

	createLNodeL(a, test_1, n_1);
	pop(a);
	push(a, 99);
	dispnode(a);

	std::cout << "计算结果=" << cal(exp, 9) << std::endl;
	return 0;
}