'''
在类RandomWalk 中，x_step 和y_step 是根据相同的条件生成的：
从列表[1, -1] 中随机地选择方向，并从列表[0, 1, 2, 3, 4] 中随机地选择距离。
请修改这些列表中的值，看看对随机漫步路径有何影响。尝试使用更长的距离选择列表，
如0~8；或者将-1从 x 或 y 方向列表中删除。
'''

# 使用了更长的距离
import matplotlib.pyplot as plt

from random_walk import RandomWalk

# 创建一个RandomWalk实例，并将其包含的点都绘制出来

while True:
    rw = RandomWalk(50000)
    rw.fill_walk()

    plt.figure(dpi=80, figsize=(10, 6))  # 设置绘图窗口的尺寸
    point_numbers = list(range(rw.num_points))
    plt.scatter(rw.x_values, rw.y_values, c=point_numbers, cmap=plt.cm.Blues,
                edgecolors='none')
    plt.scatter(rw.x_values[0], rw.y_values[0], c='green', s=100)  # 起点
    plt.scatter(rw.x_values[-1], rw.y_values[-1], c='red', s=100)  # 终点
    # 设置坐标轴不可见
    plt.axes().get_xaxis().set_visible(False)
    plt.axes().get_yaxis().set_visible(False)

    plt.show()
    plt.scatter(rw.x_values[0], rw.y_values[0], c='red')
    message = input('是否需要再生成一张图(y/n):')
    if message == 'n':
        break
