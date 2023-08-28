// 动态规划算法
#include <stdio.h>

int MaxSubSum(int a[], int N, int* first, int* last);

int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int first = 0;
    int last = N - 1;
    int max = MaxSubSum(a, N, &first, &last);
    printf("%d %d %d", max, a[first], a[last]);
    return 0;
}

int MaxSubSum(int a[], int N, int* first, int* last)
{
    int this = 0, max = -1;
    int tmpFirstIndex = 0;
    for (int i = 0; i < N; i++)
    {
        this += a[i];
        if (this > max)
        {
            max = this;
            *first = tmpFirstIndex;
            *last = i;
        }
        else if (this < 0) 
        {
            this = 0;
            tmpFirstIndex = i + 1;
        }
    }
    if (max < 0) max = 0;
    return max;
}