'''
创建一个包含魔术师名字的列表，并将其传递给一个名为show_magicians() 的函数，
这个函数打印列表中每个魔术师的名字。
'''


def show_magicians(magicians):
    for name in magicians:
        print(name)


magicians = ['大卫·科波菲尔', '达里尔', '皮特.马维']
show_magicians(magicians)  # 传入列表
