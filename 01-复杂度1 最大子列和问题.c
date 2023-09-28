#include <stdio.h>

int MaxSubseqSum(int List[], int N);

int main()
{
    int N; // 输入N个整数
    scanf("%d", &N); // 读入N的值
    int List[N]; // 创建长度为N的数组
    // 读入N个整数到数组中
    for (int i = 0; i < N; i++)
        scanf("%d", &List[i]);
    printf("%d", MaxSubseqSum(List, N));
    return 0;
}

int MaxSubseqSum(int List[], int N)
{
    int thisSum = 0, MaxSum = 0; // 一个当前最大值，一个最终最大值
    for (int i = 0; i < N; i++)
    {
        thisSum += List[i];
        if (thisSum > MaxSum) MaxSum = thisSum; // 如果当前值大于最大值，更新最大值
        else if (thisSum < 0) thisSum = 0; // 如果当前值小于0，则不可能令后面的值增大，故舍去
    }
    return MaxSum;
}