#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_exti.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	LED_GPIO_Config();
	EXTI_Key_Config();
	
//	while(1)
//	{
//		//GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
//		LED_G(OFF);
//		Delay(0xFFFFF);
//		//GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
//		LED_G(ON);
//		Delay(0xFFFFF);
//	}
	while(1)
	{
		
	}
}

// ��ҵ

// 1��ʹ�ù̼����̵ķ�ʽ����ʣ�µ�����LED��Ҳ��������ʵ����ˮ�Ƶ���ʽ
