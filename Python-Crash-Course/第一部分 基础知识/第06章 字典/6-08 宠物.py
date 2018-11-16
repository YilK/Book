'''
创建多个字典，对于每个字典，都使用一个宠物的名称来给它命名；在每个字典中，
包含宠物的类型及其主人的名字。将这些字典存储在一个名为pets 的列表中，
再遍历该列表，并将宠物的所有信息都打印出来。
'''
smallhuang = {
    'variety': 'dog',
    'owner': 'hjk'
}
bigyao = {
    'variety': 'pig',
    'owner': 'wy'
}
# 添加入列表
pets = [smallhuang, bigyao]
# 遍历
for pet in pets:
    print(pet)
