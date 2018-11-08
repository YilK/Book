'''
有一家自助式餐馆，只提供五种简单的食品。请想出五种简单的食品，并将其存储在一个元组中。
    1.使用一个for 循环将该餐馆提供的五种食品都打印出来。
    2.尝试修改其中的一个元素，核实Python确实会拒绝你这样做。
    3.餐馆调整了菜单，替换了它提供的其中两种食品。请编写一个这样的代码块：给元组变量赋值，
        并使用一个for 循环将新元组的每个元素都打印出来。
'''

foods = ('apple', 'rice', 'fish', 'noodle', 'beef')
# 1
for food in foods:
    print(food, end=' ')
print('\n')


# 2
# food[1]='aaa'
# TypeError: 'str' object does not support item assignment

#3
foods=('apple', 'rice', 'pork', 'motton', 'beef')
for food in foods:
    print(food, end=' ')
