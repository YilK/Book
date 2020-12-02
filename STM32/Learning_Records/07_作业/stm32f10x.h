//用来存放寄存器映射的代码
//外设 perirhral

//外设基地址
#define PERIRH_BASE					(unsigned int)(0x40000000)
	
//总线地址 APB1\APB2\ABH
#define APB1PERIRH_BASE			PERIRH_BASE
#define APB2PERIRH_BASE			(PERIRH_BASE+0x10000)
#define AHBPERIRH_BASE			(PERIRH_BASE+0x20000)  //这里将AHB中的保留和SDIO直接没算进去，为了以后的方便使用


//具体的外设地址
#define RCC_BASE						(AHBPERIRH_BASE+0x1000) //复位和时钟控制
#define GPIOB_BASE					(APB2PERIRH_BASE+0x0C00)

//特定的寄存器地址 ,强制转换成指针
#define RCC_APB2ENR					*(unsigned int *)(RCC_BASE+0x18)
#define GPIOB_ODR						*(unsigned int *)(GPIOB_BASE+0x0C)
#define GPIOB_CRL						*(unsigned int *)(GPIOB_BASE)
#define GPIOB_CRH						*(unsigned int *)(GPIOB_BASE+0x04)
#define GPIOB_IDR						*(unsigned int *)(GPIOB_BASE+0x08)
#define GPIOB_BSRR					*(unsigned int *)(GPIOB_BASE+0x10)
#define GPIOB_BRR						*(unsigned int *)(GPIOB_BASE+0x14)
#define GPIOB_LCKR					*(unsigned int *)(GPIOB_BASE+0x18)
	


