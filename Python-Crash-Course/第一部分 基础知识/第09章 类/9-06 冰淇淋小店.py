'''
冰淇淋小店是一种特殊的餐馆。编写一个名为IceCreamStand 的类，
让它继承你为完成练习9-1或练习9-4而编写的Restaurant 类。
这两个版 本的Restaurant 类都可以，挑选你更喜欢的那个即可。
添加一个名为flavors 的属性，用于存储一个由各种口味的冰淇淋组成的列表。
编写一个显示这些冰淇淋 的方法。创建一个IceCreamStand 实例，并调用这个方法。
'''


class Restaurant():

    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name  # 餐馆的名称
        self.cuisine_type = cuisine_type  # 菜肴的种类
        self.number_serves = 0  # 添加属性，设置为0--->就餐过的人数

    def describe_restaurant(self):
        """打印餐馆的信息"""
        print('餐馆的名称:', self.restaurant_name)
        print('菜肴的种类:', self.cuisine_type)

    def open_restaurant(self):
        """打印出餐厅正在营业"""
        print('餐厅正在营业~~~')

    def set_number_served(self, amount):
        """设置就餐人数"""
        self.number_serves = amount

    def increment_number_served(self, increment_amount):
        """增加就餐人数"""
        self.number_serves += increment_amount


class IceCreamStand(Restaurant):  # 继承了Restaurant类

    def __init__(self, restaurant_name, cuisine_type):
        """初始化父类的属性"""
        super().__init__(restaurant_name, cuisine_type)  # 给父类的所有属性赋值
        self.flavors = ['香草', '抹茶', '巧克力', '牛奶']

    def show_all(self):
        """显示冰激凌所有的口味"""
        print('所有的冰激凌口味:')
        for type in self.flavors:
            print(type)


icecream = IceCreamStand('冰淇淋小店', '冰激凌')
icecream.show_all()
