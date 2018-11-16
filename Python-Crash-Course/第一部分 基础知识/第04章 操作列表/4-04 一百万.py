'''
创建一个列表，其中包含数字1~1 000 000，再使用一个for 循环将这些数字打印出来
（如果输出的时间太长，按Ctrl + C停止输出，或关闭输出窗口）。
'''
numbers = list(range(1, 1000001))
for number in numbers:
    print(number)
