'''
使用为完成练习7-8而创建的列表sandwich_orders ，
并确保'beef_sandwich' 在其中至少出现了三次。
在程序开头附近添加 这样的代码：打印一条消息，指出熟食店的牛肉三明治卖完了；
再使用一个while 循环将列表sandwich_orders 中的'beef_sandwich' 都删除。
确认最终的列 表finished_sandwiches 中不包含'beef_sandwich' 。
'''
sandwich_orders = ['beef_sandwich',
                   'egg_sandwich',
                   'pork_sanwich',
                   'beef_sandwich',
                   'apple_sandwich',
                   'beef_sandwich']
finished_sandwiches = []  # 空列表
print('beef_sandwich 都卖完啦！！！！')

# 在while循环中删除
while 'beef_sandwich' in sandwich_orders:
    sandwich_orders.remove('beef_sandwich')  # remove(),要知道删除的元素是什么
print(sandwich_orders)  # 查看

# 遍历
while sandwich_orders:
    ok_sandwiches = sandwich_orders.pop(0)  # 删除列表中的元素，并且返回
    print(ok_sandwiches + 'is ok!')  # 打印
    finished_sandwiches.append(ok_sandwiches)  # 添加入列表
print('所有的三明治:', finished_sandwiches)
