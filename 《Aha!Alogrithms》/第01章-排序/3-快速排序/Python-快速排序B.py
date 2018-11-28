def quick_sort(sort_list, left, right):
    i = left
    j = right
    base = sort_list[left]  # 将列表的首元素作为基准值

    while i <= j:

        while sort_list[i] < base:  # 挑出大于基准值的数据
            i = i + 1

        while sort_list[j] > base:  # 挑出小于基准值的数据
            j = j - 1

        if i < j:
            sort_list[i], sort_list[j] = sort_list[j], sort_list[i]
            # 交换完之后，移动到下个数，不移动会出现死循环
            j = j - 1
            i = i + 1

    # 退出循环，i>j
    if left < j:
        quick_sort(sort_list, left, j)

    if i < right:
        quick_sort(sort_list, i, right)


sort_list = [5, 2, 7, 3]
quick_sort(sort_list, 0, 3)
print(sort_list)
