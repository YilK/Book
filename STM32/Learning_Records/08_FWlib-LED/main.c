
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
int main (void)
{

//	RCC->APB2ENR |=(1<<3);
////	GPIOB->ODR &=~(1<<0);
////	GPIOB->CRL &=~((0x0f)<<(4*0));
////	GPIOB->CRL |=(1<<(4*0));
//	
////		GPIOB->BSRR |=(1<<(17));
////		GPIOB->CRL &=~((0x0f)<<(4*1));
////		GPIOB->CRL |=(1<<(4*1));
//	
//		GPIOB->BRR |=(1<<(5));
//		GPIOB->CRL &=~((0x0f)<<(4*5));
//		GPIOB->CRL |=(1<<(4*5));


#if 0
	
	RCC->APB2ENR |=(1<<3);//�򿪶˿�ʱ��
	GPIOB->CRL &=~((0x0f)<<(4*0));//����IO��Ϊ���
	GPIOB->CRL |=(1<<(4*0));
	
//	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	
#elif 1
	GPIO_InitTypeDef GPIO_InitStructure;//������Ҫע�ⶨ�������������ǰ�档
	RCC->APB2ENR |=(1<<3);//�򿪶˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//��������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;//������������ʡ�
	//д��Ĵ�����
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��һ���������ĸ�GPIO�˿ڣ��ڶ����ǽṹ��ĵ�ַ
	
	
	
#endif 


}

void SystemInit(void)
{
	// ������Ϊ�գ�Ŀ����Ϊ��ƭ��������������
}









