#include "bsp_systick.h"

void SysTick_Delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);//1us
	for(i=0;i<us;i++)
	{
		while(!((SysTick->CTRL)&(1<<16)));//这里是看CTLK中的COUNTFLAG：当倒数计数至0，这一位会至位1，如果读取了COUNFLAG，这一位会置为0
	}
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;  //延时完毕之后不想再开启定时器，这一句是不使能定时器
}

void SysTick_Delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	for(i=0;i<ms;i++)
	{
		while(!((SysTick->CTRL)&(1<<16)));
	}
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}