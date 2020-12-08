#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_usart.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
//	uint8_t a[10]={1,2,3,4,5,6,7,8,9,10};
	// 来到这里的时候，系统的时钟已经被配置成72M。
//	LED_GPIO_Config();
	uint8_t ch;
	USART_Config();//初始化串口
	LED_GPIO_Config();
//	Usart_SendByte(DEBUG_USARTx,'A');
//		Usart_SendHalfWord(DEBUG_USARTx,0Xff56);
//	Usart_SendArray(DEBUG_USARTx,a,10);
//	Usart_SendString(DEBUG_USARTx,"欢迎使用stm32");
	printf("这是一个串口控制RGB灯的程序\n");

	
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

// 作业

// 1、使用固件库编程的方式，把剩下的两个LED灯也点亮，并实现流水灯的形式
