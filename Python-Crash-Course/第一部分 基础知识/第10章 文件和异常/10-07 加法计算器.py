'''
将你为完成练习10-6而编写的代码放在一个while 循环中，
让用户犯错（输入的是文本而不是数字）后能够继续输入数字。
'''

while True:
    a, b = input('请输入两个数字(以空格分隔):').split()
    try:
        print('数字相加的结果:', (float(a) + float(b)))  # 将字符转换为数字
    except ValueError:
        print('您输入的是文本不符合要求，请重新输入')


