'''
编写一个名为city_country() 的函数，它接受城市的名称及其所属的国家。
这个函数应返回一个格式类似于下面这样的字符串：  "Santiago, Chile"
至少使用三个城市-国家对调用这个函数，并打印它返回的值。
'''


def city_country(city, country):
    return (city + ',' + country)


print(city_country('Beijing', 'China'))
print(city_country('hebei', 'China'))
print(city_country('hangzhou', 'China'))
