#include "bsp_usart.h"



//static void NVIC_Configuration(void)
//{
//  NVIC_InitTypeDef NVIC_InitStructure;
//  
//  /* Ƕ�������жϿ�������ѡ�� */
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  
//  /* ����USARTΪ�ж�Դ */
//  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
//  /* �������ȼ�*/
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//  /* �����ȼ� */
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//  /* ʹ���ж� */
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  /* ��ʼ������NVIC */
//  NVIC_Init(&NVIC_InitStructure);
//}

void USART_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// �򿪴���GPIO��ʱ��
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);
	
	// �򿪴��������ʱ��
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);

	// ��USART Tx��GPIO����Ϊ���츴��ģʽ
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // ��USART Rx��GPIO����Ϊ��������ģʽ
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	
	// ���ô��ڵĹ�������
	// ���ò�����
	USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;
	// ���� �������ֳ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ����ֹͣλ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ����У��λ
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ����Ӳ��������
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// ���ù���ģʽ���շ�һ��
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// ��ɴ��ڵĳ�ʼ������
	USART_Init(DEBUG_USARTx, &USART_InitStructure);
	
//	// �����ж����ȼ�����
//	NVIC_Configuration();
//	
//	// ʹ�ܴ��ڽ����ж�
//	USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE);	
//	
	// ʹ�ܴ���
	USART_Cmd(DEBUG_USARTx, ENABLE);	    
}


//����һ���ֽ�
void Usart_SendByte(USART_TypeDef* pSARTx,uint8_t data)//ָ������һ�����ڣ�ָ��Ҫ���͵����ݣ�  1���ֽ�8λ
{
	USART_SendData(pSARTx,data);
	while(USART_GetFlagStatus(pSARTx,USART_FLAG_TXE)==RESET );//���ݻ�û�б�ת�Ƶ���λ�Ĵ���
}


//���������ֽڵ�����

void Usart_SendHalfWord(USART_TypeDef* pSARTx,uint16_t data)//�����ֽ�16λ
{
	uint8_t temp_h,temp_l;
	temp_h=(data&0xff00)>>8;
	temp_l=(data&0x00ff);
	
	USART_SendData(pSARTx,temp_h);    //USART_SendDataֻ�ܷ�8λ�����ݣ���Ϊʲô�βλ�Ҫ�����16λ����
	while(USART_GetFlagStatus(pSARTx,USART_FLAG_TXE)==RESET );//���ݻ�û�б�ת�Ƶ���λ�Ĵ���
	
	USART_SendData(pSARTx,temp_l);
	while(USART_GetFlagStatus(pSARTx,USART_FLAG_TXE)==RESET );//���ݻ�û�б�ת�Ƶ���λ�Ĵ���
	
}

//���Ͱ�λ���ݵ�����
void Usart_SendArray(USART_TypeDef* pSARTx,uint8_t *array,uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte(pSARTx,*array++);
	}
	while(USART_GetFlagStatus(pSARTx,USART_FLAG_TC)==RESET );//����Ҫ�õ�TC
}

//�����ַ���
void Usart_SendString(USART_TypeDef* pSARTx,uint8_t *str)
{
	uint8_t i=0;
	do{
		Usart_SendByte(pSARTx,*(str+i));
		i++;
	}while(*(str+i)!='\0');
	while(USART_GetFlagStatus(pSARTx,USART_FLAG_TC)==RESET );
}


///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ����� */
		USART_SendData(DEBUG_USARTx, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
		/* �ȴ������������� */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(DEBUG_USARTx);
}


//���ڷ��Ͷ���8λ8λ�ķ�������һ���ֽ�һ���ֽڵķ�

