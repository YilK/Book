'''
创建一个名为sandwich_orders 的列表，在其中包含各种三明治的名字；
再创建一个名为finished_sandwiches 的空列表。
遍历列 表sandwich_orders ，对于其中的每种三明治，都打印一条消息，
如I made your tuna sandwich ，并将其移到列表finished_sandwiches 。
所有三明治都制作好后，打印一条消息，将这些三明治列出来。
'''
sandwich_orders = ['beef_sandwich',
                   'egg_sandwich',
                   'pork_sanwich',
                   'apple_sandwich']
finished_sandwiches = []  # 空列表
# 遍历
while sandwich_orders:
    ok_sandwiches = sandwich_orders.pop(0)  # 删除列表中的元素，并且返回
    print(ok_sandwiches + 'is ok!')  # 打印
    finished_sandwiches.append(ok_sandwiches)  # 添加入列表
print('所有的三明治:',finished_sandwiches)

