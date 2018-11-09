class Privileges():
    def __init__(self):
        """初始化"""
        self.privileges = ['can add post', 'can delete post', 'can ban user']

    def show_privileges(self):
        """显示所有的特权"""
        print('将实例用作属性~~~~')
        print("特权:")
        for item in self.privileges:
            print(item)


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
        self.privileges = Privileges()  # 将Privileges实例作为Admin的属性
        # 每个Admin()都好包含一个自动创建的Privileges实例
