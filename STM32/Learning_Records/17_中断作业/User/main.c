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

	while(1)
	{
		
	}
}

// ��ҵ

// 1��ʹ�ù̼����̵ķ�ʽ����ʣ�µ�����LED��Ҳ��������ʵ����ˮ�Ƶ���ʽ
