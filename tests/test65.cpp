#include <algorithm>
#include <iomanip>
#include <iostream>
#include <valarray>
#ifdef __linux__
#include <malloc.h>
#elif __APPLE__
#include <sys/malloc.h>
#endif

#define maxSize 20
#define INF 1000

int t = 1;
int Board[100][100];

void chessBoard(int tr, int tc, int dr, int dc, int sz)
{
    if (sz == 1)
    {
        return;
    }
    int tile = t++;
    sz /= 2;
    if (dr < tr + sz && dc < tc + sz)
    {
        chessBoard(tr, tc, dr, dc, sz);
    }
    else
    {
        Board[tr + sz - 1][tc + sz - 1] = tile;
        chessBoard(tr, tc, tr + sz - 1, tc + sz - 1, sz);
    }
    if (dr < tr + sz && dc >= tc + sz)
    {
        chessBoard(tr, tc + sz, dr, dc, sz);
    }
    else
    {
        Board[tr + sz - 1][tc + sz] = tile;
        chessBoard(tr, tc + sz, tr + sz - 1, tc + sz, sz);
    }
    if (dr >= tr + sz && dc < tc + sz)
    {
        chessBoard(tr + sz, tc, dr, dc, sz);
    }
    else
    {
        Board[tr + sz][tc + sz - 1] = tile;
        chessBoard(tr + sz, tc, tr + sz, tc + sz - 1, sz);
    }
    if (dr >= tr + sz && dc >= tc + sz)
    {
        chessBoard(tr + sz, tc + sz, dr, dc, sz);
    }
    else
    {
        Board[tr + sz][tc + sz] = tile;
        chessBoard(tr + sz, tc + sz, tr + sz, tc + sz, sz);
    }
}

int main(int argc, char** argv)
{
    chessBoard(0, 0, 0, 1, 4);
    // 二维数组打印
    std::cout << "棋盘为" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << std::setw(3) << Board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}