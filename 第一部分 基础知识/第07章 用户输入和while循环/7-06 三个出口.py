'''
以另一种方式完成练习7-4或练习7-5，在程序中采取如下所有做法。
    1.在while 循环中使用条件测试来结束循环。
    2.使用变量active 来控制循环结束的时机。
    3.使用break 语句在用户输入'quit' 时退出循环。
'''
# 在while 循环中使用条件测试来结束循环。
age = ''  # 先赋值,进入循环
while age != 'quit':  # age不等于quit时进入循环
    age = input('1.请输入年龄查询票价(输入quit退出查询):')
    if age == 'quit':
        print('退出查询')
        continue
    elif int(age) < 3:
        print('票价为:', '免费')
    elif int(age) < 12:
        print('票价为:', '10美元')
    else:
        print('票价为:', '15美元')

# 使用变量active 来控制循环结束的时机。
active = True
while active:
    age = input('2.请输入年龄查询票价(输入quit退出查询):')  # 输入
    # 判断
    if age == 'quit':
        print('退出查询')
        active = False
    elif int(age) < 3:
        print('票价为:', '免费')
    elif int(age) < 12:
        print('票价为:', '10美元')
    else:
        print('票价为:', '15美元')

# 使用break 语句在用户输入'quit' 时退出循环。
while True:
    age = input('3.请输入年龄查询票价(输入quit退出查询):')
    if age == 'quit':
        print('退出查询')
        break  # 退出循环
    elif int(age) < 3:
        print('票价为:', '免费')
    elif int(age) < 12:
        print('票价为:', '10美元')
    else:
        print('票价为:', '15美元')
