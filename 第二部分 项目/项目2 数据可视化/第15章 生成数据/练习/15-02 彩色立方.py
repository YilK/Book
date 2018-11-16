'''
给你前面绘制的立方图指定颜色映射
'''
import matplotlib.pyplot as plt

plt.figure(1)
x_values1 = list(range(1, 6))
y_values1 = [x ** 3 for x in x_values1]
plt.scatter(x_values1, y_values1, linewidth=12, c=y_values1, cmap=plt.cm.Blues)

plt.figure(2)
x_values2 = list(range(1, 50001))
y_values2 = [x ** 3 for x in x_values2]
plt.scatter(x_values2, y_values2, linewidth=12, c=y_values2, cmap=plt.cm.Reds)
plt.show()