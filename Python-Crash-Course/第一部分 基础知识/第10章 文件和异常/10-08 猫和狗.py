'''
创建两个文件cats.txt和dogs.txt，在第一个文件中至少存储三只猫的名字，
在第二个文件中至少存储三条狗的名字。编写一个程序，尝试读取这些文件，
并将其内容打印到屏幕上。将这些代码放在一个try-except 代码块中，
以便在文件不存在时捕获FileNotFound 错误，并打印一条友好的消息。
将其中一个文件 移到另一个地方，并确认except 代码块中的代码将正确地执行。
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
    print('找不到文件')
