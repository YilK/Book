'''
选择你在本章编写的一个程序，在末尾添加几行代码，以完成如下任务。
    1.打印消息“The first three items in the list are:”，再使用切片来打印列表的前三个元素。
    2.打印消息“Three items from the middle of the list are:”，再使用切片来打印列表中间的三个元素。
    3.打印消息“The last three items in the list are:”，再使用切片来打印列表末尾的三个元素。
'''

numbers = list(range(1, 1000001))

#1
print('The first three items in the list are:'+str(numbers[:3]))

#2
print('Three items from the middle of the list are:'+str(numbers[4899:4902]))

#3
print('The last three items in the list are:'+str(numbers[-3:]))
