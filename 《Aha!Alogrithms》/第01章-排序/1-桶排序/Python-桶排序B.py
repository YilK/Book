# 对数据范围在0-1000的整数进行排序

book = [0] * 1000  # 要对范围为0-1000的整数进行排序，需要建立1000个桶，并初始化桶中的旗子数为0

amounts = int(input('请输入你需要对几个整数进行排序:'))

print('请输入数据(以回车分隔)\n')

for i in range(amounts):
    number = int(input())  # 读取数字到变量number中
    book[number] += 1  # 对编号为number的桶中的旗子数+1

# 将排序的好的结果打印出来
for i in range(len(book)):  # 依次判断编号为0-1000的桶
    if book[i] > 0:  # 如果桶中有旗子
        for j in range(book[i]):  # 有几个旗子，就将桶的编号打印几遍
            print(i)
