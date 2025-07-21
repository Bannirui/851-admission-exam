// 求网格中的黑点分布
// 现有6*7的网格 在某些格子中有黑点 已知各行与各列有黑点的点数之和
// 请在网格中画出黑点的位置
#include <cstdio>
#include <iostream>

#define ROWS 6
#define COLS 7
// 各列黑点数和的情况
int iPointsR[ROWS] = {2, 0, 4, 3, 4, 0};
// 各列黑点数的情况
int iPointsC[COLS] = {4, 1, 2, 2, 1, 2, 1};
int iCount, iFound;
int iSumR[ROWS], iSumC[COLS], Grid[ROWS][COLS];

int Set(int iRowNo)
{
    if (iRowNo == ROWS)
    {
        for (int iColNo = 0; iColNo < COLS && iSumC[iColNo] == iPointsC[iColNo]; iColNo++)
        {
            if (iColNo == COLS - 1)
            {
                printf("\nNo %d\n", ++iCount);
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLS; j++)
                    {
                        std::cout << Grid[i][j] << ((j + 1) % COLS ? "" : "\n");
                    }
                }
                // 有解
                iFound = 1;
            }
            else
            {
                for (int iColNo = 0; iColNo < COLS; iColNo++)
                {
                    if (iPointsR[iColNo] == 0)
                        Set(iColNo + 1);
                    else if (Grid[iRowNo][iColNo] == 0)
                    {
                        Grid[iRowNo][iColNo] = 1;
                        iSumR[iRowNo]++;
                        iSumC[iColNo]++;
                        if (iSumR[iRowNo] > iPointsR[iRowNo] && iSumC[iColNo] <= iPointsC[iColNo])
                            Set(iRowNo);
                        else if (iSumR[iRowNo] == iPointsR[iRowNo] && iRowNo < ROWS)
                            Set(iRowNo + 1);
                        Grid[iRowNo][iColNo] = 0;
                        iSumC[iColNo]--;
                    }
                }
            }
        }
    }
    return iFound;
}

int main(int argc, char** argv)
{
    if (!Set(0)) std::cout << "FAILURE" << std::endl;
    return 0;
}