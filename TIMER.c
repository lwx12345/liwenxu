#include "TIMER.h"

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);				//使能TIM3时钟
	
	TIM_TimeBaseInitStructrue.TIM_Period = arr;						//自动装载值
	TIM_TimeBaseInitStructrue.TIM_Prescaler = psc;					//预分频系数
	TIM_TimeBaseInitStructrue.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式，向上计数
	TIM_TimeBaseInitStructrue.TIM_ClockDivision = TIM_CKD_DIV1;		//时钟分频因子
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);				//初始化定时器
	
	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);						//使能TIM3更新中断
	
	
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  				//TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  		//抢占优先级为1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  			//响应优先级为2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 				//IRQ通道使能
	
	NVIC_Init(&NVIC_InitStructure);  								//初始化NVIC寄存器
	
	
	TIM_Cmd(TIM3,ENABLE);											//使能定时器
}


void TIM3_IRQHandler(void)											//中断服务函数
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET)					//获得更新中断标志
	{
		PBout(5) = !PBout(5);										//led灯翻转
		PEout(5) = !PEout(5);
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);					//清除更新中断标志
		
	}
	
}

