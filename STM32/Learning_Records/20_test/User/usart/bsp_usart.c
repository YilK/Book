#include "bsp_usart.h"

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
void USART_Config()
{
	
	//定义初始化结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;
	
	//打开时钟
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	
	//初始化GPIO
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);
	
	//配置串口参数
	USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	//完成串口初始化配置
	USART_Init(DEBUG_USARTx,&USART_InitStructure);
	//串口中断优先级配置
	NVIC_Configuration();
//	
//	//使能串口接收中断
	USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
	//使能USART
	USART_Cmd(DEBUG_USARTx,ENABLE);
}
void USART_SendByte(USART_TypeDef* pSARTx,uint8_t ch)   //发送一个字节的数据
{
	USART_SendData(pSARTx,ch);
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TXE)==RESET);//发送数据寄存器为空
}
void USART_SendArray(USART_TypeDef* pSARTx,uint16_t data)	//发送两个字节数据
{
	uint8_t temp_h,temp_l;
	temp_h=(data&0xff00)>>8;
	temp_l=(data&0x00ff);
	USART_SendData(pSARTx,temp_h);
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TXE)==RESET);//发送数据寄存器为空
	
	USART_SendByte(pSARTx,temp_l);
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TXE)==RESET);//发送数据寄存器为空
}

void USART_SendString(USART_TypeDef* pSARTx,uint8_t *str)		//发送字符串0
{
	uint8_t i=0;
	do
	{
		USART_SendByte(pSARTx,*(str+i));
		i++;
	}while(*(str+i)!='\0');
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TC)==RESET);
}
