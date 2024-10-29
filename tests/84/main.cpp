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
 * 快排 按照节点权重升序
 * @param qu 数组实现的栈
 * @param front front指针
 * @param rear rear指针
 */
void sort_w(HuffmanNode* qu[], int front, int rear)
{
  // base
  if(front >= rear) return;
  HuffmanNode* s;
  int i=front,j=rear;
  // 参考 所有相对参考而言 比参考大的节点全部在右边 比参考小的节点全部在左边
  s=qu[front];
  while(i<j)
  {
    // 右边节点都比参考大
    while(i<j && qu[j]->weight>=s->weight) --j;
    // 找到了右边节点比参考小 挪到左边
    if(i<j)
    {
      qu[i]=qu[j];
      ++i;
    }
    // 左边节点都比参考小
    while(i<j && qu[i]->weight<s->weight) ++i;
    // 找到了左边节点比参考大 挪到右边
    if(i<j)
    {
      qu[j]=qu[i];
      --j;
    }
  }
  // 此时i跟j汇合 也就是基准应该呆的地方 基准左边都比基准小 基准右边都比基准大
  qu[i]=s;
  // [front...i...rear] 递归下去
  sort_w(qu, front, i-1);
  sort_w(qu, i+1, rear);
}

/**
 * 霍夫曼树构造方法 根据数组构建
 * @param node 节点值
 * @param name 节点名称
 * @param sz 点数量
 */
HuffmanNode* HuffmanTree(int node[], char name[], int sz)
{
  // 构建队列缓存树
  HuffmanNode* qu[MAX_SZ],*s,*p,*q;
  int rear=0, front=0;
  // 所有的字符构建成节点放到数组中升序
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
  // 然后对升序的节点数组 每次拿出最小的两个节点生成新的root节点 再放回数组继续排序 最终生成的树就是霍夫曼树
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
    std::cout<<"当前节点为创建出来的 权重为"<<s->weight<<std::endl;
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
  
  std::cout<<"树的中序为 ";
	inOrder(L);
  std::cout<<std::endl;
  return 0;
}