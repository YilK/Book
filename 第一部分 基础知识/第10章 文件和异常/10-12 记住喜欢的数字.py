'''
将练习10-11中的两个程序合而为一。如果存储了用户喜欢的数字，就向用户显示它，
否则提示用户输入他喜欢的数字并将其存储到文件中。 运行这个程序两次，
看看它是否像预期的那样工作。
'''

import json

filename = '10-11.txt'
for i in range(2):  # 设置循环运行2次
    try:
        with open(filename) as f:
            number = json.load(f)  # 读取数字
    except:
        print('没有找到此文件')
        with open(filename, 'w') as f:  # 存储数字
            number = input('请输入你喜欢的数字:')
            number = float(number)  # 转换为数字
            json.dump(number, f)
    else:  # 如果已经保存过数字了
        print('I know your favorite number! It\'s', number)
