//������żĴ���ӳ��Ĵ���
//���� perirhral

//�������ַ
#define PERIRH_BASE					(unsigned int)(0x40000000)
	
//���ߵ�ַ APB1\APB2\ABH
#define APB1PERIRH_BASE			PERIRH_BASE
#define APB2PERIRH_BASE			(PERIRH_BASE+0x10000)
#define AHBPERIRH_BASE			(PERIRH_BASE+0x20000)  //���ｫAHB�еı�����SDIOֱ��û���ȥ��Ϊ���Ժ�ķ���ʹ��


//����������ַ
#define RCC_BASE						(AHBPERIRH_BASE+0x1000) //��λ��ʱ�ӿ���
#define GPIOB_BASE					(APB2PERIRH_BASE+0x0C00)

//�ض��ļĴ�����ַ ,ǿ��ת����ָ��
#define RCC_APB2ENR					*(unsigned int *)(RCC_BASE+0x18)
#define GPIOB_ODR						*(unsigned int *)(GPIOB_BASE+0x0C)
#define GPIOB_CRL						*(unsigned int *)(GPIOB_BASE)
#define GPIOB_CRH						*(unsigned int *)(GPIOB_BASE+0x04)
#define GPIOB_IDR						*(unsigned int *)(GPIOB_BASE+0x08)
#define GPIOB_BSRR					*(unsigned int *)(GPIOB_BASE+0x10)
#define GPIOB_BRR						*(unsigned int *)(GPIOB_BASE+0x14)
#define GPIOB_LCKR					*(unsigned int *)(GPIOB_BASE+0x18)
	


