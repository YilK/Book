'''
在本节中，为节省篇幅，程序foods.py的每个版本都没有使用for 循环来打印列表。请选择一个版本的foods.py，
在其中编写两个for 循环，将各 个食品列表都打印出来。
'''

my_foods = ['pizza', 'falafel', 'carrot cake']

friend_foods = my_foods[:]

my_foods.append('cannoli')

friend_foods.append('ice cream')

for food in my_foods:
    print(food)

for food in friend_foods:
    print(food)
