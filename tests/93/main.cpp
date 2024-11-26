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
 * 数组合并
 * A[p...q]
 * A[q+1...r]
 * 这个数组的两个部分已经分别绝对有序 把他们调整到A[p...r]整个有序
 * @param start 开始脚标
 * @param mid 中间脚标
 * @param end 结束脚标
 */
void MERGES(int *A, int start, int mid, int end)
{
  // [start...mid]之间个数
  int n1=mid-start+1;
  // [mid+1...end]个数
  int n2=end-mid;
  // 申请两个数组
  int *L=new int[n1+1],*R=new int[n2+1];
  int i,j,k;
  // A两个部分分别拷贝到两个不同数组中
  for(i=0;i<n1;++i)
  {
    L[i]=A[start+i];
  }
  for(j=0;j<n2;++j)
  {
    R[j]=A[mid+1+j];
  }
  // 设置哨兵
  L[n1]=10000;
  R[n2]=10000;
  i=0;
  j=0;
  // 两个数组合并到A[p...r]
  for(k=start;k<=end;++k)
  {
    if(L[i]<=R[j])
    {
      A[k]=L[i];
      ++i;
    }
    else
    {
      A[k]=R[j];
      ++j;
    }
  }
}

/**
 * 合并排序 对A[p...r]进行排序
 * @param A 要排序的数组
 * @param start 开始脚标
 * @param end 结束脚标
 */
void MERGESORT(int *A, int start, int end)
{
  if(start<end)
  {
    // 中间
    int mid=(start+end)/2;
    // A[start...mid]
    MERGESORT(A, start, mid);
    // A[mid+1...end]
    MERGESORT(A, mid+1, end);
    MERGES(A, start, mid, end);
  }
}

int main(int argc, char** argv)
{
  int x, z, p, r;
  x=10;
  int *A=new int[x];
  int num=88;
  for(int i=0;i<x;++i)
  {
    A[i]=num--;
  }
  // display
  std::cout<<"排序前 数组打印"<<std::endl;
  for(int i=0;i<x;++i)
  {
    std::cout<<A[i]<<" ";
  }
  std::cout<<std::endl;

  // sort
  MERGESORT(A, 0, 9);

  std::cout<<"排序后 数组打印"<<std::endl;
  for(int i=0;i<x;++i)
  {
    std::cout<<A[i]<<" ";
  }
  std::cout<<std::endl;

  delete []A;

  return 0;
}