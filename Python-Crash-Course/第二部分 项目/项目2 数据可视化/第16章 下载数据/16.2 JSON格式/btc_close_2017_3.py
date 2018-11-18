import json
import pygal
from itertools import groupby

# 将数据添加到一个列表中
filename = 'btc_close_2017.json'
with open(filename) as f:
    btc_data = json.load(f)

dates = []
month = []
week = []
weekday = []
close = []

for btc_dict in btc_data:  # 将所有数据存入列表
    dates.append(btc_dict['date'])
    month.append(int(btc_dict['month']))
    week.append(int(btc_dict['week']))
    weekday.append(btc_dict['weekday'])
    close.append(float(btc_dict['close']))


def draw_line(x_data, y_data, title, y_legend):
    xy_map = []
    for x, y in groupby(sorted(zip(x_data, y_data)), key=lambda _: _[0]):
        '''
        最主要理解 zip(),sorted(),groupy() 理解之后下面的函数也就懂了 important
        '''
        y_list = [v for _, v in y]
        xy_map.append([x, sum(y_list) / len(y_list)])

    X_unique, Y_mean = zip(*xy_map)

    # 绘图
    line_chart = pygal.Line()
    line_chart.title = title  # 设置图片标题
    line_chart.x_labels = X_unique  # 设置x轴
    line_chart.add(y_legend, Y_mean)
    line_chart.render_to_file(title + '.svg')


idx_month = dates.index('2017-12-01')
draw_line(month[:idx_month], close[:idx_month], '收盘价月日均值', '月日均值')

idx_week = dates.index('2017-12-01')
draw_line(week[:idx_week], close[:idx_week], '收盘价周日均值', '周日均值')
