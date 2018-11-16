'''
在你为完成练习4-1而编写的程序中，创建比萨列表的副本，并将其存储到变量friend_pizzas 中，再完成如下任务。
    1.在原来的比萨列表中添加一种比萨。
    2.在列表friend_pizzas 中添加另一种比萨。
    3.核实你有两个不同的列表。为此，打印消息“My favorite pizzas are:”，
        再使用一个for 循环来打印第一个列表；
        打印消息“My friend's favorite pizzas are:”，
        再使用一 个for 循环来打印第二个列表。核实新增的比萨被添加到了正确的列表中。
'''

pizza_list = ['Seafood pizza',
              'Sausage pizza',
              'Cheese pizza',
              'Beef pizza',
              'Corn pizza',
              'Chicken pizza']

# 1
pizza_list.append('Pork pizza')

# 2
friend_pizzas = pizza_list[:]  # 创建了一个副本，并不是一个视图
friend_pizzas.append('Mutton pizza')

# 3
print('My favorite pizzas are:')
for pizza in pizza_list:
    print(pizza)

print("My friend's favorite pizzas are:")
for pizza in friend_pizzas:
    print(pizza)
