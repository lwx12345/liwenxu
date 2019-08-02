#include "stm32f10x.h"


void USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能串口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能GPIOA时钟
	
	
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_9;//TX
	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_AF_PP;//推挽复用输出
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_10;//RX
	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	
	USART_InitStrue.USART_BaudRate = 115200;//波特率
	USART_InitStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//不使用硬件流
	USART_InitStrue.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;//发送接收使能
	USART_InitStrue.USART_Parity = USART_Parity_No;//不使用奇偶校验
	USART_InitStrue.USART_StopBits = USART_StopBits_1;//1位停止位
	USART_InitStrue.USART_WordLength = USART_WordLength_8b;//字长为8
	USART_Init(USART1,&USART_InitStrue);//串口1参数初始化
	
	
	USART_Cmd(USART1,ENABLE);//使能串口1
	
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//接收缓冲区非空中断
	
	
	NVIC_InitStrue.NVIC_IRQChannel = USART1_IRQn;//串口1中断
	NVIC_InitStrue.NVIC_IRQChannelCmd = ENABLE;//IQR通道使能
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级
	NVIC_InitStrue.NVIC_IRQChannelSubPriority = 2;//响应优先级
	NVIC_Init(&NVIC_InitStrue);
}

void USART1_IRQHandler(void)//串口1中断服务函数
{
	u8 rec;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))//如果接受到数据
	{
		rec = USART_ReceiveData(USART1);//读取接收到的数据
	}
}

int main(void)
{
	u8 x = 100;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2位抢占，2位响应
	USART1_Init();
	
	USART_SendData(USART1,x);//发送数据
	while(1);
}
 
 
