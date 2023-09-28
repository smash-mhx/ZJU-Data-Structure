Position BinarySearch(List L, ElementType X)
{
    int Head = 1; // 待查找顺序表的表头位置坐标
    int Middle = L->Last / 2; // 待查找顺序表的中间位置坐标
    int result = NotFound; // 返回的结果
    while (1)
    {
        if (L->Data[Middle] > X) // 如果X可能在左边
        {
            Middle = (Head + Middle) / 2; // 更新中间位置坐标
        }
        else if (L->Data[Middle] < X) // 如果X可能在左边在右边
        {
            Head = Middle; // 更新表头位置坐标
            Middle = (Head + L->Last + 1) / 2; // 更新中间位置坐标
        }
        else // 找到X，跳出循环
        {
            result = Middle;
            break;
        }
        // 检查头部和尾部的边界条件
        if (Middle == Head)
            if (L->Data[Middle] != X) break;
    }
    return result;
}