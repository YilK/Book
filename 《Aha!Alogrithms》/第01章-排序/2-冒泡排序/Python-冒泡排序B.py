n = int(input('数据量:'))
print('请输入数据:')
data_list = []  # 创建一个列表存储数据

for i in range(n):
    data = input('').strip().split(' ')
    data[1] = int(data[1])  # 转换数据类型
    data_list.append(data)


'''进行冒泡排序，降序'''
for i in range(1, n):  # n个数进行n-1躺排序
    for j in range(n - i):  # 两两比较的次数依次减小
        if data_list[j][1] < data_list[j + 1][1]:
            data_list[j][1], data_list[j + 1][1] = data_list[j + 1][1], \
                                                   data_list[j][1]

# 输出排序后的结果
print('排序后：')
for item in data_list:
    print(item)
