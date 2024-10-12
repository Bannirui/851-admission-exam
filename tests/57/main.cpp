#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

typedef struct BTNode {
  char data;
  struct BTNode *lchild;
  struct BTNode *rchild;
} BTNode;

void createTree(BTNode *&T) {
  BTNode *a, *b, *c, *d, *e, *f, *g, *h;

  T = (BTNode *)malloc(sizeof(BTNode));
  T->data = '*';
  a = (BTNode *)malloc(sizeof(BTNode));
  a->data = '-';
  b = (BTNode *)malloc(sizeof(BTNode));
  b->data = '/';
  c = (BTNode *)malloc(sizeof(BTNode));
  c->data = '2';
  d = (BTNode *)malloc(sizeof(BTNode));
  d->data = '+';
  e = (BTNode *)malloc(sizeof(BTNode));
  e->data = '3';
  f = (BTNode *)malloc(sizeof(BTNode));
  f->data = '1';
  g = (BTNode *)malloc(sizeof(BTNode));
  g->data = '3';
  h = (BTNode *)malloc(sizeof(BTNode));
  h->data = '4';

  T->lchild = a;
  T->rchild = b;
  a->lchild = c;
  a->rchild = d;
  b->lchild = e;
  b->rchild = f;
  c->lchild = NULL;
  c->rchild = NULL;
  d->lchild = g;
  d->rchild = h;
  e->lchild = NULL;
  e->rchild = NULL;
  f->lchild = NULL;
  f->rchild = NULL;
  g->lchild = NULL;
  g->rchild = NULL;
  h->lchild = NULL;
  h->rchild = NULL;
}

// 计算二叉树的深度 1-based
int getDepth(BTNode *T) {
  if (T == NULL)
    return 0;
  int L, R;
  L = getDepth(T->lchild);
  R = getDepth(T->rchild);
  return (L > R ? L : R) + 1;
}

/**
 * 从二叉树中检索key 找到了把节点缓存在q中
 * @return 0标识找到了 -1标识没找到
 */
int find(BTNode *T, BTNode *&q, char key) {
  if (T == NULL)
    return -1;
  if (T->data == key) {
    q = T;
    return 0;
  }
  if (find(T->lchild, q, key) == 0)
    return 0;
  return find(T->rchild, q, key);
}

/**
 * 从二叉树根节点开始找第k个结点
 * @param q 找到的值缓存
 * @param idx 1-based
 * @return 0标识找到了 -1标识没找到
 */
int findKth(BTNode *T, BTNode *&q, int idx) {
  if (T == NULL)
    return -1;
  --idx;
  if (idx == 0) {
    q = T;
    return 0;
  }
  if (findKth(T->lchild, q, idx) == 0)
    return 0;
  return findKth(T->rchild, q, idx);
}

int main(int argc, char **argv) {
  BTNode *T;
  createTree(T);
  std::cout << "二叉树的深度为: " << getDepth(T) << std::endl;

  BTNode *q;
  char ch = '9';
  if (find(T, q, ch) == 0) {
    std::cout << "找到了" << ch << std::endl;
  } else {
    std::cout << "没找到" << ch << std::endl;
  }

  int k = 3;
  if (findKth(T, q, k) == 0) {
    std::cout << "二叉树中第" << k << "个结点的值为" << q->data << std::endl;
  } else {
    std::cout << "二叉树中没有第" << k << "个结点" << std::endl;
  }
}