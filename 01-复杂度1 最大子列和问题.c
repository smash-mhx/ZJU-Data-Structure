// 动态规划算法
#include <stdio.h>

int MaxSeqSum(int a[], int N);

int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
        scanf("%d",&a[i]);

    printf("%d", MaxSeqSum(a, N));
    
    return 0;
}

int MaxSeqSum(int a[], int N)
{
    int MaxSum = 0, ThisSum = 0;
    for (int i = 0; i < N; i++)
    {
        ThisSum += a[i];
        if (ThisSum > MaxSum) MaxSum = ThisSum;
        else if (ThisSum < 0) ThisSum = 0;
    }
    return MaxSum;
}