#include "stm32f10x.h"


void USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//ʹ�ܴ���ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��GPIOAʱ��
	
	
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_9;//TX
	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_AF_PP;//���츴�����
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_10;//RX
	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	
	USART_InitStrue.USART_BaudRate = 115200;//������
	USART_InitStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��ʹ��Ӳ����
	USART_InitStrue.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;//���ͽ���ʹ��
	USART_InitStrue.USART_Parity = USART_Parity_No;//��ʹ����żУ��
	USART_InitStrue.USART_StopBits = USART_StopBits_1;//1λֹͣλ
	USART_InitStrue.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8
	USART_Init(USART1,&USART_InitStrue);//����1������ʼ��
	
	
	USART_Cmd(USART1,ENABLE);//ʹ�ܴ���1
	
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//���ջ������ǿ��ж�
	
	
	NVIC_InitStrue.NVIC_IRQChannel = USART1_IRQn;//����1�ж�
	NVIC_InitStrue.NVIC_IRQChannelCmd = ENABLE;//IQRͨ��ʹ��
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority = 1;//��ռ���ȼ�
	NVIC_InitStrue.NVIC_IRQChannelSubPriority = 2;//��Ӧ���ȼ�
	NVIC_Init(&NVIC_InitStrue);
}

void USART1_IRQHandler(void)//����1�жϷ�����
{
	u8 rec;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))//������ܵ�����
	{
		rec = USART_ReceiveData(USART1);//��ȡ���յ�������
	}
}

int main(void)
{
	u8 x = 100;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2λ��ռ��2λ��Ӧ
	USART1_Init();
	
	USART_SendData(USART1,x);//��������
	while(1);
}
 
 
