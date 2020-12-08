#include "bsp_usart.h"

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Ƕ�������жϿ�������ѡ�� */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* ����USARTΪ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
  /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* �����ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ʹ���ж� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure);
}
void USART_Config()
{
	
	//�����ʼ���ṹ��
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;
	
	//��ʱ��
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	
	//��ʼ��GPIO
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);
	
	//���ô��ڲ���
	USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	//��ɴ��ڳ�ʼ������
	USART_Init(DEBUG_USARTx,&USART_InitStructure);
	//�����ж����ȼ�����
	NVIC_Configuration();
//	
//	//ʹ�ܴ��ڽ����ж�
	USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
	//ʹ��USART
	USART_Cmd(DEBUG_USARTx,ENABLE);
}
void USART_SendByte(USART_TypeDef* pSARTx,uint8_t ch)   //����һ���ֽڵ�����
{
	USART_SendData(pSARTx,ch);
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TXE)==RESET);//�������ݼĴ���Ϊ��
}
void USART_SendArray(USART_TypeDef* pSARTx,uint16_t data)	//���������ֽ�����
{
	uint8_t temp_h,temp_l;
	temp_h=(data&0xff00)>>8;
	temp_l=(data&0x00ff);
	USART_SendData(pSARTx,temp_h);
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TXE)==RESET);//�������ݼĴ���Ϊ��
	
	USART_SendByte(pSARTx,temp_l);
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TXE)==RESET);//�������ݼĴ���Ϊ��
}

void USART_SendString(USART_TypeDef* pSARTx,uint8_t *str)		//�����ַ���0
{
	uint8_t i=0;
	do
	{
		USART_SendByte(pSARTx,*(str+i));
		i++;
	}while(*(str+i)!='\0');
	while(USART_GetFlagStatus(pSARTx, USART_FLAG_TC)==RESET);
}
