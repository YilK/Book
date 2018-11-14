## 第11章 测试代码

### 一、测试函数

​	Python 标准库中的模块 unittest 提供了代码测试工具。

​	首先导入模块 unittest 以及要测试的函数，再创建一个继承 unittest.TestCase的类，并编写一系列的方法对函数进行测试。

​	编写测试方法的时候需要使用 test_ 开头，所有以test_ 开头的方法都将自动运行

​	使用断言方法来核实得到的结果是否与期望的结果一致

### 二、测试类

​	

| **序号** | **断言方法**                 | **描述**                               |
| -------- | ---------------------------- | -------------------------------------- |
| 1        | assertEqual(arg1, arg2, )    | 验证arg1=arg2，不等则fail              |
| 2        | assertNotEqual(arg1, arg2, ) | 验证arg1 != arg2, 相等则fail           |
| 3        | assertTrue(expr, )           | 验证expr是true，如果为false，则fail    |
| 4        | assertFalse(expr,)           | 验证expr是false，如果为true，则fail    |
| 5        | assertIs(arg1, arg2, )       | 验证arg1、arg2是同一个对象，不是则fail |
| 6        | assertIsNot(arg1, arg2, )    | 验证arg1、arg2不是同一个对象，是则fail |
| 7        | assertIsNone(expr, )         | 验证expr是None，不是则fail             |
| 8        | assertIsNotNone(expr, )      | 验证expr不是None，是则fai              |
| 9        | assertIn(arg1, arg2,)        | 验证arg1是arg2的子串，不是则fail       |
| 10       | assertNotIn(arg1, arg2, )    | 验证arg1不是arg2的子串，是则fail       |



在测试类的时候，可以使用**setup()** 来创建对象，提高效率