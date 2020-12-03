#ifndef __BSP_SYSTICK_H

#define __BSP_SYSTICK_H
#include "stm32f10x.h"		//这个还是要在上面的
#include "core_cm3.h"

void SysTick_Delay_ms(uint32_t ms);
void SysTick_Delay_us(uint32_t us);

#endif /*__BSP_SYSTICK_H*/