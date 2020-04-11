# 第一周 计算

## 1.1	第一个java程序

​		创建工程：File->New->Java project->输入project name

​		 			find src->class 创建

​		输出：System.out.println("Hello World"); 💡快捷键 Alt + /



## 1.2	变量与计算

#### 	输入-

```java
Scanner in =new Scanner(System.in);	System.out.println("echo:"+in.nextLine());//in.nextline()是指把下一行的东西读进来
System.out.println(2+3+"=2+3="+(2+3));
```

#### 	变量

- 变量定义的一般形式就是：
  - <类型名称> <变量名称>
- int price;
  - 定义了一个变量。变量的名字是price，类型是int，初始值是0；
- int amout;
- int price,amount;

```java
Scanner in =new Scanner(System.in);
int price;
price=in.nextInt();//in.nextInt()读入用户输入的数字
System.out.println("100-"+price+"="+(100-price));
```

#### 	赋值	

```java
System.out.println("你好");
Scanner in =new Scanner(System.in);
int price=0;//变量，初始值为0
//	final int amount=100;//表示一个常量
int amount;
System.out.print("请输入票面:");//注意这里是print而不是println
amount=in.nextInt();
System.out.print("请输入金额:");
price=in.nextInt();//in.nextInt()读入用户输入的数字
System.out.println(amount+"-"+price+"="+(amount-price));
```



## 1.3	浮点数计算

#### 	浮点数

​	✔double

- 两个整数的运算的结果只能是整数

- 10和10.0在Java中是完全不同的数

- 10.0是浮点数

- 当浮点数和整数放到一起运算时，Java会将整数转换成浮点数，然后进行浮点数的运算

  浮点数的计算是有误差的

  ```java
  System.out.println(1.2-1.1);
  //输出：0.09999999999999987
  ```



#### 	优先级

| 优先级 | 运算符 |   运算   | 结合关系 |      举例      |
| :----: | :----: | :------: | :------: | :------------: |
|   1    |   +    | 单目取正 | 自右向左 | a*+b(表示正数) |
|   1    |   -    | 单目取负 | 自右向左 | a*-b(表示负数) |
|   2    |   *    |   乘法   | 自左向右 |      a*b       |
|   2    |   /    |   除法   | 自左向右 |      a/b       |
|   2    |   %    |   取余   | 自左向右 |      a%b       |
|   3    |   +    |   加法   | 自左向右 |      a+b       |
|   3    |   -    |   减法   | 自左向右 |      a-b       |
|   4    |   =    |   赋值   | 自右向左 |      a=b       |

#### 	类型转换

​	int->double 自动转换 

​	❕强制转换->(int)(表达式)

```java
double b=10.3;
int a=(int)b;
```

- 只是从那个变量计算出了一个新的类型的值，它并不改变那个变量，无论是值还是类型都不改变

