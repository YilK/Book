'''
在为完成练习5-8编写的程序中，添加一条if 语句，检查用户名列表是否为空。
    1.如果为空，就打印消息“We need to find some users!”。
    2.删除列表中的所有用户名，确定将打印正确的消息。
'''
users = ['admin', 'hjk', 'wy', 'llq', 'wll']

# 删除列表中所有的用户名
for i in range(len(users)):  # 循环的次数为列表的长度
    users.pop()  # 每一次都删除列表末尾的元素

if users == []:  # 如果列表为空
    print('We need to find some users!')
else:
    for user in users:
        if user == 'admin':
            print('Hello admin, would you like to see a status report?')
        else:
            print('Hello ' + user + ', thank you for logging in again')
