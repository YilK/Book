def quicksort(sort_list, left, right):
    if (left > right):
        return

    temp = sort_list[left]  # temp代表了基准值
    i = left
    j = right

    # 升序排列
    while i != j:
        # 先从右边开始寻找，因为是升序排列，所以要找到比基准值小的值
        while sort_list[j] >= temp and i < j:
            j = j - 1

        # 从左边开始寻找,找到比基准值大的值
        while sort_list[i] <= temp and i < j:
            i = i + 1

        if i < j:  # 将数据进行交换
            sort_list[i], sort_list[j] = sort_list[j], sort_list[i]

    # 结束循环，这时，i==j,将基准数归位
    sort_list[left], sort_list[j] = sort_list[j], temp

    quicksort(sort_list, left, j - 1)  # 继续处理左边，这是一个递归过程
    quicksort(sort_list, j + 1, right)  # 继续处理右边


sort_list = [6, 1, 2, 7, 9, 3, 4, 5, 10, 8]
quicksort(sort_list, 0, 9)
print(sort_list)
