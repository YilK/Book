'''
修改rw_visual.py，将其中的plt.scatter() 替换为plt.plot() 。
为模拟花粉在水滴表面的运动路径，向plt.plot() 传递rw.x_values 和rw.y_values ，
并指定实参值linewidth 。使用5000个点而不是50 000个点。
'''

import matplotlib.pyplot as plt

from random_walk import RandomWalk

# 创建一个RandomWalk实例，并将其包含的点都绘制出来

while True:
    rw = RandomWalk(50000)
    rw.fill_walk()

    plt.figure(dpi=80, figsize=(10, 6))  # 设置绘图窗口的尺寸
    point_numbers = list(range(rw.num_points))
    plt.plot(rw.x_values, rw.y_values)
    plt.plot(rw.x_values[0], rw.y_values[0], c='green')  # 起点
    plt.plot(rw.x_values[-1], rw.y_values[-1], c='red')  # 终点
    # 设置坐标轴不可见
    plt.axes().get_xaxis().set_visible(False)
    plt.axes().get_yaxis().set_visible(False)

    plt.show()

    message = input('是否需要再生成一张图(y/n):')
    if message == 'n':
        break
