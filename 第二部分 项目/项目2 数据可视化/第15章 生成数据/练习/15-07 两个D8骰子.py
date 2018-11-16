'''
请模拟同时掷两个8面骰子1000次的结果。逐渐增加掷骰子的次数，直到系统不堪重负为止
'''
from die import Die

import pygal

# 创建两个D6的骰子
die1 = Die(8)
die2 = Die(8)
# 掷几次骰子，并将结果存储在一个列表中
results = [die1.roll() + die2.roll() for i in range(1000)]
# 分析结果，看每个数字出现了多少次

frequencies = [results.count(value) for value in range(2, die1.num_sides +
                                                       die2.num_sides + 1)]
print(frequencies)

# 对结果进行可视化
hist = pygal.Bar()  # 创建条形图
hist.title = "掷两个骰子2000次的结果"  # 用于标示直方图的字符串
hist.x_labels = list(range(2, die1.num_sides + die2.num_sides + 1))  # x轴的标签
hist.x_title = "Result"  # x轴的标题
hist.y_title = "Frequency of Result"  # y轴的标题

hist.add('D8+D8', frequencies)
'''
们使用add() 将一系列值添加到图表中（向它传递要给添加的值指定的标签，还有一个列表，
                                    其中包含 将出现在图表中的值）'''

hist.render_to_file('15-07.svg')  # 将图表渲染为一个SVG文件
