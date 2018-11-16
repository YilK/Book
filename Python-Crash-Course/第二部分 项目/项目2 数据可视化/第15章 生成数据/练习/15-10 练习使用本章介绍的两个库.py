'''
尝试使用matplotlib通过可视化来模拟掷骰子的情况，并尝试使用Pygal通过可视化来模拟随机漫步的情况
'''

# 使用matplotlib通过可视化来模拟掷骰子的情况
from die import Die
from random_walk import RandomWalk
import matplotlib.pyplot as plt
import pygal

# 创建两个D6的骰子
die1 = Die()
die2 = Die()
# 掷几次骰子，并将结果存储在一个列表中
results = [die1.roll() + die2.roll() for i in range(2000)]
# 分析结果，看每个数字出现了多少次

x_label = list(set(results))
x_label.sort()

frequencies = [results.count(value) for value in range(2, die1.num_sides +
                                                       die2.num_sides + 1)]
print(frequencies)

plt.plot(x_label, frequencies, linewidth=12)
plt.show()

# 使用Pygal通过可视化来模拟随机漫步的情况
# 创建一个RandomWalk实例，并将其包含的点都绘制出来

while True:
    rw = RandomWalk(500)
    rw.fill_walk()
    # 将每一个点添加入列表
    i = 0
    list = []
    print(rw.x_values)
    print(len(rw.x_values))
    print(rw.y_values)
    print(len(rw.y_values))
    while i < len(rw.y_values):
        list.append((rw.x_values[i], rw.y_values[i]))
        i = i + 1
    print(list)

    chart = pygal.XY(stroke=False)  # 创建散点图
    chart.title = '随机漫步'
    chart.add('walk', list)
    chart.render_to_file('15-10.svg')

    message = input('是否需要再生成一张图(y/n):')
    if message == 'n':
        break
