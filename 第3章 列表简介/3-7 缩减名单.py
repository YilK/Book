'''
你刚得知新购买的餐桌无法及时送达，因此只能邀请两位嘉宾。
以完成练习3-6时编写的程序为基础，在程序末尾添加一行代码，打印一条你只能邀请两位嘉宾共进晚餐的消息。
    使用pop() 不断地删除名单中的嘉宾，直到只有两位嘉宾为止。每次从名单中弹出一位嘉宾时，都打印一条消息，让该嘉宾知悉你很抱歉，无法邀请他来共进晚餐。
    对于余下的两位嘉宾中的每一位，都打印一条消息，指出他依然在受邀人之列。
    使用del 将最后两位嘉宾从名单中删除，让名单变成空的。打印该名单，核实程序结束时名单确实是空的。
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
# 3-7
print('sorry:' + people.pop(-1))
print('sorry:' + people.pop(-1))
print('sorry:' + people.pop(-1))
print('sorry:' + people.pop(-1))
print('sorry:' + people.pop(-1))
print('sorry:' + people.pop(-1))

print(people[0])
print(people[1])

del people[0]
del people[0]

print(people)
