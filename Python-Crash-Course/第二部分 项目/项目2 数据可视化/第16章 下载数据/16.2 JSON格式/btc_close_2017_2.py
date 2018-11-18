import json
import pygal
import math

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

line_chart = pygal.Line(x_label_rotiaon=20, show_minor_x_labels=False)
'''
x_label_rotiaon=20 : 让x轴上的坐标顺时针旋转20
show_minor_x_labels=False : 告诉图形不用显示所有的x轴标签

'''
line_chart.title = '收盘价对数变换'
line_chart.x_labels = dates

N = 20  # x轴坐标每隔20天显示一次
line_chart.x_labels_major = dates[::50]
close_log = [math.log10(item) for item in close]
line_chart.add('log收盘价(￥)', close_log)
line_chart.render_to_file('log收盘价折线图￥.svg')
