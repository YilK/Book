import csv

import matplotlib.pyplot as plt

from datetime import datetime

filename = 'death_valley_2014.csv'
with open(filename) as f:
    reader = csv.reader(f)
    head_row = next(reader)

    dates, highs, lows = [], [], []
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

fig = plt.figure()
plt.plot(dates, highs, c='r', alpha=0.5)  # 绘制
plt.plot(dates, lows, c='b', alpha=0.5)

plt.fill_between(dates, highs, lows, facecolor='y', alpha=0.1)  # 填充

# 设置图片的标题

title = "Daily high and low temperatures - 2014\nDeath Valley, CA"
plt.title(title, fontsize=20)

plt.xlabel('Date', fontsize=16)  # 给x轴添加标签
plt.ylabel('Temperature(F)', fontsize=16)  # 给y轴添加标签
fig.autofmt_xdate()  # 将日期标签倾斜，防止重复
plt.tick_params(axis='both', which='major', labelsize=16)  # 对刻度线的操作

plt.show()  # 将绘图显示出来
