#include <algorithm>
#include <iostream>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 4

typedef struct sqStack {
  int data[maxSize];
  int top;
} SqStack;

void initStack(SqStack &st) { st.top = -1; }

int isEmpty(sqStack st) {
  if (st.top != -1)
    return 0;
  else
    return 1;
}

int push(sqStack &st, int x) {
  if (st.top == maxSize - 1)
    return 0;
  ++(st.top);
  st.data[st.top] = x;
  return 1;
}

int pop(sqStack &st, int &e) {
  if (st.top == -1)
    return 0;
  e = st.data[st.top];
  --(st.top);
  return 1;
}

int main(int argc, char **argv) {
  sqStack st;

  initStack(st);
  push(st, 1);
  push(st, 3);
  push(st, 5);
  push(st, 7);

  int i = 0;
  std::cout << "栈中元素为 ";
  while (i < st.top + 1) {
    std::cout << st.data[i] << " ";
    i++;
  }
  std::cout << std::endl;
  return 0;
}