numbers_str = input('输入一组需要排序的数字以空格为分隔:\n')  # 输入数据

numbers_list = numbers_str.strip().split(' ')  # 按空格分隔，但是里面的元素还是str类型的
numbers_list = [int(item) for item in numbers_list]  # 转换为int类型
# print(numbers_list)

'''冒泡排序的核心部分'''
for i in range(1, len(numbers_list)):  # n个数排序，需要进行n-1趟
    for j in range(0, len(numbers_list) - 1):  # len(numbers_list)-1表示比较的次数依次减少
        if numbers_list[j] < numbers_list[j + 1]:  # 降序排列
            numbers_list[j], numbers_list[j + 1] = numbers_list[j + 1], numbers_list[j]
            '''
            在这里交换值不需要使用中间变量,这是Python一个独特的地方
            '''
print(numbers_list)
