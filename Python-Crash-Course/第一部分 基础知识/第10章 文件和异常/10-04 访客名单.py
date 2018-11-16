'''
编写一个while 循环，提示用户输入其名字。用户输入其名字后，在屏幕上打印一句问候语，
并将一条访问记录添加到文件guest_book.txt中。确保这 个文件中的每条记录都独占一行。
'''

filename='guest_book.txt'
with open(filename, 'w', encoding='UTF-8') as f:#'w' 写入模式
    while True:
        name = input('请输入用户名(输入q退出程序):')
        if name == 'q':
            break
        else:
            f.write(name+'\n')
            print('Hello,'+name)

