'''
将最新的Restaurant 类存储在一个模块中。在另一个文件中，导入Restaurant 类，
创建一个Restaurant 实例，并调 用Restaurant 的一个方法，以确认import 语句正确无误
'''
from restaurant import Restaurant

first_restaurant = Restaurant('全聚德', '烤鸭')  # 创建实例
first_restaurant.describe_restaurant()  # 调用方法
first_restaurant.open_restaurant()
