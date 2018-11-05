'''
修改为完成练习6-2而编写的程序，让每个人都可以有多个喜欢的数字，
然后将每个人的名字及其喜欢的数字打印出来。
'''
message = {
    'hjk': [7,3,5,7],
    'wy': [5,3,23,54],
    'llq': [1,4,3,524],
    'ghd': [4,23,65,786],
    'wll': [23,324,5645,565675675]
}
for people in message.keys():#首先遍历键
    print(people)#打印出人名
    for number in message[people]:#遍历键所对应的列表
        print(number)
    print('--------')