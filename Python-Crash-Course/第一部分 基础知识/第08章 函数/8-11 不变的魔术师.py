'''
修改你为完成练习8-10而编写的程序，在调用函数make_great() 时，
向它传递魔术师列表的副本。由于不想修改原始列表，请返回修改后的列表，
并将其存储到另一个列表中。分别使用这两个列表来调用show_magicians() ，
确认一个列表包含的是原来的魔术师名字，而另一个列表包含的是添加了字 样“the Great”的魔术师名字。
'''


def make_great(magicians):
    for i in range(len(magicians)):  # 计算列表的长度，遍历列表
        magicians[i] = 'the Great ' + magicians[i]
    return magicians


def show_magicians(magicians):
    for name in magicians:
        print(name)


A_magicians = ['大卫·科波菲尔', '达里尔', '皮特.马维']  # 魔术师列表
B_magicians = make_great(A_magicians[:])  # 传入副本
show_magicians(A_magicians)  # 输出
show_magicians(B_magicians)
