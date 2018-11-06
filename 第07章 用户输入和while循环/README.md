## 第7章 用户输入和循环

### 输入 ：input()

​	输入一个数字之后，会是一个字符串类型的变量，需要使用 int() ,float() 将其转换，获取数值

### 使用 while 来处理列表和字典

​	for 循环是一种遍历列表的有效方式，但在for 循环中不应修改列表，否则将导致Python难以跟踪其中的元素。**要在遍历列表的同时对其进行修改，可使用while 循环。**通过 将while 循环同列表和字典结合起来使用，可收集、存储并组织大量输入，供以后查看和显示。 

​	简单的来说：如果你要遍历一个列表，并将其中的内容修改，那么就使用 while 循环

#### 删除包含特定值的所有列表元素

```python
pets = ['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabbit', 'cat'] 
print(pets) 
while 'cat' in pets:    
	pets.remove('cat') 
print(pets)
```



### 控制循环的退出

1. 使用 **break**

2. 使用标记

   ```python
   active = True
   while active:
   	message = input()
       
       if message == 'quit':
           active = False
       else:
           print(message)
   ```

3. 使用条件测试退出循环(最普遍的)

   ```python
   x = 1
   while x < 5:
   	print(x)
   	x=x+1
   ```


