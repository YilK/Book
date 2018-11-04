'''
你并非只能创建10个测试。如果你想尝试做更多的比较，可再编写一些测试，
并将它们加入到conditional_tests.py中。
对于下面列出的各种测 试，至少编写一个结果为True 和False 的测试。
    1.检查两个字符串相等和不等。
    2.使用函数lower() 的测试。
    3.检查两个数字相等、不等、大于、小于、大于等于和小于等于。
    4.使用关键字and 和or 的测试。
    5.测试特定的值是否包含在列表中。
    6.测试特定的值是否未包含在列表中。
'''
# 1,2
A = 'hello'
B = 'HeLlo'
print(A == B)
print(B.lower() == A)

# 3,4
a = 12
b = 23
print('1:', a == b)
print('2:', a >= b)
print('3:', a <= b)
print('4:', a > b)
print('5:', a < b)
print('6:', a >= 10 and b >= 12)  # 两个都为真
print('7:', a >= 10 or b >= 24)  # 其中一个为真

# 5,6
numbers = list(range(1, 39))
print(1 in numbers)
print(123 in numbers)
