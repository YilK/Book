
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
	
	RCC->APB2ENR |=(1<<3);//打开端口时钟
	GPIOB->CRL &=~((0x0f)<<(4*0));//配置IO口为输出
	GPIOB->CRL |=(1<<(4*0));
	
//	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	
#elif 1
	GPIO_InitTypeDef GPIO_InitStructure;//这里需要注意定义变量必须在最前面。
	RCC->APB2ENR |=(1<<3);//打开端口时钟
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;//定义引脚
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//定义推挽输出。
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;//定义输出的速率。
	//写入寄存器。
	GPIO_Init(GPIOB, &GPIO_InitStructure);//第一个参数是哪个GPIO端口，第二个是结构体的地址
	
	
	
#endif 


}

void SystemInit(void)
{
	// 函数体为空，目的是为了骗过编译器不报错
}









