#include "stm32f10x.h"

int main()
{
	
	//��GPIOB�Ķ˿�ʱ��
	RCC_APB2ENR |=(1<<3);
	while(1)   //��ˮ����ҵ
	{	
		//�̵�
		int j=0;
		GPIOB_CRL	&=~((0x0F)<<(4*0)); //�������    //����IO��Ϊ���
		GPIOB_CRL	|=((1)<<(4*0));
		GPIOB_ODR &=~(1<<0);  //����ODR�Ĵ���
		
		while(j<1000000)
			j++;
		
		GPIOB_CRL	&=~((0x0F)<<(4*0)); //�������
		
		//����
		GPIOB_CRL &=~((0x0f)<<(4*1));
		GPIOB_CRL |=((1)<<(4*1));
		GPIOB_ODR &=~(1<<1);

		while(j<2000000)
			j++;
		
		GPIOB_CRL	&=~((0x0F)<<(4*1)); //�������
		
		//���
		GPIOB_CRL &=~((0x0f)<<(4*5));
		GPIOB_CRL |=((1)<<(4*5));
		GPIOB_ODR &=~(1<<5);
		while(j<3000000)
			j++;
		GPIOB_CRL	&=~((0x0F)<<(4*5)); //�������
	}
	

//		GPIOB_BSRR &=~(1<<5);
//		GPIOB_CRL &=~((0x0f)<<(4*5));
//		GPIOB_CRL |=(1<<(4*5));
//		




}
void SystemInit()
{
	//������Ϊ�գ�Ŀ����Ϊ��ƭ��������
}

