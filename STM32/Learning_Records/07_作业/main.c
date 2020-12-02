#include "stm32f10x.h"

int main()
{
	
	//打开GPIOB的端口时钟
	RCC_APB2ENR |=(1<<3);
	while(1)   //流水灯作业
	{	
		//绿灯
		int j=0;
		GPIOB_CRL	&=~((0x0F)<<(4*0)); //清零操作    //设置IO口为输出
		GPIOB_CRL	|=((1)<<(4*0));
		GPIOB_ODR &=~(1<<0);  //配置ODR寄存器
		
		while(j<1000000)
			j++;
		
		GPIOB_CRL	&=~((0x0F)<<(4*0)); //清零操作
		
		//蓝灯
		GPIOB_CRL &=~((0x0f)<<(4*1));
		GPIOB_CRL |=((1)<<(4*1));
		GPIOB_ODR &=~(1<<1);

		while(j<2000000)
			j++;
		
		GPIOB_CRL	&=~((0x0F)<<(4*1)); //清零操作
		
		//红灯
		GPIOB_CRL &=~((0x0f)<<(4*5));
		GPIOB_CRL |=((1)<<(4*5));
		GPIOB_ODR &=~(1<<5);
		while(j<3000000)
			j++;
		GPIOB_CRL	&=~((0x0F)<<(4*5)); //清零操作
	}
	

//		GPIOB_BSRR &=~(1<<5);
//		GPIOB_CRL &=~((0x0f)<<(4*5));
//		GPIOB_CRL |=(1<<(4*5));
//		




}
void SystemInit()
{
	//函数体为空，目的是为了骗过编译器
}

