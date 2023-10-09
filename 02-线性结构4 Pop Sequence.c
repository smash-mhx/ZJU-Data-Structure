/* 模拟出栈入栈 */

#include <stdio.h>

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int stack[1001] = {0};
    int top = 0; // 栈顶标记
    int sq[1001]; // 存放出栈顺序

    while (k--)
    {
        top = 0;
        for (int i = 1; i <= n; i ++) scanf("%d", &sq[i]);
        for (int i = 1, j = 1; i <= n; i ++)
        {
            stack[++top] = i;
            if (top > m) break;
            /* 判断能否得到出栈*/
            while (top != 0 && stack[top] == sq[j])
            {
                top --;
                j ++;
            }
        }

        /* top 为 0,则说明 n 个数都可以顺利出栈 */
        if (top == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
