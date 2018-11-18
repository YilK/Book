import csv

import matplotlib.pyplot as plt

from datetime import datetime

# 从文件中提取最高温,最低温和日期
filename = 'sitka_weather_2014.csv'
with open(filename) as f:  # 打开文件对象
    reader = csv.reader(f)  # 创建阅读器对象
    header_row = next(reader)  # 得到文件的第一行，
    # for index, column_header in enumerate(header_row):  # 获取每个元素的索引，及其值
    #     print(index, column_header)

    '''已经读取了文件的第一行，后面从第二行开始读取'''

    dates = []
    highs = []
    lows = []
    for row in reader:
        dates.append(datetime.strptime(row[0], '%Y-%m-%d'))
        highs.append(int(row[1]))
        lows.append(int(row[3]))

    print(dates)
# 根据数据绘制图片

fig = plt.figure(figsize=(20, 6))

plt.plot(dates, highs, c='red', alpha=0.5)  # 将线条设置为红色
plt.plot(dates, lows, c='b', alpha=0.5)  # alpha 表明颜色的透明度

plt.fill_between(dates, highs, lows, facecolor='g', alpha=0.1)  # 填充上颜色

plt.title('Daily high temperatures - 2014', fontsize=24)  # 设置图片的标题
plt.xlabel('Date', fontsize=16)  # 给x轴添加标签

fig.autofmt_xdate()  # 将日期标签倾斜，防止重复

plt.ylabel('Temperature(F)', fontsize=16)  # 给y轴添加标签
plt.tick_params(axis='both', which='major', labelsize=16)  # 对刻度线的操作
plt.show()
