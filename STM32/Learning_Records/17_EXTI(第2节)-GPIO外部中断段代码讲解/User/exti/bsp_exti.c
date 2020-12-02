#include "bsp_exti.h"
static void EXTI_NVIC_Config()
{
	NVIC_InitTypeDef NVIC_InitStruct;//�����ʼ���ṹ��
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//�����ж����ȼ�����
	
	//����NVIC�Ĵ�������ʼ��NVIC_InitTypeDef
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
	
	//����NVIC�ж�
	EXTI_NVIC_Config();
	
	//1-��ʼ��Ҫ���ӵ�EXTI��GPIO
	
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������˵�����GPIO���ⲿ��ƽ����
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//����û���ٶ�֮˵
	
	GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);
	
	//2-��ʼ��EXTI���ڲ����ж�/�¼�
	//ѡ��������
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);   //ѡ��������
	
	//��ʱ��
	//�������ǲ�������AFIO�Ĵ��������Ǻ�GPIO���Ƶģ�������Ҳ��Ҫ����ʱ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//��ʼ��EXTI�ṹ��
	//�����������˵�6��
	//����ṹ��Ķ�������˵�6��
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Rising;//������
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;
	
	EXTI_Init(&EXTI_InitStruct);
	
	//3-��ʼ��NVIC�����ڴ����ж� void EXTI_NVIC_Config()��
	/*
		ʹ���ж�����-->���������NVIC  �й������Ѿ�����
		�����ж����ȼ�����
		����NVIC�Ĵ�������ʼ��NVIC_InitTypeDef;
	*/
}
