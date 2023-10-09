#include <stdio.h>

/* 使用链表来表示多项式 */
typedef struct PolyNode* PtrToPolyNode;
struct PolyNode
{
    int Coef; // 系数
    int Expon; // 指数
    PtrToPolyNode Next; // 指向下一个结点
};

PtrToPolyNode Read(int i); // 读入项数为 i 的多项式
PtrToPolyNode Multi(PtrToPolyNode L1, PtrToPolyNode L2);
PtrToPolyNode Add(PtrToPolyNode L1, PtrToPolyNode L2);
void Put(PtrToPolyNode L);
void Attach(int Coef, int Expon, PtrToPolyNode *ptr); // 添加结点至链尾

int main()
{
    PtrToPolyNode L1;// 多项式L1
    PtrToPolyNode L2; // 多项式L2
    PtrToPolyNode L3; // 乘积多项式
    PtrToPolyNode L4; // 和多项式
    int i; // 多项式非零项的个数
    
    scanf("%d", &i);
    L1 = Read(i);
    scanf("%d", &i);
    L2 = Read(i);
    // Put(L1);
    // Put(L2);
    
    L3 = Multi(L1, L2);
    L4 = Add(L1, L2);
    Put(L3);
    Put(L4);
    return 0;
}

PtrToPolyNode Read(int i)
{
    int tmpCoef, tmpExpon;
    PtrToPolyNode head = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
    head->Next = NULL;
    PtrToPolyNode rear = head;

    while(i--)
    {
        scanf("%d %d", &tmpCoef, &tmpExpon);
        Attach(tmpCoef, tmpExpon, &rear);
    }

    PtrToPolyNode tp = head;
    head = head->Next;
    free(tp);

    return head;
}

PtrToPolyNode Multi(PtrToPolyNode L1, PtrToPolyNode L2)
{
    if (!L1 || !L2) return NULL;
    
    PtrToPolyNode head = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
    head->Next = NULL;
    PtrToPolyNode rear = head;
    PtrToPolyNode t1 = L1, t2 = L2;
    
    while(t2)
    {
        Attach(t1->Coef * t2->Coef, t1->Expon + t2->Expon, &rear);
        t2 = t2->Next;
    }
    t1 = t1->Next;

    while (t1)
    {
        t2 = L2; rear = head;
        while (t2)
        {
            int e = t1->Expon + t2->Expon;
            int c = t1->Coef * t2->Coef;
            while (rear->Next && rear->Next->Expon > e)
                rear = rear->Next;
            if (rear->Next && rear->Next->Expon == e)
            {
                if (rear->Next->Coef + c) rear->Next->Coef += c;
                else
                {
                    PtrToPolyNode t = rear->Next;
                    rear->Next = t->Next;
                    free(t);
                }
            }
            else
            {
                PtrToPolyNode t = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
                t->Coef = c; t->Expon = e;
                t->Next = rear->Next;
                rear->Next = t; rear = rear->Next;
            }
            t2 = t2->Next;
        }
        t1 = t1->Next;
    }

    t2 = head; head = head->Next; free(t2);

    return head;
}

PtrToPolyNode Add(PtrToPolyNode L1, PtrToPolyNode L2)
{
    PtrToPolyNode head = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
    PtrToPolyNode t1 = L1, t2 = L2;
    PtrToPolyNode rear = head;

    while(t1 && t2)
    {
        if (t1->Expon > t2->Expon)
        {
            Attach(t1->Coef, t1->Expon, &rear);
            t1 = t1->Next;
        }
        else if (t1->Expon < t2->Expon)
        {
            Attach(t2->Coef, t2->Expon, &rear);
            t2 = t2->Next;
        }
        else
        {
            int sum = t1->Coef + t2->Coef;
            if (sum) Attach(sum, t1->Expon, &rear);
            t1 = t1->Next;
            t2 = t2->Next;
        }
    }

    for ( ; t1; t1=t1->Next) Attach(t1->Coef, t1->Expon, &rear);
    for ( ; t2; t2=t2->Next) Attach(t2->Coef, t2->Expon, &rear);

    rear->Next = NULL;
    PtrToPolyNode tp = head;
    head = head->Next;
    free(tp);

    return head;
}

/* 链表的遍历操作 */
void Put(PtrToPolyNode L)
{
    if (!L) 
    {
        printf("0 0\n");
        return ;
    }
    int flag = 0;
    while (L)
    {
        if (!flag) flag = 1;
        else printf(" ");
        printf("%d %d", L->Coef, L->Expon);
        L = L->Next;
    }
    printf("\n");
}

void Attach(int Coef, int Expon, PtrToPolyNode *ptr)
{
    /* 创建一个新结点，并赋值*/
    PtrToPolyNode tp = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
    tp->Next = NULL;
    tp->Coef = Coef;
    tp->Expon = Expon;

    /* 将新结点加之链尾，并更新链尾指针*/
    (*ptr)->Next = tp;
    (*ptr) = tp;
}