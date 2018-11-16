'''
将练习5-4中的if-else 结构改为if-elif-else 结构。
    1.如果外星人是绿色的，就打印一条消息，指出玩家获得了5个点。
    2.如果外星人是黄色的，就打印一条消息，指出玩家获得了10个点。
    3.如果外星人是红色的，就打印一条消息，指出玩家获得了15个点。
    4.编写这个程序的三个版本，它们分别在外星人为绿色、黄色和红色时打印一条消息。
'''
# 1
alien_color = 'green'
if alien_color == 'green':
    print('you get 5 points !')
elif alien_color == 'yellow':
    print('you get 10 points !')
else:
    print('you get 15 points !')

# 2
alien_color = 'yellow'
if alien_color == 'green':
    print('you get 5 points !')
elif alien_color == 'yellow':
    print('you get 10 points !')
else:
    print('you get 15 points !')

# 3
alien_color = 'red'
if alien_color == 'green':
    print('you get 5 points !')
elif alien_color == 'yellow':
    print('you get 10 points !')
else:
    print('you get 15 points !')
