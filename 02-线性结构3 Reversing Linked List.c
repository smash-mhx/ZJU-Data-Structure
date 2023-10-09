/* 用结构数组模拟链表 */
#include <stdio.h>
#define MAXSIZE 100001

struct Node
{
	int data;
	int next;
} link[MAXSIZE];

void read(int n)
{
	while (n--)
	{
		int addr, data,next;
		scanf("%d %d %d", &addr, &data, &next);
		link[addr].data = data;
		link[addr].next = next;
	}
}

int reverseLink(struct Node link[], int head, int k)
{
	/* 统计可用的节点数 */
	int sum = 0;
	int nxt = link[head].next;
	while (nxt != -1)
	{
		sum++;
		nxt = link[nxt].next;
	}
	
	int curr = link[head].next;
	int prev = -1;
	int p0 = head; // p0 为待反转段的上一个结点
	for (int t = 0; t < sum / k; t++)
	{
		
		for (int i = 0; i < k; i++)
		{
			nxt = link[curr].next;
			link[curr].next = prev;
			prev = curr;
			curr = nxt;
		}
		
		int tp = link[p0].next; // tp 临时记录 p0 要去的结点
		link[tp].next = curr;
		link[p0].next = prev;
		p0 = tp;
		
	}
	
	return link[head].next;
}

void printLink(int head)
{
	/* 输出 */
	int x;
	for (x = head; link[x].next != -1; x = link[x].next)
	{
		printf("%05d %d %05d\n", x, link[x].data, link[x].next);
	}
	printf("%05d %d %d", x, link[x].data, link[x].next);
	
}
int main()
{
	int head, n, k;
	scanf("%d %d %d", &head, &n, &k);
	read(n);
	
	/* 设置一个空的头结点 */
	link[MAXSIZE - 1].data = 0;
	link[MAXSIZE - 1].next = head;
	head = MAXSIZE - 1;
	
	int result = reverseLink(link, head, k);
	printLink(result);
	
	return 0;
}
