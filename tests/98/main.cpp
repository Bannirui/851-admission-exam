#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <valarray>

#ifdef __linux__
  #include <malloc.h>
#elif __APPLE__
  #include <sys/malloc.h>
  #include <queue>
#endif

class Flowshop;
class MinHeapNode {
  friend Flowshop;
  public:
    operator int() const {
      return bb;
    }
  private:
    void Init(int);
    void NewNode(MinHeapNode, int, int, int, int);
    int s, // 已安排作业数
    f1, // 机器1上最后完成时间
    f2, // 机器2上最后完成时间
    sf2, // 当前机器2上完成时间和
    bb, // 当前作业完成时间和下界
    *x; // 当前作业调度
};

class Flowshop {
  friend int main(void);
  public:
    int BBFlow(void);
  public:
    int Bound(MinHeapNode E, int &fl, int &f2, bool **y);
    void Sort(void);
    int n, //  作业数
      **M, // 各作业所需的处理时间数组
      **b, // 各作业所需的处理时间排序数组
      **a, // 数组M和b的对应关系数组
      *bestx, // 最优解
      bestc; // 最小完成时间和
  bool **y; // 工作数组
};

template<class T>
inline void Swap(T &a, T &b);

int main()
{
  int n=3,bf;
  int M1[3][2]={{2,1},{3,1},{2,3}};
  int **M=new int*[n];
  int **b=new int*[n];
  int **a=new int*[n];
  bool **y=new bool*[n];
  int *bestx=new int[n];

  for(int i=0;i<=n;++i) {
    M[i]=new int[2];
    b[i]=new int[2];
    a[i]=new int[2];
    y[i]=new bool[2];
  }
  std::cout<<"各作业所需的时间处理数组M(i,j)值如下 "<<std::endl;
  for(int i=0;i<n;++i) {
    std::cout<<"(";
    for(int j=0;j<2;++j) {
      std::cout<<M1[i][j]<<" ";
    }
    std::cout<<")";
  }
  std::cout<<std::endl;

  Flowshop flow;
  flow.n=n;
  flow.M=M;
  flow.b=b;
  flow.a=a;
  flow.y=y;
  flow.bestx=bestx;
  flow.bestc=1000; // 给定初值
  flow.BBFlow();
  std::cout<<"最优值是"<<flow.bestc<<std::endl;
  std::cout<<"最优调度是";
  for(int i=0;i<n;++i) {
    std::cout<<(flow.bestx[i]+1)<<" ";
  }
  std::cout<<std::endl;
  for(int i=0;i<n;++i) {
    delete[] M[i];
    delete[] b[i];
    delete[] a[i];
    delete[] y[i];
  }
  return 0;
}

// 最小堆节点初始化
void MinHeapNode::Init(int n) {
  x=new int[n];
  for(int i=0;i<n;++i) {
    x[i]=i;
  }
  s=0;
  f1=0;
  f2=0;
  sf2=0;
  bb=0;
}

// 最小堆新节点
void MinHeap::NewNode(MinHeapNode E, int Ef1, int Ef2, int Ebb, int n) {
  x=new int[n];
  for(int i=0;i<n;++i) {
    x[i]=E.x[i];
  }
  f1=Ef1;
  f2=Ef2;
  sf2=E.sf2+f2;
  bb=Ebb;
  s=E.s+1;
}

// 对各作业在机器1和机器2上所需时间排序
void Flowshop::Sort(void) {
  int *c=new int[n];
  for(int j=0;j<2;++j) {
    for(int i=0;i<n;++i) {
      b[i][j]=M[i][j];
      c[i]=i;
    }
    for(int i=0;i<n-1;++i) {
      for(int k=n-1;k>i;--k) {
        if(b[k][j]<b[k-1][j]) {
          Swap(b[k][j], b[k-1][j]);
          Swap(c[k], c[k-1]);
        }
      }
    }

    for(int i=0;i<n;++i) {
      a[c[i]][j]=i;
    }
  }
  delete[] c;
}

// 计算完成时间和下界
int Flowshop::Bound(MinHeapNode E, int &f1, int &f2, bool **y) {
  for(int k=0;k<n;++k) {
    for(int j=0;j<2;++j) {
      y[k][j]=false;
    }
  }
  for(int k=0;k<=E.s;++k) {
    for(int j=0;j<2;++j) {
      y[a[E.x[k]][j]][j]=true;
    }
  }
  f1=E.f1+M[E.x[E.s]][0];
  f2=((f1>E.f2)?f1:E.f2)+M[E.x[E.s]][1];
  int sf2=E.sf2+f2;
  int s1=0,s2=0,k1=n-E.s,k2=n-E.s,f3=f2;
  // 计算s1的值
  for(int j=0;j<n;++j) {
    if(!y[j][0]) {
      k1--;
      if(k1==n-E.s-1) {
        f3=(f2>f1+b[j][0])?f2:f1+b[j][0];
      }
      s1+=f1+k1*b[j][0];
    }
  }
  // 计算s2的值
  for(int j=0;j<n;++j) {
    if(!y[j][1]) {
      k2--;
      s1+=b[j][1];
      s2+=f3+k2*b[j][1];
    }
  }
  // 返回完成时间和下界
  return sf2+((s1>s2)?s1:s2);
}

// 解批处理作业调度问题的优先队列式分支限界法
int Flowshop::BBFlow(void) {
  Sort(); // 对各作业在机器1和2是所需时间排序
  MinHeap<MinHeapNode> H(1000);
  MinHeapNode E;
  E.Init(n); // 初始化
  // 搜索排列空间树
  while(E.s<=n) {
    // 叶节点
    if(E.s==n) {
      if(E.sf2<bestc) {
        bestc=E.sf2;
        for(int i=0;i<n;++i) {
          bestx[i]=E.x[i];
        }
      }
      delete[] E.x;
    } else {
      // 产生当前扩展节点的儿子节点
      for(int i=E.s;i<n;++i) {
        Swap(E.x[E.s], E.x[i]);
        int f1, f2;
        int bb=Bound(E, f1, f2, y);
        if(bb<bestc) {
          // 子树可能含有最优解 节点插入最小堆
          MinHeapNode N;
          N.NewNode(E, f1, f2, bb, n);
          H.Insert(N);
        }
        Swap(E.x[E.s], E.x[i]);
      }
      delete[] E.x; // 完成节点扩展
    }
    if(H.size()==0) {
      break;
    }
    H.DeleteMin(E); // 取下一扩展节点
  }
  return bestc;
}

template<class T>
inline void Swap(T &a, T &b) {
  T temp=a;
  a=b;
  b=temp;
}