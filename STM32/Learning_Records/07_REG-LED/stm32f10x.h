//������żĴ���ӳ��Ĵ���
//���� perirhral

//�������ߵĻ���ַ
#define PERIRH_BASE								((unsigned int)0x40000000)
#define APB1PERIRH_BASE					 PERIRH_BASE
#define APB2PERIRH_BASE					 	(PERIRH_BASE+0x10000)
#define AHBPERIRH_BASE					 	(PERIRH_BASE+0x20000)
	
#define RCC_BASE									(AHBPERIRH_BASE+0x1000)
#define GPIOB_BASE								(APB2PERIRH_BASE+0x0C00)   

//������Ϊ�˰����ռĴ����ĵ�ַ�Ƶ�����������������ֵ���㣬����*

//�Ĵ���

#define RCC_APB2ENR								*(unsigned int*)(RCC_BASE+0x18)//�Ĵ���Ҫ��ָ��
	
#define GPIOB_CRL									*(unsigned int*)(GPIOB_BASE)
#define GPIOB_CRH									*(unsigned int*)(GPIOB_BASE+0x04)
#define GPIOB_ODR									*(unsigned int*)(GPIOB_BASE+0x0C)
	



