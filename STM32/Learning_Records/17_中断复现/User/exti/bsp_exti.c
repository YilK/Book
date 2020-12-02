#include "bsp_exti.h"
static void EXTI_NVIC_Config()  //NVIC Ƕ�������жϿ�����
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
	GPIO_InitTypeDef	GPIO_InitStruct; //����һ����ʼ���ṹ��
	EXTI_InitTypeDef	EXTI_InitStruct;
	//����NVIC�ж�
	EXTI_NVIC_Config();
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);	//��GPIOA��ʱ��
	
	//��GPIO�ṹ���еĳ�Ա��ֵ
	GPIO_InitStruct.GPIO_Pin=KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	//ע�������ʱ��Ҫ�������ʣ�ֻ�������ʱ��Ҫ��������
	
	GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_InitStruct);
	
	//��ʼ��EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);//�˿�,����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger= EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTI_InitStruct);
}                                                