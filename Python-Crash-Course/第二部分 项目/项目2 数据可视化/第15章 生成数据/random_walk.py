from random import choice


class RandomWalk():
    """一个生成随机漫步数据的类"""

    def __init__(self, num_points=5000):  # 默认点数设置为5000
        """初始化随机漫步的属性"""
        self.num_points = num_points

        # 所有的随机漫步都开始于(0,0)
        # 设置存储x,y值的列表

        self.x_values = [0]
        self.y_values = [0]

    def fill_walk(self):
        """计算随机漫步包含所有的点"""
        # 不断漫步,直到走完所有的步数
        while len(self.x_values) < self.num_points:
            x_step = get_step()

            y_step = get_step()

            if x_step == 0 and y_step == 0:
                # 如果原地踏步则继续循环
                continue

            # 计算下一个点的x和y值
            next_x = self.x_values[-1] + x_step
            next_y = self.y_values[-1] + y_step

            self.x_values.append(next_x)
            self.y_values.append(next_y)


def get_step():
    direction = choice([1, -1])
    distance = choice(list(range(9)))
    return direction * distance
