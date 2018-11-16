'''
数字的三次方被称为其立方。请绘制一个图形，显示前5个整数的立方值，
再绘制一个图形，显示前5000个整数的立方值。
'''

import matplotlib.pyplot as plt

plt.figure(1)
x_values1 = list(range(1, 6))
y_values1 = [x ** 3 for x in x_values1]
plt.scatter(x_values1, y_values1, linewidth=12)

plt.figure(2)
x_values2 = list(range(1, 50001))
y_values2 = [x ** 3 for x in x_values2]
plt.scatter(x_values2, y_values2, linewidth=12)
plt.show()
