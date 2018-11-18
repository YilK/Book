'''
在有关锡特卡和死亡谷的图表中，气温刻度反映了数据范围的不同。
为准确地比较锡特卡和死亡谷的气温范围，需要在y 轴上使 用相同的刻度。为此，
请修改图16-5和图16-6所示图表的y 轴设置，对锡特卡和死亡谷的气温范围进行直接比较
（你也可以对任何两个地方的气温范围进行比较）。
你还可以尝试在一个图表中呈现这两个数据集。
'''

import matplotlib.pyplot as plt

from datetime import datetime

import csv


def get_message(filename, dates, highs, lows):
    """

    :param filename: 文件名
    :param dates: 存储日期的列表
    :param highs: 存储最高温的列表
    :param lows: 存储最低温的列表
    :return:
    """

    with open(filename) as f:
        reader = csv.reader(f)
        head_row = next(reader)  # 读取第一行不做任何操作，方便接下来直接读取第二行

        for row in reader:
            try:
                current_date = datetime.strptime(row[0], "%Y-%m-%d")
                high = int(row[1])
                low = int(row[3])
            except:
                print(current_date, 'missing data')
            else:
                dates.append(current_date)
                highs.append(high)
                lows.append(low)


# Get weather data for Sitka.
dates, highs, lows = [], [], []
get_message('sitka_weather_2014.csv', dates, highs, lows)

# 绘制图像
fig = plt.figure(dpi=128, figsize=(10, 6))
plt.plot(dates, highs,  c='r', alpha=0.5)
plt.plot(dates,  lows, c='b', alpha=0.5)
plt.fill_between(dates, highs, lows, facecolor='g', alpha=0.15)

# Get Death Valley data.
dates, highs, lows = [], [], []
get_message('death_valley_2014.csv', dates, highs, lows)

# 绘制图像
plt.plot(dates, highs, c='r', alpha=0.5)
plt.plot(dates, lows, c='b', alpha=0.5)
plt.fill_between(dates, highs, lows, facecolor='g', alpha=0.1)

plt.title("Daily high and low temperatures",fontsize=20)  # 设置图片的标题
plt.xlabel('Date', fontsize=16)  # 给x轴添加标签
plt.ylabel('Temperature(F)', fontsize=16)  # 给y轴添加标签

plt.tick_params(axis='both', which='major', labelsize=16)  # 对刻度线的操作

plt.ylim(10, 120)  # 修改y坐标轴的范围

plt.show()
