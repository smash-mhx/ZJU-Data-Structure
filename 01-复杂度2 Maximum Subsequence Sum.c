#include <stdio.h>

int MaxSubseqSum(int List[], int N, int* first, int* last);

int main()
{
    int N; // 一共有N个数据
    scanf("%d", &N);
    int List[N];
    for (int i = 0; i < N;i++) 
        scanf("%d", &List[i]); // 读入N个数据至数组中

    int first = 0; // 最大子列和的第一个数的坐标
    int last = N - 1; // 最大子列和的最后一个数的坐标
    int maxSum = MaxSubseqSum(List, N, &first, &last);
    printf("%d %d %d", maxSum, List[first], List[last]);
    return 0;
}

int MaxSubseqSum(int List[], int N, int* first, int* last)
{
    int thisSum = 0, maxSum = -1;
    int tmpIndex = 0; // 临时的第一个数的下标
    for (int i = 0; i < N; i++)
    {
        thisSum += List[i];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            *first = tmpIndex;
            *last = i;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
            tmpIndex = i + 1;
        }
    }
    if (maxSum < 0) maxSum = 0;
    
    return maxSum;
}