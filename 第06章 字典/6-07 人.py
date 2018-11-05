'''
在为完成练习6-1而编写的程序中，再创建两个表示人的字典，
然后将这三个字典都存储在一个名为people 的列表中。
遍历这个列表，将其中每个人的所有 信息都打印出来。
'''
message1 = {
    'first_name': 'huang',
    'last_name': 'junkai',
    'age': 21,
    'city': 'zhejiang'
}

message2={
    'first_name': 'wang',
    'last_name': 'yao',
    'age': 22,
    'city': 'shanxi'
}

message3={
    'first_name': 'luo',
    'last_name': 'liqiang',
    'age': 23,
    'city': 'zhejiang'
}
#存入列表
message_list=[message1,message2,message3]
for message in message_list:
    print(message)