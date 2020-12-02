#include "bsp_exti.h"
static void EXTI_NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStruct;//定义初始化结构体
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//配置中断优先级分组
	
	//配置NVIC寄存器，初始化NVIC_InitTypeDef
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);
}
void EXTI_Key_Config()  
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	EXTI_InitTypeDef	EXTI_InitStruct;
	
	//配置NVIC中断
	EXTI_NVIC_Config();
	
	//1-初始化要连接到EXTI的GPIO
	
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入说明这个GPIO由外部电平决定
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//输入没有速度之说
	
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//2-初始化EXTI用于产生中断/事件
	//选择输入线
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);   //选择输入线
	
	//打开时钟
	//上面我们操作的是AFIO寄存器（这是和GPIO类似的），我们也需要打开其时钟
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//初始化EXTI结构体
	//这个定义放在了第6行
	//这个结构体的定义放在了第6行
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;//上升沿
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	
	EXTI_Init(&EXTI_InitStruct);
	
	//3-初始化NVIC，用于处理中断 void EXTI_NVIC_Config()；
	/*
		使能中断请求-->配置外设和NVIC  中国上面已经做了
		配置中断优先级分组
		配置NVIC寄存器，初始化NVIC_InitTypeDef;
	*/
}
