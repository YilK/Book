## 17_EXTI(第2节)外部中断控制实验

### 实验的设计

1. PA0连接到EXTI用于产生中断，PA0的电平变化通过按键来控制。
2. 产生一次中断，LED反转一次

### 实验流程

1. 将第12章节的利用固件库点亮GPIO的文件拷贝一份，在User文件夹下创建一个exti文件夹，在文件夹中创建`bsp_exti.c`与`bsp_exti.h`文件，打开工程在USER文件夹中将`bsp_exti.c`导入然后包含头文件`bsp_exti.h`，在头文件中要写上条件编译。（注意里面的一些初始化操作，都是很固定操作）

2. 初始化要连接到EXTI的GPIO

   1. 创建一个新的函数`EXTI_Key_Config()`
   2. 因为是按键,查看原理图可以看到所要用到的引脚是PA0与PC13。
   3. 定义引脚的宏，定义一个初始化结构体，写入变量，打开始终，初始化GPIO
   4. 主要感觉这个定义这个宏麻烦，要取好多名字。

3. 初始化EXTI，用于产生中断/事件

   1. 打开EXTI时钟   这里十分重要--》**一定要先打开时钟！！！！！！！！！！！**

      `RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);`这里时AFIO寄存器。

   2. 选择GPIO的引脚作为EXTI Line

      函数：`void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource)`

      函数的参数在函数的描述中很容易理解

   3. 初始化EXTI结构体

      1. 首先要定义一个初始化结构体（这个是要在函数的头部定于的。）`EXTI_InitTypeDef	EXTI_InitStruct;`
      2. 初始化结构体中的成员，这个查看描述配置即可
      3. 调用函数，将结构体中的函数写到相应的寄存器当中去`EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);`       

4. 初始化NVIC

   1. NVIC对应msic.h和msic.c这两个文件。

   2. 创建一个新的函数`void EXTI_NVIC_Config()`

   3. 定义NVIC初始化结构体

   4. 配置中断优先级分组

      `NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);`

   5. 配置结构体中的每一个成员

      `NVIC_InitStruct.NVIC_IRQChannel`这个取值需要注意。

   6. 调用NVIC的初始化函数

      `NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);`

   7. 将此函数写入`EXTI_Key_Config()`并写在变量定义的后面。

5. 编写中断服务函数

   1. 中断服务函数都写在`stm32f10x_it.c`中

   2. 函数的名称应该怎么写，在启动文件`startup_stm32f10x_hd.s`找到对应的函数名。

      ```c
      
      ```

6. main函数

   ```C
   
   ```
