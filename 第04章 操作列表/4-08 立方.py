'''
将同一个数字乘三次称为立方。例如，在Python中，2的立方用2**3 表示。
请创建一个列表，其中包含前10个整数（即1~10）的立方，再使用一个for 循 环将这些立方数都打印出来。
'''
numbers=[i**3 for i in range(1,11)]
for number in numbers:
    print(number)



#4-09 立方解析使用这个方法就好了