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