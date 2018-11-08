'''
创建一个名为favorite_places 的字典。在这个字典中，将三个人的名字用作键；对于其中的每个人，
都存储他喜欢的1~3个地方。为让这个练 习更有趣些，可让一些朋友指出他们喜欢的几个地方。
遍历这个字典，并将其中每个人的名字及其喜欢的地方打印出来。
'''
favorite_places = {
    'hjk': ['上海', '北京', '杭州'],
    'wy': ['南京', '重庆', '天津'],
    'llq': ['芜湖', '合肥']
}
for name in favorite_places.keys():  # 先遍历键
    print('姓名：', name)  # 打印出键
    for place in favorite_places[name]:  # 遍历每个键对应的列表
        print(place)
