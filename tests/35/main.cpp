#include <iostream>

#define INF 1000

int test_arr1[10]{ -1, 1, 5, 6, 8, 9, -INF, -INF, -INF, -INF },
	n_1 = 6,
	test_arr2[8]{ -3, 1, 2, 3, -INF, -INF, -INF, -INF },
	n_2 = 4;

typedef struct LNode
{
	int data;
	struct LNode* next;
} LNode;

typedef struct DLNode
{
	int data;
	DLNode* prev, * next;
} DLNode;

/**
 * 打印数组.
 * @param arr 待打印的数组
 * @param sz 数组长度
 */
void displayArr(int arr[], int sz);
/**
 * 打印单链表.
 */
void displayList(LNode* list);
/**
 * 打印双链表.
 */
void displayList(DLNode* list);
/**
 * 数组中第一个比target大的位置
 * @param arr 数组
 * @param sz 数组长度
 * @param target 目标数字
 */
int func4(int arr[], int sz, int target);

void displayArr(int arr[], int sz)
{
	std::cout << "打印数组 ";
	for (int i = 0; i < sz; i++) std::cout << arr[i];
	std::cout << std::endl;
}
void displayList(LNode* list)
{
	std::cout << "打印链表 ";
	while (list->next != nullptr)
	{
		std::cout << list->next->data << " ";
		list = list->next;
	}
	std::cout << std::endl;
}
void displayList(DLNode* list)
{
	std::cout << "打印链表 ";
	while (list->next != nullptr)
	{
		std::cout << list->next->data << " ";
		list = list->next;
	}
	std::cout << std::endl;
}
int func4(int arr[], int sz, int target)
{
	int i;
	for (i = 0; i < sz; ++i) if (arr[i] > target) return i;
	return i;
}
/**
 * 在升序数组arr中找到合适的位置放target保证升序
 */
void func5(int arr[], int& sz, int target)
{
	int p = func4(arr, sz, target);
	for (int i = sz - 1; i > p; --i) arr[i] = arr[i - 1];
	arr[p] = target;
	++sz;
}
/**
 * 轮询搜索数组 找到位置
 * @param arr 数组
 * @param sz 数组长度
 * @param target 要找的数字
 * @return -1标识没找到
 */
int func6(int arr[], int sz, int target)
{
	for (int i = 0; i < sz; i++) if (arr[i] == target) return i;
	return -1;
}
/**
 * 把数组arr从[p...]所有元素都往后挪一个位置 把target放到p位置上
 * 相当于把数组扩容了一个空间
 * @param arr 数组
 * @param sz 数组大小 扩容后增加对应的大小
 * @param target 要放到数组的新元素
 * @param p 数组脚标 arr[p...end]
 */
void func7(int arr[], int& sz, int target, int p)
{
	// 数组元素后移
	for (int i = sz - 1; i >= p; --i) arr[i + 1] = arr[i];
	arr[p] = target;
	sz++;
}
/**
 * 把数组p位置之后从[p+1...]所有元素都往前挪一个位置
 * 相当于把数组缩容了一个空间
 * @param sz 数组大小 缩容后减少对应的大小
 * @param p 数组位置
 */
void func8(int arr[], int& sz, int p)
{
	for (int i = p + 1; i < sz; i++) arr[i - 1] = arr[i];
	--sz;
}
void createLNodeL(LNode*& l, int arr[], int sz)
{
	LNode* s, * r;
	l = (LNode*)malloc(sizeof(LNode));
	l->next = nullptr;
	r = l;
	for (int i = 0; i < sz; ++i)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = arr[i];
		r->next = s;
		s->next = nullptr;
		r = r->next;
	}
}
void createLNodeR(LNode*& l, int arr[], int sz)
{
	LNode* s, * r;
	l = (LNode*)malloc(sizeof(LNode));
	l->next = nullptr;
	r = l;
	for (int i = 0; i < sz; ++i)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = arr[i];
		s->next = nullptr;
		r->next = s;
		r = r->next;
	}
}
/**
 * 合并两个升序单链表为升序链表 链表都是带头节点
 * @param a
 * @param b
 * @param c 合并结果 带头节点
 */
void merge1(LNode* a, LNode* b, LNode*& c)
{
	// 遍历单链表时指向的节点
	LNode* r;
	c = (LNode*)malloc(sizeof(LNode));
	c->next = nullptr;
	r = c;
	// 待合并的节点都带头结点 指向数据节点
	a = a->next;
	b = b->next;
	while (a != nullptr && b != nullptr)
	{
		if (a->data <= b->data)
		{
			r->next = a;
			a = a->next;
		}
		else
		{
			r->next = b;
			b = b->next;
		}
		r = r->next;
	}
	if (a == nullptr) r->next = b;
	if (b == nullptr)r->next = a;
}
/**
 * 合并两个升序链表为升序链表 链表都是带头结点
 * @param l1
 * @param l2
 * @param l
 */
void merge2(LNode* l1, LNode* l2, LNode*& l)
{
	LNode* s;
	// 初始化结果
	l = (LNode*)malloc(sizeof(LNode));
	l->next = nullptr;
	// 跳过头结点 指向数据结点
	l1 = l1->next;
	l2 = l2->next;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->data <= l2->data)
		{
			s = l1;
			l1 = l1->next;
			s->next = l->next;
		}
		else
		{
			s = l2;
			l2 = l2->next;
			s->next = l->next;
		}
		l->next = s;
	}
	while (l1 != nullptr)
	{
		s = l1;
		l1 = l1->next;
		s->next = l->next;
		l->next = s;
	}
	while (l2 != nullptr)
	{
		s = l2;
		l2 = l2->next;
		s->next = l->next;
		l->next = s;
	}
}
/**
 * 从链表中移除特定值的结点
 * @param l 带头结点的单链表
 * @param target 要移除的结点的值
 * @return 0标识成功
 */
int func9(LNode* l, int target)
{
	while (l->next != nullptr)
	{
		if (l->next->data == target)
		{
			// 移除下一个结点
			LNode* s = l->next;
			l->next = s->next;
			free(s);
		}
		l = l->next;
	}
	return 0;
}
/**
 * 将数组arr[start...end]翻转
 */
void reverse(int arr[], int start, int end)
{
	int tmp;
	while (start < end)
	{
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}
/**
 * 删除升序链表中相同的结点
 */
void diff(LNode* l1, LNode* l2)
{
	LNode* s;
	while (l1->next != nullptr && l2->next != nullptr)
	{
		if (l1->next->data < l2->next->data) l1 = l1->next;
		else if (l1->next->data > l2->next->data) l2 = l2->next;
		else
		{
			s = l1->next;
			l1 = l1->next;
			free(s);
		}
	}
}
void p1(LNode* l)
{
	LNode* s = l->next;
	l->next = s->next;
}
void p2(LNode* l)
{
	l = l->next;
	l = l->next;
}
void p3(LNode* l)
{
	l->next = l->next->next;
}

int main(int argc, char** argv)
{
	LNode* a, * b, * c;
	createLNodeR(a, test_arr1, n_1);
	createLNodeR(b, test_arr2, n_2);
	createLNodeL(c, test_arr2, n_2);
	p3(a);
	displayList(a);
	displayList(b);
	displayList(c);
	return 0;
}