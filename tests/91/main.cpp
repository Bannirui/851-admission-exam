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
 * 只要满足每位数的立方和等于该数就是水仙花数
 */
int main(int argc, char** argv)
{
  int i, j, k, n;
  std::cout<<"result is: "<<std::endl;
  for(n=100;n<1000;++n)
  {
    // 百位
    i=n/100;
    // 十位
    j=(n-i*100)/10;
    // 个数
    k=n%10;
    if(n==i*i*i+j*j*j+k*k*k)
    {
      std::cout<<n<<std::endl;
    }
  }
  return 0;
}