'''
修改你在练习10-8中编写的except 代码块，让程序在文件不存在时一言不发。
'''

try:
    with open('cats.txt', encoding='UTF-8') as f:  # 打开文件
        for name in f:  # 遍历文件对象读取
            print(name.strip())  # 去除空行
        print('-------')

    with open('dogs.txt', encoding='UTF-8') as f:  # 打开文件
        name_list = f.readlines()  # 将各行信息存储在一个列表里
        for name in name_list:
            print(name.strip())
except FileNotFoundError:
    pass  # 什么都没发生一样继续运行
