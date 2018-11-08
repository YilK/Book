## 第8章 函数

### 一、传递实参

​	向函数传递实参的方式有很多种，可以使用**位置实参**，这要求实参的顺序和形参的顺序相同；也可以使用**关键字实参**，其中的每个实参都是由变量名和实参组成，还可以使用**字典和列表**

#### 	1. 位置实参

​		基于实参的顺序进行关联

```python
def describe_pet(animal_type, pet_name):
	"""显示宠物的信息"""      
	print("\nI have a " + animal_type + ".")      
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
    
describe_pet('hamster', 'harry')
# 按顺序对应起来，我觉得是最普遍的用法了
#输出
I have a hamster. 
My hamster's name is Harry
```

​	

#### 	2.关键字实参

​		关键字实参是传递给函数的名称—值对。

```python
def describe_pet(animal_type, pet_name):
	"""显示宠物的信息"""      
	print("\nI have a " + animal_type + ".")      
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
    
describe_pet(animal_type='hamster',pet_name='harry')
describe_pet(pet_name="jkljkl",animal_type='dog')

#输出
I have a hamster. 
My hamster's name is Harry.

I have a dog.
My dog's name is Jkljkl.
```

​		在传递实参的时候，把它要传递给的形参直接写出来

#### 		3.默认值

​		编写函数时，可给每个形参指定默认值。在调用函数中给形参提供了实参，Python将使用指定的实参；否则，将使用形参的默认值。

​	**使用默认值的时候，在形参列表中必须先列出没有默认值的列表，再列出有默认值的形参。**

```python

```



### 二、传递列表

​	将列表传递给函数之后，函数就可以对列表进行修改，再函数中对列表所作的修改是永久性的

```python
example = list(range(1, 10))  # 生成一个列表
print('before:', example)


def deal(example_list):
    while example_list:  # 删除列表中的所有元素
        example_list.pop()


deal(example)
print('after:', example)  # 输出列表

#输出
before: [1, 2, 3, 4, 5, 6, 7, 8, 9]
after: []
```

​	可见列表在函数中做了修改

​	那么怎么样才能不修改原来的列表----->创建副本 **list[:]**，缺点：需要花费时间和内存去创建内存

```python
example = list(range(1, 10))  # 生成一个列表
print('before:', example)


def deal(example_list):
    while example_list:  # 删除列表中的所有元素
        example_list.pop()


deal(example[:])#创建了副本
print('after:', example)  # 输出列表

#输出
before: [1, 2, 3, 4, 5, 6, 7, 8, 9]
after: [1, 2, 3, 4, 5, 6, 7, 8, 9]
```



### 三、传递任意数量的实参

​	有时候，你预先不知道函数需要接受多少个实参，好在Python允许从调用语句中手机任意数量的实参

​	看个例子

```python
def make_pizza(*toppings):    
    """打印顾客点的所有配料"""    
    print(toppings) 
    
make_pizza('pepperoni') 
make_pizza('mushrooms', 'green peppers', 'extra cheese')

#输出
('pepperoni',) 
('mushrooms', 'green peppers', 'extra cheese')
```

​	形参名 *toppings 中的星号让Python创建一个名为 toppings 的**空元组**，并将收到的所有值都封装这个元组里

	#### 	1.结合使用位置实参和任意数量实参

​		如果要让函数接受不同类型的实参，必须在函数定义中**将接纳任意数量实参的形参放在最后**

```python
def make_pizza(size, *toppings):    
    """概述要制作的比萨"""    
    print("\nMaking a " + str(size) + "-inch pizza with the following toppings:")    
    for topping in toppings:        
        print("- " + topping) 
        
 make_pizza(16, 'pepperoni') 
 make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

#输出
Making a pizza with the following toppings: 
- pepperoni 

Making a pizza with the following toppings: 
- mushrooms 
- green peppers 
- extra cheese
```

#### 	2.使用任意数量的关键字实参

​		有时候，需要接受任意数量的实参，但是预先不知道传递给函数的会是什么样的信息，在这种情况下，可将函数编写成**能够接受任意数量的键值对**

```python
def build_profile(first, last, **user_info):      
        """创建一个字典，其中包含我们知道的有关用户的一切"""      
	profile = {}
	profile['first_name'] = first      
	profile['last_name'] = last 
	for key, value in user_info.items():          
        profile[key] = value      
    return profile 

user_profile = build_profile('albert', 'einstein',location='princeton',ield='physics')  
print(user_profile)
```

​		形参**user_info 中的两个星号让Python创建一个名为user_info 的 空字典，并将收到的所有名称—值对都封装到这个字典中。



### 四、将函数存储在模块中

​	1.导入整个模块

```python
import pizza #最普遍的方法
```

​	2.导入特定的函数

```python
from pizza import make_pizza #无需使用句点
```

​	3.使用 as 给函数指定别名

```python
from pizza import make_pizza as mp #解决有重名的问题，或者函数名太长
```

​	4.使用 as 给模块指定别名

```python
import pizza as p #指定简短的别名，更好的调用模块中的函数
```

​	5.导入模块中的所有函数

```python
from pizza import * #可通过名称来调用函数，而无需使用句点表示法
```



