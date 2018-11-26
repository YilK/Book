# 排序0-10的整数

book = [0] * 10  # 10个桶 初始化为0
print(book)

print('输入5个整数(0-10)以回车分隔:')

for i in range(5):  # 循环输入数据
    a = int(input())
    book[a] += 1  # 编号为t的桶中的旗子+1
print(book)

for i in range(len(book)):  # 遍历所有的桶
    if book[i] > 0:  # 如果桶中的旗子不为0
        for j in range(book[i]):  # 将桶的编号打印，打印的次数为桶中的旗子数
            print(i)
