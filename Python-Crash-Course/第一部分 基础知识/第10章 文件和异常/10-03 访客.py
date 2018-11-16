'''
编写一个程序，提示用户输入其名字；用户作出响应后，将其名字写入到文件guest.txt中。
'''

filename = 'guest.txt'
with open(filename, 'w', encoding='UTF-8') as f:#'w' 写入模式
    while True:
        name = input('请输入用户名(输入q退出程序):')
        if name == 'q':
            break
        else:
            f.write(name+'\n')

