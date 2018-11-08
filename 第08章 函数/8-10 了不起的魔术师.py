'''
在你为完成练习8-9而编写的程序中，编写一个名为make_great() 的函数，
对魔术师列表进行修改，在每个魔术师的名字中都加入字样“the Great”。
调用函数show_magicians() ，确认魔术师列表确实变了。
'''


def make_great(magicians):
    for i in range(len(magicians)):  # 计算列表的长度，遍历列表
        magicians[i] = 'the Great ' + magicians[i]


def show_magicians(magicians):
    for name in magicians:
        print(name)


magicians = ['大卫·科波菲尔', '达里尔', '皮特.马维']  # 魔术师列表
make_great(magicians)  # 修改魔术师列表
show_magicians(magicians)  # 输出
