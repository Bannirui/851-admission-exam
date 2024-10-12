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

int getDepth(BTNode *T) {
  if (T == NULL)
    return 0;
  int L, R;
  L = getDepth(T->lchild);
  R = getDepth(T->rchild);
  return (L > R ? L : R) + 1;
}

int main(int argc, char **argv) {
  BTNode *T;
  createTree(T);
  std::cout << "二叉树的深度为: " << getDepth(T) << std::endl;
  return 0;
}