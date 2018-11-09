'''
管理员是一种特殊的用户。编写一个名为Admin的类，
让它继承你为完成练习9-3或练习9-5而编写的User 类。添加一个名为privileges 的属性，
用于存储一个由字符串（如"can add post" 、"can delete post" 、"can ban user" 等）组成的列表。
编写一个名为show_privileges() 的方法，它显示管理员的权限。创建一个Admin 实例，并调用这个方法。
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
        greet_message = 'Hello' + self.message['first_name'] + \
                        self.message['last_name']
        print(greet_message)


class Admin(User):

    def __init__(self, first_name, last_name='', **user_info):  # last_name=''默认值
        """初始化父类的方法"""
        super().__init__(first_name, last_name, **user_info)
        # 添加属性
        self.privileges = ['can add post', 'can delete post', 'can ban user']

    def show_privileges(self):
        """显示管理员权限"""
        print('管理员的权限:')
        for item in self.privileges:
            print(item)


admin1 = Admin('admin1')
admin1.show_privileges()
admin1.describe_user()
