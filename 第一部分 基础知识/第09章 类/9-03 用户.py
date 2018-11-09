'''
创建一个名为User 的类，其中包含属性first_name 和last_name ，
还有用户简介通常会存储的其他几个属性。在类User 中定义一个名 为describe_user() 的方法，
它打印用户信息摘要；再定义一个名为greet_user() 的方法，它向用户发出个性化的问候。

创建多个表示不同用户的实例，并对每个实例都调用上述两个方法。
'''


class User():
    def __init__(self, first_name, last_name, **user_info):
        """初始化"""
        self.message = {}
        self.message['first_name'] = first_name
        self.message['last_name'] = last_name
        for key, value in user_info.items():
            self.message[key] = value

    def describe_user(self):
        """打印出用户的信息"""
        for key, value in self.message.items():
            print(str(key) + ':' + str(value))

    def greet_user(self):
        """问候"""
        greet_message = 'Hello ' + self.message['first_name'] + \
                        self.message['last_name']
        print(greet_message)


user_1 = User('h', 'jk', age=12, sex='male')
user_1.describe_user()
user_1.greet_user()
print('------')
user_2 = User('h', 'jj', age=23, sex='female', hobby='painting')
user_2.describe_user()
user_2.greet_user()
print('------')
user_3 = User('h', 'jk')
user_3.describe_user()
user_3.greet_user()