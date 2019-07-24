#include "TIMER.h"

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);				//ʹ��TIM3ʱ��
	
	TIM_TimeBaseInitStructrue.TIM_Period = arr;						//�Զ�װ��ֵ
	TIM_TimeBaseInitStructrue.TIM_Prescaler = psc;					//Ԥ��Ƶϵ��
	TIM_TimeBaseInitStructrue.TIM_CounterMode = TIM_CounterMode_Up;	//����ģʽ�����ϼ���
	TIM_TimeBaseInitStructrue.TIM_ClockDivision = TIM_CKD_DIV1;		//ʱ�ӷ�Ƶ����
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);				//��ʼ����ʱ��
	
	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);						//ʹ��TIM3�����ж�
	
	
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  				//TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		//��ռ���ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  			//��Ӧ���ȼ�Ϊ2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 				//IRQͨ��ʹ��
	
	NVIC_Init(&NVIC_InitStructure);  								//��ʼ��NVIC�Ĵ���
	
	
	TIM_Cmd(TIM3,ENABLE);											//ʹ�ܶ�ʱ��
}


void TIM3_IRQHandler(void)											//�жϷ�����
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET)					//��ø����жϱ�־
	{
		PBout(5) = !PBout(5);										//led�Ʒ�ת
		PEout(5) = !PEout(5);
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);					//��������жϱ�־
		
	}
	
}

