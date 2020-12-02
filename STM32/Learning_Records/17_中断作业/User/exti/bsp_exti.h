#ifndef __BSH_EXTI_H

#define  __BSH_EXTI_H

#include "stm32f10x.h"

#define KEY2_INT_GPIO_PIN              GPIO_Pin_13
#define KEY2_INT_GPIO_PORT             GPIOC
#define KEY2_INT_GPIO_CLK              RCC_APB2Periph_GPIOC

void EXTI_Key_Config();
#endif /* __BSH_EXTI_H*/


