## 18_SysTick-系统定时器

1. SysTick简介
2. SysTick功能框图讲解
3. SysTick定时实验讲解

### 1.SysTick简介

SysTick—系统定时器是属于 CM3 内核中的一个外设，内嵌在 NVIC 中。系统定时器是一个 24bit 的向下递减的计数器。

### 2.SysTick功能框图讲解

![](pic/54.png)

#### 这里面最重要的三个寄存器

- CTRL：SysTick控制及状态寄存器
  - ![](pic/55.png)
  - COUNTFLAG：当倒数计数至0，这一位会至位1，如果读取了COUNFLAG，这一位会置为0；//这个是自动的？
  - CLKSOURCE：这里可以和HSE那一节结合起来，给系统时钟提供时钟
  - ENABLE：写1时SysTick定时器使能。
- LOAD：SysTick重装载数值寄存器
  - ![](pic/56.png)
- VAL：SysTick当前数值寄存器
  - ![](pic/57.png)
  - ![](pic/58.png)

#### SysTick定时时间计算

1. t：一个计数循环的时间，跟reload和CLK有关
2. CLK：72M或者9M，由CTRL寄存器配置
3. RELOAD：24位，用户自己配置

example：

- t = reload * ( 1/clk )
- Clk = 72M时，t = (72) *(1/ 72 M )= 1US
- Clk = 72M时，t = (72000) *(1/ 72 M )= 1MS

#### SysTick库函数

```c
//初始化并启动SysTick计数器及其中断。
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
   //判断ticks的值是否>2^24，如果大于则不符合规则
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);           
   //初始化RELOAD寄存器的值                                                            
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      
   //配置中断优先级，配置为15，默认为最低的优先级
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  
    
   //初始化当前数值寄存器
  SysTick->VAL   = 0;      

    //配置systick 时钟为72M，使能中断，使能systick
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}

```

#### SysTick中断优先级

1-STM32里面无论是内核还是外设都是使用**4个二进制位**来表示中断优先级。

2-中断优先级的分组对内核和外设同样适用。当比较的时候，只需要把内核外设的中断优先级的四个位按照外设的中断优先级来分组来解析即可，即人为的分出抢占优先级和子优先级。

### 3.SysTick定时实验讲解

#### 实验设计

1. 编写一个微秒延时函数
2. 编写一个毫秒延时函数

#### 实验流程

1. 将第12章节的利用固件库点亮GPIO的文件拷贝一份，在User文件夹下创建一个systick文件夹，在文件夹中创建`bsp_systick.c`与`bsp_systick.h`文件，打开工程在USER文件夹中将`bsp_systick.c`导入然后包含头文件`bsp_systick.h`，在头文件中要写上条件编译。（注意里面的一些初始化操作，都是很固定操作）

   在`bsp_systick.h`多加一句

   ```c
   #include "core_cm3.h"
   ```

2. `bsp_systick.c`

   ```c
   #include "bsp_systick.h"
   
   void SysTick_Delay_us(uint32_t us)
   {
   	uint32_t i;
   	SysTick_Config(72);//1us
   	for(i=0;i<us;i++)
   	{
   		while(!((SysTick->CTRL)&(1<<16)));//这里是看CTLK中的COUNTFLAG：当倒数计数至0，这一位会至位1，如果读取了COUNFLAG，这一位会置为0
   	}
   	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;  //延时完毕之后不想再开启定时器，这一句是不使能定时器
   }
   
   void SysTick_Delay_ms(uint32_t ms)
   {
   	uint32_t i;
   	SysTick_Config(72000);
   	for(i=0;i<ms;i++)
   	{
   		while(!((SysTick->CTRL)&(1<<16)));
   	}
   	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
   }
   ```

   

