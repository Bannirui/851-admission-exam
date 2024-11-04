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

#define INF 1000

// 抽象任务
typedef struct JobNode
{
  // 任务编号 执行任务耗时
  int id, needtime;
} JobNode;

// 抽象机器节点
typedef struct MachineNode
{
  // 机器编号 可用开始时间
  int id, avail;
} MachineNode;

// 快排 按照任务的耗时needtime升序
void sort_time(JobNode job[], int lo, int hi)
{
  JobNode tmp;
  int i=lo,j=hi;
  if(lo<hi)
  {
    tmp=job[lo];
    while(i<j)
    {
      while(i<j && job[j].needtime>=tmp.needtime) --j;
      if(i<j)
      {
        job[i]=job[j];
        ++i;
      }
      while(i<j && job[i].needtime<tmp.needtime) ++i;
      if(i<j)
      {
        job[j]=job[i];
        --j;
      }
    }
    job[i]=tmp;
    sort_time(job, lo, i-1);
    sort_time(job, i+1, hi);
  }
}

/**
 * 数组中查找avail最小的脚标
 * 从机器列表中选择执行任务的机器 选择的标准是最早可用的 也就是avail最小的
 * @return 机器里表的脚标
 */
int genminavail(MachineNode machine[], int sz)
{
  int min=INF, minj;
  for(int i=0;i<sz;++i)
  {
    if(machine[i].avail<min)
    {
      minj=i;
      min=machine[i].avail;
    }
  }
  return minj;
}

/**
 * @param jobSz 任务列表
 * @param machineSz 机器资源
 */
void greedy(JobNode job[], MachineNode machine[], int jobSz, int machineSz)
{
  if(jobSz<=machineSz) return;
  int k=0;
  sort_time(job, 0, jobSz-1);
  std::cout<<"job按照耗时排序后为"<<std::endl;
  for(int i=0;i<jobSz;++i) std::cout<<"job "<<job[i].id<<", cost "<<job[i].needtime<<std::endl;
  for(int i=0;i<jobSz;++i)
  {
    std::cout<<"machine="<<machine[k].id<<" avail="<<machine[k].avail<<" next time="<<machine[k].avail+job[i].needtime;
    machine[k].avail+=job[i].needtime;
    k=genminavail(machine, machineSz);
    std::cout<<" 选取的机器是"<<k<<std::endl;
  }
}

int main(int argc, char** argv)
{
  int work[7]={1,2,3,4,5,6,7}, needtime[7]={2,14,4,16,6,5,3};
  int jobSz=7,machineSz=3;
  JobNode job[jobSz];
  MachineNode machine[machineSz];

  // 初始化任务
  for(int i=0;i<jobSz;++i)
  {
    // 任务编号
    job[i].id=i+1;
    // 执行任务需要的耗时
    job[i].needtime=needtime[i];
  }

  // 初始化机器
  for(int i=0;i<machineSz;++i)
  {
    // 机器编号
    machine[i].id=i+1;
    // 机器可用时刻
    machine[i].avail=0;
  }
  greedy(job, machine, jobSz, machineSz);
  return 0;
}