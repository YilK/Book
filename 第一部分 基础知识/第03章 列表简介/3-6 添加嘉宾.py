'''
你刚找到了一个更大的餐桌，可容纳更多的嘉宾。请想想你还想邀请哪三位嘉宾。
以完成练习3-4或练习3-5时编写的程序为基础，在程序末尾添加一条print 语句，指出你找到了一个更大的餐桌。
    使用insert() 将一位新嘉宾添加到名单开头。
    使用insert() 将另一位新嘉宾添加到名单中间。
    使用append() 将最后一位新嘉宾添加到名单末尾。
    打印一系列消息，向名单中的每位嘉宾发出邀请。
'''
people = ['hjk', 'wy', 'llq', 'ghd', 'wll']
print('邀请名单：' + str(people))
print('缺席人员：' + str(people[-1]))
# 修改名单
people[-1] = 'lsh'
print('修改后的名单：' + str(people))
# 3-6
print('找到了一个更大的餐桌！！！！')
people.insert(0, 'hhh')
people.insert(2, 'jjj')
people.append('kkk')
print(people)
