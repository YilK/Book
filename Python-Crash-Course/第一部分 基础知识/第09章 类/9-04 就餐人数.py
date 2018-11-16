'''
在为完成练习9-1而编写的程序中，添加一个名为number_served 的属性，并将其默认值设置为0。
根据这个类创建一个名为restaurant 的实 例；打印有多少人在这家餐馆就餐过，
然后修改这个值并再次打印它。

1.添加一个名为set_number_served() 的方法，它让你能够设置就餐人数。
调用这个方法并向它传递一个值，然后再次打印这个值。

2.添加一个名为increment_number_served() 的方法，它让你能够将就餐人数递增。
调用这个方法并向它传递一个这样的值：你认为这家餐馆每天可能接待的就 餐人数。
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


restaurant = Restaurant('全聚德', '烤鸭')
print(restaurant.number_serves)  # 访问属性，查看就餐过的人数
restaurant.number_serves = 123  # 修改属性
print(restaurant.number_serves)  # 访问修改后的属性
print('--------')
restaurant.set_number_served(23)  # 设置就餐人数
print(restaurant.number_serves)  # 输出人数
print('--------')
restaurant.increment_number_served(17)  # 增加就餐人数
print(restaurant.number_serves)
