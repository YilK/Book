## 第4章 操作列表



#### 使用 range() 函数

​	创建一个数字列表

```python
numbers=list(range(1,6))
print(numbers)

#输出
[1, 2, 3, 4, 5]
```



#### 对数字列表进行简单的统计计算

```python
digits = list(range(1, 10))
print(digits)
#最小值
print(min(digits))
#最大值
print(max(digits))
#总和
print(sum(digits))

#输出
[1, 2, 3, 4, 5, 6, 7, 8, 9]
1
9
45
```



### 定义元组

元组看起来犹如列表，但使用==圆括号()==来标识



### 设置代码格式

PEP8 (Python Enhancement Proposal), Python 改进提案



1. 缩进使用 4 个空格
2. 每行不超过 80 个字符
3. 等等