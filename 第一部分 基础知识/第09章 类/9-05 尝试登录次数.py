'''
在为完成练习9-3而编写的User 类中，添加一个名为login_attempts 的属性。
编写一个名为increment_login_attempts() 的方法， 它将属性login_attempts 的值加1。
再编写一个名为reset_login_attempts() 的方法，它将属性login_attempts 的值重置为0。

根据User 类创建一个实例，再调用方法increment_login_attempts() 多次。
打印属性login_attempts 的值，确认它被正确地递增；然后，
调用方法reset_login_attempts() ，并再次打印属性login_attempts的值，确认它被重置为0。
'''


class User():
    def __init__(self, first_name, last_name, **user_info):
        """初始化"""
        self.message = {}
        self.message['first_name'] = first_name
        self.message['last_name'] = last_name
        self.message['login_attempts'] = 0  # 添加属性e
        for key, value in user_info.items():
            self.message[key] = value

    def describe_user(self):
        """打印出用户的信息"""
        for key, value in self.message.items():
            print(str(key) + ':' + str(value))

    def greet_user(self):
        """问候"""
        greet_message = 'Hello' + self.message['first_name'] + \
                        self.message['last_name']
        print(greet_message)

    def increment_login_attempts(self):
        """将属性login_attempts 的值加1"""
        self.message['login_attempts'] += 1

    def reset_login_attempts(self):
        """将属性login_attempts 的值重置为0"""
        self.message['login_attempts'] = 0


user = User('h', 'jk', age=12, hobby='play basketba')  # 创建实例
print(user.message['login_attempts'])

for i in range(3):
    user.increment_login_attempts()  # 将属性login_attempts 的值加1
print(user.message['login_attempts'])

user.reset_login_attempts()  # 将属性login_attempts 的值重置为0
print(user.message['login_attempts'])

