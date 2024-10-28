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

#define maxSize 20


/**
 * 交换数组两脚标位置
 * @param i 脚标
 * @param j 脚标
 */
template<typename T>
void swap(T arr[], int& i, int& j)
{
  int tmp=arr[i];
  arr[i]=arr[j];
  arr[j]=tmp;
}

/**
 * 按照商品的单位重量价值进行降序排序
 * @param sz 数据规模 数组长度 sz个商品
 * @param v 商品的价值 v[i]商品i的价值
 * @param w 商品的重量 w[i]商品i的重量
 */
void sort_vw(int sz, float v[], float w[])
{
  /**
   * vw[i] 商品i单位重量的价值
   * max 最大的单位重量价值
   */
  float vw[maxSize],max=0;
  int maxj;
  // 商品单位重量
  for(int i=0;i<sz;++i) vw[i]=v[i]/w[i];
  for(int i=0;i<sz-1;++i)
  {
    // 冒泡排序 轮询数组 每次把[i...sz)最大值换到[i]上
    for(int j=i;j<sz;++j)
    {
      if(max<vw[j])
      {
        max=vw[j];
        maxj=j;
      }
    }
    // 缓存重置 下一轮使用
    max=0;
    // 数组排序 交换
    swap<float>(vw, i, maxj);
    swap<float>(v, i, maxj);
    swap<float>(w, i, maxj);
  }
}

/**
 * 背包容纳的重量给定 能装物品的最大价值
 * @param sz 商品数量
 * @param v 商品价值
 * @param w 商品重量
 * @param c 背包能够容纳的重量
 * @param x 背包装的物品
 */
void package(int sz, float c, float v[], float w[], float x[])
{
  int i;
  sort_vw(sz, v, w);
  for(i=0;i<sz;++i) x[i]=0;

  for(i=0;i<sz;++i)
  {
    if(w[i]>c) break;
    x[i]=1;
    c-=w[i];
  }
  // 剩下的重量没办法容纳整个物品 也就是第i个物品只能装这个物品的部分
  if(i<sz) x[i]=c/w[i];
}

#define SZ 4
int main(int argc, char **argv) {
  /**
   * v 物品价值
   * w 物品重量
   * x 最终背包选择商品的方案
   */
  float v[SZ]={70,120,100,60},w[SZ]={10,30,20,10},x[SZ];
  package(SZ,50,v,w,x);
  std::cout<<"排序后的商品价值 ";
  for(int i=0;i<SZ;++i) std::cout<<v[i]<<" ";
  std::cout<<std::endl;

  std::cout<<"排序后的商品重量 ";
  for(int i=0;i<SZ;++i) std::cout<<w[i]<<" ";
  std::cout<<std::endl;

  std::cout<<"背包结果"<<std::endl;
  for(int i=0;i<SZ;++i) std::cout<<"第"<<i<<"个物品装"<<x[i]<<"个"<<std::endl;
  return 0;
}