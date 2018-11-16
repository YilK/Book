'''
同时掷两个骰子时，通常将它们的点数相加。请通过可视化展示将两个骰子的点数相乘的结果。
'''

from die import Die

import pygal

# 创建两个骰子

die1 = Die()
die2 = Die()

# 将点数相乘
results = [die1.roll() * die2.roll() for i in range(2000)]

number = list(set([i * j for i in range(1, 7) for j in range(1, 7)]))  # 可能的值去重
number.sort()  # 对值进行排序
print(number)

# 分析结果
frequencies = [results.count(value) for value in number]

# 数据可视化

hist = pygal.Bar()  # 创建条形图
hist.title = "掷两个骰子2000次的结果"  # 图的标题
hist.x_labels = number  # x轴的标签
hist.x_title = "Result"  # x轴的标题
hist.y_title = "Frequency of Result"  # y轴的标题

hist.add('D6*D6', frequencies)
hist.render_to_file('15-09.svg')  # 将图表渲染为一个SVG文件
