#include "bsp_exti.h"
static void EXTI_NVIC_Config()  //NVIC 嵌套向量中断控制器
{
	NVIC_InitTypeDef	NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	
}
void EXTI_Key_Config()
{
	GPIO_InitTypeDef	GPIO_InitStruct; //定义一个初始化结构体
	EXTI_InitTypeDef	EXTI_InitStruct;
	//配置NVIC中断
	EXTI_NVIC_Config();
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);	//打开GPIOA的时钟
	
	//给GPIO结构体中的成员赋值
	GPIO_InitStruct.GPIO_Pin=KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	//注意输入的时候不要设置速率，只有输出的时候要设置速率
	
	GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_InitStruct);
	
	//初始化EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);//端口,引脚
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTI_InitStruct);
}                                                