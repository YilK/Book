#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_usart.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
//	uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
//	LED_GPIO_Config();
	uint8_t ch;
	USART_Config();//��ʼ������
	LED_GPIO_Config();
//	Usart_SendByte(DEBUG_USARTx,'A');
//		Usart_SendHalfWord(DEBUG_USARTx,0Xff56);
//	Usart_SendArray(DEBUG_USARTx,a,10);
//	Usart_SendString(DEBUG_USARTx,"��ӭʹ��stm32");
	printf("����һ�����ڿ���RGB�Ƶĳ���\n");

	
	while(1)
	{
		ch=getchar();
		printf("ch=%c\n",ch);
		
		switch(ch)
		{
			case '1':
					LED_G(OFF);
					break;
			default:
				LED_G(ON);
			
		}
	}
}

// ��ҵ

// 1��ʹ�ù̼����̵ķ�ʽ����ʣ�µ�����LED��Ҳ��������ʵ����ˮ�Ƶ���ʽ
