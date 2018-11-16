'''
创建一个名为Restaurant 的类，其方法__init__() 设置两个属性：
restaurant_name 和cuisine_type 。
创建一个名 为describe_restaurant() 的方法和一个名为open_restaurant() 的方法，
其中前者打印前述两项信息，而后者打印一条消息，指出餐馆正在营业

根据这个类创建一个名为restaurant 的实例，分别打印其两个属性，再调用前述两个方法。
'''


class Restaurant():
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name  # 餐馆的名称
        self.cuisine_type = cuisine_type  # 菜肴的种类

    def describe_restaurant(self):
        print('餐馆的名称:', self.restaurant_name)
        print('菜肴的种类:', self.cuisine_type)

    def open_restaurant(self):
        print('餐厅正在营业~~~')


first_restaurant = Restaurant('全聚德', '烤鸭')  # 创建实例
first_restaurant.describe_restaurant()  # 调用方法
first_restaurant.open_restaurant()
