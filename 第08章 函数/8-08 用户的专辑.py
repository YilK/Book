'''
在为完成练习8-7编写的程序中，编写一个while 循环，
让用户输入一个专辑的歌手和名称。获取这些信息后，使用它们来调用函 数make_album() ，
并将创建的字典打印出来。在这个while 循环中，务必要提供退出途径。
'''


def make_album(singer, album):
    return {'歌手': singer, '专辑名': album}


while True:
    singer = input('输入歌手的名字(输入exit,退出程序):')  # 输入
    if singer == 'exit':  # 判断
        break

    album = input('输入专辑的名称(输入exit,退出程序):')  # 输入
    if album == 'exit':
        break
    print(make_album(singer, album))
