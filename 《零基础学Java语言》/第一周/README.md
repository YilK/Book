# 第一周 计算

## 1.1	第一个java程序

​		创建工程：File->New->Java project->输入project name

​		 			find src->class 创建

​		输出：System.out.println("Hello World"); 💡快捷键 Alt + /



## 1.2	变量与计算

#### 	输入

```

```



```java
		Scanner in =new Scanner(System.in);
		System.out.println("echo:"+in.nextLine());//in.nextline()是指把下一行的东西读进来
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
//		final int amount=100;//表示一个常量
		int amount;
		System.out.print("请输入票面:");//注意这里是print而不是println
		amount=in.nextInt();
		System.out.print("请输入金额:");
		price=in.nextInt();//in.nextInt()读入用户输入的数字
		System.out.println(amount+"-"+price+"="+(amount-price));
```



## 1.3	浮点数计算

