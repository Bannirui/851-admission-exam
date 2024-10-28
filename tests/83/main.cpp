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

#define MAX_SIZE 20
// 商品重量的最大值
#define INF 1000

// 交换数组脚标元素
template<typename T>
void swap(T arr[], int i, int j)
{
  T tmp=arr[i];
  arr[i]=arr[j];
  arr[j]=tmp;
}

/**
 * @param w 货物重量数组 排序并没有直接操作这个数组 而是拷贝了临时数组
 * @param t 如果w数组升序对应的脚标顺序 即实际不变更w数组顺序 将其升序脚标记录在t中
 */
void sort_w(int sz, int w[], int t[])
{
  int w1[MAX_SIZE], minVal=INF, minIndex=-1;
  // 复制数组
  for(int i=0;i<sz;++i) w1[i]=w[i];

  // 拷贝w1数组 2层遍历 每一轮都找到重量最小的货物所在的脚标位置
  for(int i=0;i<sz;++i)
  {
    for(int j=0;j<sz;++j)
    {
      if(w1[j]<minVal)
      {
        // 找到了更小的最小值 更新缓存和对应的脚标
        minVal=w1[j];
        minIndex=j;
      }
    }
    // 更新最小值的缓存 给下一轮轮询使用
    minVal=INF;
    // w1数组按照货物重量升序后的脚标顺序
    t[i]=minIndex;
    w1[minIndex]=INF;
  }
}

/**
 * 货车装货
 * @param sz 货物数量
 * @param w 货物重量
 */
void loading(int sz, int c, int w[], int x[])
{
  // 货物重量数组升序的顺序脚标存储在t中
  int t[MAX_SIZE];
  sort_w(sz, w, t);
  for(int i=0;i<sz;++i) x[i]=0;
  for(int i=0;i<sz&&w[t[i]]<=c;++i)
  {
    x[t[i]]=1;
    c-=w[t[i]];
  }
}

#define SZ 6
int main(int argc, char** argv)
{
  // 货物重量
  int truck[SZ]={6,5,4,3,3,9}, x[MAX_SIZE];
  // 总共装的重量 对货物重量升序后 从小重量到大重量装 通过x数组标识 0表示不装i货物 1表示装i货物
  int target=14;
  loading(SZ, target, truck, x);
  std::cout<<"货物重量为 ";
  for(int i=0;i<SZ;++i) std::cout<<truck[i]<<" ";
  std::cout<<std::endl;

  std::cout<<"总共要装的重量为"<<target<<" 装载方案为 ";
  for(int i=0;i<SZ;++i) std::cout<<x[i]<<" ";
  std::cout<<std::endl;
}