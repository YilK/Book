## 20_USART-串口通信(第2节)-实验部分

1. 中断接收和发送
   - 单片机给电脑发送数据，电脑上位机把数据打印出来；
   - 电脑上位机给单片机发数据，单片机接收到数据之后立马发回给电脑，并打印出来。
2. 串口控制RGB灯亮灭
   - 电脑给单片机发命令，用于控制开发板上的RGB灯。

### 1.中断接收和发送

- 单片机给电脑发送数据，电脑上位机把数据打印出来；

  1. 使能 RX 和 TX 引脚 GPIO 时钟和 USART 时钟；
  2. 初始化 GPIO，并将 GPIO 复用到 USART 上
  3. 配置 USART 参数
  4. 使能 USART
  5. 串口发送数据
  6. 串口传输状态获取

  NOTE：在这一个例子中，单片机只需要给电脑发送数据，所以可以不写中断函数。

1. 使能 RX 和 TX 引脚 GPIO 时钟和 USART 时钟；

   ```c
   // 打开串口GPIO的时钟
   DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);
   	
   // 打开串口外设的时钟
   DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);
   ```

2. 初始化 GPIO，并将 GPIO 复用到 USART 上

   ```c
   // 将USART Tx的GPIO配置为推挽复用模式     发送引脚
   GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);
   
   // 将USART Rx的GPIO配置为浮空输入模式    接收引脚
   GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
   GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
   ```

3. 配置 USART 参数

   ```c
   // 配置串口的工作参数
   // 配置波特率
   USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;
   // 配置 针数据字长
   USART_InitStructure.USART_WordLength = USART_WordLength_8b;
   // 配置停止位
   USART_InitStructure.USART_StopBits = USART_StopBits_1;
   // 配置校验位
   USART_InitStructure.USART_Parity = USART_Parity_No ;
   // 配置硬件流控制
   USART_InitStructure.USART_HardwareFlowControl = 
   USART_HardwareFlowControl_None;
   // 配置工作模式，收发一起
   USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
   // 完成串口的初始化配置
   USART_Init(DEBUG_USARTx, &USART_InitStructure);
   ```

4. 配置中断控制器并使能 USART 接收中断

   ```
   NVIC_Configuration();
   ```

5. 使能 USART

   ```
   USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
   
   
   static void NVIC_Configuration(void)
   {
     NVIC_InitTypeDef NVIC_InitStructure;
     
     /* 嵌套向量中断控制器组选择 */
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
     
     /* 配置USART为中断源 */
     NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
     /* 抢断优先级*/
     NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
     /* 子优先级 */
     NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
     /* 使能中断 */
     NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
     /* 初始化配置NVIC */
     NVIC_Init(&NVIC_InitStructure);
   }
   ```

6. 在 USART 接收中断服务函数实现数据接收和发送。

   ```
   USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
   ```

   











移植的的时候需要改串口，GPIO

