'''
在6.3.1节编写的程序favorite_languages.py中执行以下操作。
    1.创建一个应该会接受调查的人员名单，其中有些人已包含在字典中，而其他人未包含在字典中。
    2.遍历这个人员名单，对于已参与调查的人，打印一条消息表示感谢。对于还未参与调查的人，打印一条消息邀请他参与调查。
'''
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python'
}

# 应该会接受调查的人的名单
people = ['jen', 'sarah']

# 遍历
for key in favorite_languages:
    if key in people:  # 使用 in 关键字来判断
        print('Thanks,', key + '.')
    else:
        print('Please take part in investigtion,', key + '.')
