'''
编写一个程序，提示用户输入他喜欢的数字，并使用json.dump() 将这个数字存储到文件中。
再编写一个程序，从文件中读取这个值，并打印 消息“I know your favorite number! It's _____.”。
'''

import json

filename = '10-11.txt'
# 保存数据
with open(filename, 'w') as f:
    # 打开仅供写入的文件。如果文件存在，则覆盖该文件。如果文件不存在，则创建一个新文件进行写入。
    try:
        number = input('请输入你喜欢的数字:')
        number = float(number)  # 转换为数字
    except:
        print('你输入的不是数字')
    else:
        json.dump(number, f)
        print('保存成功')

# 读取数据
with open(filename) as f:
    n = json.load(f)
    print('I know your favorite number! It\'s', n)
