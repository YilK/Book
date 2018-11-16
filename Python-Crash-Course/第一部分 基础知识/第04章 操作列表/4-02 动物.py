'''
想出至少三种有共同特征的动物，将这些动物的名称存储在一个列表中，再使用for 循环将每种动物的名称都打印出来。
    1.修改这个程序，使其针对每种动物都打印一个句子，如“A dog would make a great pet”。
    2.在程序末尾添加一行代码，指出这些动物的共同之处，
        如打印诸如“Any of these animals would make a great pet!”这样的句子。
'''
animals = ['dog', 'pig', 'cat']
for animal in animals:
    print(animal)

# 1
for animal in animals:
    print('A ' + animal + ' would make a great pet')

# 2
print('Any of these animals would make a great pet!')
