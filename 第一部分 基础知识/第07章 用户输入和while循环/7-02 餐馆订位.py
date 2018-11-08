'''
编写一个程序，询问用户有多少人用餐。如果超过8人，
就打印一条消息，指出没有空桌；否则指出有空桌。
'''
number = input('How many people?')
if int(number) > 8:
    print('There are no seats.')
else:
    print('follow me.')
