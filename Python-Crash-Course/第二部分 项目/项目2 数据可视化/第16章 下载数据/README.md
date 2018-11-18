## 第16章 下载数据

以下是几个函数

### 1.zip()

​	**zip()** 函数用于将可迭代的对象作为参数，将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的对	象，这样做的好处是节约了不少的内存。  

​	我们可以使用 list() 转换来输出列表。

​	如果各个迭代器的元素个数不一致，则返回列表长度与最短的对象相同，利用 * 号操作符，可以将元组解压为列表。

```python
a = [1, 2, 3]
b = [5, 6, 8]
c = [6, 7, 9, 334, 12]
zipped = zip(a, b)  # 返回一个对象

print(zipped)
print(list(zipped))  # 转换为列表
print(type(zipped))
print(list(zip(a, c)))  # 元素的个数于最短的列表一致

a1,a2=zip(*zip(a,b))#zip(*) 可理解为解压
print(a1)
print(a2)

#输出
<zip object at 0x000001DEC6230C08>
[(1, 5), (2, 6), (3, 8)]
<class 'zip'>
[(1, 6), (2, 7), (3, 9)]
(1, 2, 3)
(5, 6, 8)

```

 

### 2.sorted()

​	**sorted()** 函数对所有可迭代的对象进行排序操作。

​		**sort** 与 **sorted** 的区别：

​		sort 是应用在 list 上的方法，sorted 可以对所有的可迭代的对象进行排序操作。

​		list 的 sort 方法返回的是对已经存在的的列表进行操作，无返回值。而内建函数 sorted 方法返回的是一个新的	 	  list 而不是在原来的基础上进行操作的



### 3.itertools.groupby()

​	`groupby()`把迭代器中相邻的重复元素挑出来放在一起:

```python
>>> for key, group in itertools.groupby('AAABBBCCAAA'):
...     print(key, list(group))
...
A ['A', 'A', 'A']
B ['B', 'B', 'B']
C ['C', 'C']
A ['A', 'A', 'A']
```

​	实际上挑选规则是通过函数完成的，只要作用于函数的两个元素返回的值相等，这两个元素就被认为是在一组的，而函数返回值作为组的key。如果我们要忽略大小写分组，就可以让元素`'A'`和`'a'`都返回相同的key：

```python
>>> for key, group in itertools.groupby('AaaBBbcCAAa', lambda c: c.upper()):
...     print(key, list(group))
...
A ['A', 'a', 'a']
B ['B', 'B', 'b']
C ['c', 'C']
A ['A', 'A', 'a']
```

