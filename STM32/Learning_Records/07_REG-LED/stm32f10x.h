//用来存放寄存器映射的代码
//外设 perirhral

//三条总线的基地址
#define PERIRH_BASE								((unsigned int)0x40000000)
#define APB1PERIRH_BASE					 PERIRH_BASE
#define APB2PERIRH_BASE					 	(PERIRH_BASE+0x10000)
#define AHBPERIRH_BASE					 	(PERIRH_BASE+0x20000)
	
#define RCC_BASE									(AHBPERIRH_BASE+0x1000)
#define GPIOB_BASE								(APB2PERIRH_BASE+0x0C00)   

//以上是为了把最终寄存器的地址推导出来，仅仅是做数值运算，不加*

//寄存器

#define RCC_APB2ENR								*(unsigned int*)(RCC_BASE+0x18)//寄存器要用指针
	
#define GPIOB_CRL									*(unsigned int*)(GPIOB_BASE)
#define GPIOB_CRH									*(unsigned int*)(GPIOB_BASE+0x04)
#define GPIOB_ODR									*(unsigned int*)(GPIOB_BASE+0x0C)
	



