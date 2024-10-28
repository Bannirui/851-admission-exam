#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define MAX_SZ (1<<10)

// 霍夫曼树节点
typedef struct HuffmanNode
{
  int weight;
  char id;
  struct HuffmanNode* left;
  struct HuffmanNode* right;
} HuffmanNode;

/**
 * 快排
 * @param qu 数组实现的栈
 * @param front front指针
 * @param rear rear指针
 */
void sort_w(HuffmanNode* qu[], int front, int rear)
{
  if(front >= rear) return;
  HuffmanNode* s;
  int i=front,j=rear;
  s=qu[front];
  while(i<j)
  {
    while(i<j && qu[j]->weight>=s->weight)
    {
      if(i<j)
      {
        qu[i]=qu[j];
        ++i;
      }
      while(i<j && qu[i]->weight<s->weight) ++i;
      if(i<j)
      {
        qu[j]=qu[i];
        --j;
      }
    }
  }
  qu[i]=s;
  sort_w(qu, front, i-1);
  sort_w(qu, i+1, rear);
}

/**
 * 霍夫曼树构造方法
 * @param node 结点值
 * @param name 节点名称
 * @param sz 结点数量
 */
HuffmanNode* HuffmanTree(int node[], char name[], int sz)
{
  // 构建队列缓存树结点
  HuffmanNode* qu[MAX_SZ],*s,*p,*q;
  int rear=0, front=0;
  for(int i=0;i<sz;i++)
  {
    // 实例化初始化结点
    s=(HuffmanNode*)malloc(sizeof(HuffmanNode));
    s->weight=node[i];
    s->id=name[i];
    s->left=NULL;
    s->right=NULL;
    // 入栈
    rear=(rear+1)%MAX_SZ;
    qu[rear]=s;
  }
  sort_w(qu, front+1, rear);
  // 队列不空
  while(rear!=front+1)
  {
    // 出队
    p=qu[++front];
    q=qu[++front];
    s=(HuffmanNode*)malloc(sizeof(HuffmanNode));
    s->left=p;
    s->right=q;
    s->weight=p->weight+q->weight;
    // 生成的新节点重新入队
    rear=(rear+1)%MAX_SZ;
    qu[rear]=s;
    // 队列中有新节点进来 重排序
    sort_w(qu, front+1, rear);
    std::cout<<s->weight<<std::endl;
  }
  return qu[rear];
}

void inOrder(HuffmanNode* L)
{
  if(L!=NULL)
  {
    inOrder(L->left);
    std::cout<<L->weight<<" ";
    inOrder(L->right);
  }
}

int main(int argc, char** argv)
{
  HuffmanNode *L;
  // 霍夫曼树节点的名称
	char name[6]={'a','b','c','d','e','f'};
  // 霍夫曼树结点的权重 语义是上面字符出现的次数
	int weight[6]={45,13,12,16,9,5};
  // 构建霍夫曼树
	L=HuffmanTree(weight, name, 6);
	inOrder(L);
  return 0;
}