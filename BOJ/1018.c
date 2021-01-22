#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define minFinder(a,b) a < b ? a : b

int main()
{
    int N, M;
    int min = 64;
    int cntB = 0; int cntW = 0;
    scanf("%d %d", &N, &M);
    // N:row  M:col
    char board[50][50];
    for (int i = 0; i < N; i++)
        scanf("%s", &board[i]);

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            cntB = 0;
            cntW = 0;
            for (int a = i; a < i + 8; a++) {
                for (int b = j; b < j + 8; b++) {
                    if ((a + b) % 2 == 0) {
                        if (board[a][b] == 'B')
                            cntW++;
                        else
                            cntB++;
                    }
                    else {
                        if (board[a][b] == 'B')
                            cntB++;
                        else
                            cntW++;
                    }
                }
            }
            min = minFinder(min, cntB);
            min = minFinder(min, cntW);
        }
    }

    printf("%d", min);
    return 0;
}