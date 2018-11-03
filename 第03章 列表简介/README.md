## 第3章 列表简介



### 在列表中添加元素

1. list.append(obj) ：在列表末尾添加对象，obj -- 添加到列表末尾的对象。

2. list.insert (index,obj) ：在指定位置添加对象。

   ​	index ：对象 obj 需要插入的索引位置。

   ​	obj ：要插入列表中的对象。



### 从列表中删除元素

1. list.pop(index=-1) ：pop() 函数用于移除列表中的一个元素（默认最后一个元素），并且返回该元素的值。
2. list.remove(obj) ：移除列表中某个值的**第一个匹配项**。如果要删除的值在列表中出现多次，可以使用循环来   解决问题



### 列表的排序

1. list.sort() ：对列表进行永久性的排序，默认为升序排序，若要降序设置 reverse=True  

```python
list=[3,4,1,7,5]
list.sort()
print(list)
list.sort(reverse=True)
print(list)

#输出
[1, 3, 4, 5, 7]
[7, 5, 4, 3, 1]

```

2. sorted() ：对列表进行临时排序，也可以向函数传递  reverse=True  

   3.list.reverse() ：将列表倒过来，最后的变为第一个  相当于list[::-1],但是这个函数是对列表永久性排序



