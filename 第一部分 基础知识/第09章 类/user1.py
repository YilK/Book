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
