'''
序数表示位置，如1st和2nd。大多数序数都以th结尾，只有1、2和3例外。
    1.在一个列表中存储数字1~9。
    2.遍历这个列表。
    3.在循环中使用一个if-elif-else 结构，以打印每个数字对应的序数。
        输出内容应为1st 、2nd 、3rd 、4th 、5th 、6th 、7th 、8th 和9th ，但每个序 数都独占一行。
'''
numbers=list(range(1,10))
for number in numbers:
    if number == 1:
        print(str(number)+'st')
    elif number==2:
        print(str(number)+'nt')
    elif number==3:
        print(str(number)+'rt')
    else:
        print(str(number)+'th')
