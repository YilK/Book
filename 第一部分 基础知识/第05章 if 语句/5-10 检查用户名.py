'''
按下面的说明编写一个程序，模拟网站确保每位用户的用户名都独一无二的方式。
    1.创建一个至少包含5个用户名的列表，并将其命名为current_users 。
    2.再创建一个包含5个用户名的列表，将其命名为new_users ，
        并确保其中有一两个用户名也包含在列表current_users 中。
    3.遍历列表new_users ，对于其中的每个用户名，都检查它是否已被使用。
        如果是这样，就打印一条消息，指出需要输入别的用户名；
        否则，打印一条消息，指 出这个用户名未被使用。
        确保比较时不区分大消息；换句话说，如果用户名'John' 已被使用，应拒绝用户名'JOHN' 。
'''
current_users = ['hjk', 'wy', 'Wll', 'llq', 'Ghd']
new_users = ['lzy', 'jhb', 'ghd', 'zy', 'Llq']

# method1
for i in range(len(current_users)):
    current_users[i] = current_users[i].lower()  # 将其改写为小写的形式
print(current_users)

# method2
'''
current_users=[item.lower() for user in currents_users]#解析列表
'''
# 遍历
for user in new_users:
    if user.lower() in current_users:  # 转化为小写
        print(user + ' 此用户名已被使用,你需要输入别的用户名！')
    else:
        print(user + ' 用户名未被使用！')
