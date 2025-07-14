#include <stdio.h>
#include <math.h>

#include "MyQueue.h"

/**
 * 创建两个栈s1和s2 其中s1负责入栈 s2负责出栈
 * 队列入队 直接将元素入s1栈
 * 队列出队 判断s2是否为空 若不为空 直接将s2首元素出栈 否则将s1中元素一一出栈进入s2栈中 再队s2进行出栈操作
 * 如果s1和s2均为空 则出队为空
 */
int main(int argc, char** argv)
{
    MyQueue* q = QueueInit();
    for (int i = 0; i < 5; i++)
    {
        printf("入队的元素是 %d\n", i);
        EnQueue(q, i);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("出队的元素是 %d\n", DeQueue(q));
    }
    for (int i = 0; i < 2; ++i)
    {
        printf("队列为空了 继续出队的元素是 %d\n", DeQueue(q));
    }
    return 0;
}