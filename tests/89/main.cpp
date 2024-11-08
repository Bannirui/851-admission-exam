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

/**
 * 算法思想
 * 每个多项式的各个项 按照指数递增的次序放在单链表中 两个多项式相加 可以将相加的结果合并到一个链表中
 * 可设置两个指针p q 分别用于遍历A(x) B(x)的r各个结点
 * 若当前p q所指两个结点的指数e^x相等 则将q p的系数相加 并让p指向A(x)的下一个结点 q指向B(x)的下一个结点
 * 若当前p的指数e^x更小 则将q所指结点插入到p结点之前 保证指数更小的项在单链表中更靠前 再让q指向B(x)的下一个结点
 * 若当前p的指数e^x更小 则将p指针指向A(x)的下一个结点即可 两个多项式相加的结果保存在原来的单链表A(x)中
 *
 * 若两个多项式的长度是m n 则
 * 时间复杂度是O(m+n)
 * 空间复杂度是O(1)
 */

// 多项式的数据结构定义
typedef struct Node
{
  float co; // 系数
  int ex; // 指数
  struct Node* next; // 指向下一个结点
} *Polynomial;

// a和b两个多项式相加 相加的结果合并到a
int Addition(Polynomial &a, Polynomial &b)
{
  if(a==NULL || b==NULL) return 0;
  struct Node* p=a, *q=b;
  struct Node* pPre=NULL;
  // 合并同类项 结果放到a上
  while(p!=NULL && q!=NULL)
  {
    if(p->ex < q->ex)
    {
      // p指数小 不动
      pPre=p;
      p=p->next;
    }
    else if(p->ex > q->ex)
    {
      // p指数大 把b上面小的项挂到a上面大的前面
      struct Node* s=q;
      q=q->next;
      s->next=p->next;
      p->next=s;
      int coTmp=s->co;
      int exTmp=s->ex;
      s->co=p->co;
      s->ex=p->ex;
      p->co=coTmp;
      p->ex=exTmp;
      pPre=p;
      p=p->next;
    }
    else
    {
      // 两个指数相同 合并系数放到a上
      p->co+=q->co;
      pPre=p;
      p=p->next;
      struct Node* s=q;
      q=q->next;
      free(s);
    }
  }
  if(p==NULL)
  {
    // 说明b中还没合并完的结点 全部挂到a上
    pPre->next=q;
  }
  return 1;
}

void print(Polynomial &head)
{
  std::cout<<"多项式为 ";
  while(head!=NULL)
  {
    std::cout<<head->co<<"*X^"<<head->ex<<" ";
    head=head->next;
  }
  std::cout<<std::endl;
}

struct Node* init(int co, int ex)
{
  struct Node* ans=(struct Node*)malloc(sizeof(struct Node));
  ans->co=co;
  ans->ex=ex;
  return ans;
}

int main(int argc, char** argv)
{
  struct Node* h1=init(2,0);
  struct Node* h2=init(4,3);
  struct Node* h3=init(-1,6);
  struct Node* h4=init(5,7);
  h1->next=h2;
  h2->next=h3;
  h3->next=h4;
  h4->next=NULL;

  struct Node* h5=init(1,3);
  struct Node* h6=init(2,7);
  struct Node* h7=init(-2,8);
  h5->next=h6;
  h6->next=h7;
  h7->next=NULL;

  int succ=Addition(h1, h5);
  if(succ==0)
  {
    std::cout<<"合并链表失败"<<std::endl;
    return 0;
  }
  print(h1);
}