## 第9章 类

###  1.方法`__init__()`

​	这是一个特殊的方法，当你创建实例的时候，Python会自动运行它。在这个方法的名称中，开头和末尾各有两个下划线，这是一种约定，旨在避免Python默认方法与普通方法发生名称冲突
​	在这个方法中 **self** 是必不可少的，还必须位于其他形参的前面。每个与类相关联的方法调用都会自动传递实参 self ，它是一个指向实例本身的引用，让实例能够访问类中的方法和属性。

### 2.修改属性的值

1. 直接修改属性的值：通过实例直接访问该属性，进行修改(使用句点表示法)
2. 通过方法修改属性的值：在类中创建更改属性的方法，创建实例调用方法，将值传入
3. 通过方法对属性的值进行递增(递减)：在类中创建方法，创建实例后调用该方法，然后将需要的值传入

### 3.继承

​	一个类继承另一个类时，它将自动获得另一个类的所有属性和方法；原有的类称为父类，而新的类称为子类。

字类继承了其父类的所有属性和方法，同时还可以定义自己的属性和方法

​	1.首先要初始化父类的属性

```python
class Car():
    """一次模拟汽车的简单尝试"""

    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        
class ElectricCar(Car):
    """电动汽车的独特之处"""

    def __init__(self, make, model, year):
        """ 初始化父类的属性，再初始化电动汽车特有的属性"""
        super().__init__(make, model, year)#调用super将父类和字类联系起来
```

​	2.给子类定义属性和方法

​	3.重写父类的方法：

​		对于父类的方法，只要它不符合子类的要求，都可以对其进行重写。定义方法的时候要与重写的方法名相同，这样，python就不会考虑父类的方法，而只关注你在子类中定义的相应的方法。

​	4.将实例用作属性

​		使用代码模拟实物时，你可能会发现自己给类添加的细节越来越多：属性和方法清单以及文件都越来越长。在这种情况下，可能需要将类的一部分作为一个独立的类提取出来。 你可以将大型类拆分成多个协同工作的小类

```python
class Car():
    --snip--
    
class Battery():
    """一次模拟电动汽车电瓶的简单尝试"""

    def __init__(self, battery_size=70):
        """初始化电瓶的属性"""
        self.battery_size = battery_size

    def describe_battery(self):
        """打印一条描述电瓶容量的消息"""
        print("This car has a " + str(self.battery_size) + "-kWh battery.")

class ElectricCar(Car):
    """电动汽车的独特之处"""

    def __init__(self, make, model, year):
        """ 初始化父类的属性，再初始化电动汽车特有的属性"""
        super().__init__(make, model, year)
        self.battery = Battery()#!!!!!将Battery实例作为ElectricCar类的属性
        #在每个ElectricCar 实例都包含一个自动创建的Battery 实例
car=ElectricCar('tesla', 'model s', 2016)
car.battery.describe_battery()

#输出
This car has a 70-kWh battery.
```



### 4.OrderedDict类

​	OrderedDict 是模块 collections 中的一个类 。

​	OrderedDict 实例行为几乎与字典相同，**区别在于键值对的添加顺序**

```python
from collections import OrderedDict # 导入 OrderedDict 类

favorite_languages = OrderedDict() # 创建实例

favorite_languages['jen'] = 'python'  
favorite_languages['sarah'] = 'c'  
favorite_languages['edward'] = 'ruby'  
favorite_languages['phil'] = 'python' 
for name, language in favorite_languages.items():      
    print(name.title() + "'s favorite language is " + language.title() + ".")
   
#输出
Jen's favorite language is Python. 
Sarah's favorite language is C. 
Edward's favorite language is Ruby. 
Phil's favorite language is Python.
```



### 5.类编码风格

1. 将类名中的每个单词的首字母都大写，而不使用下划线
2. 实例名和模块名都采用小写的格式，并在单词之间添加下划线
3. 对于每个类，都应紧跟在类定义后面包含一个**文档字符串**。这种文档字符串简要地描述类的功能，并遵循编写函数的文档字符串时采用的格式约定。**每个模块也都应包含一个文档字符串**，对其中的类可用于做什么进行描述。
4. 在类中以**一个空行**来分割方法；在模块中，使用**两个空格**来分割类
5. 需要同时导入标准库中的模块和你编写的模块时，先编写导入标准库模块的import 语句，再**添加一个空行**，然后编写导入你自己编写的模块的import 语句。在包含多 条import 语句的程序中，这种做法让人更容易明白程序使用的各个模块都来自何方。 