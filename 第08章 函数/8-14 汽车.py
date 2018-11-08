'''
编写一个函数，将一辆汽车的信息存储在一个字典中。这个函数总是接受制造商和型号，
还接受任意数量的关键字实参。这样调用这个函数：提供必不可 少的信息，以及两个名称—值对，
如颜色和选装配件。这个函数必须能够像下面这样进行调用：
'''


def car(maker, tpye, **case):
    message = {}  # 创建一个字典
    message['制造商'] =maker
    message['型号']=type
    for key,value in case.items():#遍历字典
        message[key]=value
    return message

print(car('123','jjj',颜色='黄色',排量='2.5T'))
print(car('111','kkk',颜色='红色',排量='3.0T',配件='尾翼'))

