'''
假设在游戏中刚射杀了一个外星人，请创建一个名为alien_color 的变量，并将其设置为'green' 、'yellow' 或'red' 。
    1.编写一条if 语句，检查外星人是否是绿色的；如果是，就打印一条消息，指出玩家获得了5个点。
    2.编写这个程序的两个版本，在一个版本中上述测试通过了，而在另一个版本中未通过（未通过测试时没有输出）。
'''
alien_color = 'green'

# 1
if alien_color == 'green':
    print('you get 5 points !')
# 2
if alien_color == 'yellow':
    print('you get nothing !')
