// L1 和 L2 返回时需要有一个空的头结点
List Merge( List L1, List L2 )
{
    List head = (List)malloc(sizeof(struct Node)); // 合并链表的头指针
    List tail = head; // 合并链表的尾指针
    List tmpL1 = L1->Next; // 跟踪L1表中当前正进行比较的值
    List tmpL2 = L2->Next; // 跟踪L2表中当前正进行比较的值
    // 比较两个链表中元素的大小，并将小的元素接到tail结点后
    while (tmpL1 && tmpL2)
    {
        if (tmpL1->Data <= tmpL2->Data)
        {
            tail->Next = tmpL1;
            tmpL1 = tmpL1->Next;
        }
        else
        {
            tail->Next = tmpL2;
            tmpL2 = tmpL2->Next;
        }
        tail = tail->Next; // 更新tail结点
    }
    // 当跳出循环时，要么L1有剩余元素，要么L2有剩余元素，直接将剩余元素全部接到tail结点后
    if (tmpL1) tail->Next = tmpL1;
    else tail->Next = tmpL2;
    // 将 L1、L2 设置为空表
    L1->Next = NULL;
    L2->Next = NULL;

    return head;
}