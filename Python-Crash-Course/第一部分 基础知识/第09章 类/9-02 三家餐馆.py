'''
根据你为完成练习9-1而编写的类创建三个实例，并对每个实例调用方法describe_restaurant() 。
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

restaurant_one=Restaurant('小龙坎','火锅')
restaurant_one.describe_restaurant()
print('------')
restaurant_two=Restaurant('一点点','奶茶')
restaurant_two.describe_restaurant()
print('------')
restaurant_three=Restaurant('KFC','汉堡')
restaurant_three.describe_restaurant()
