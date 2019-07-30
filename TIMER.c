#include "TIMER.h"


void TIM3_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructrue;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	TIM_OCInitTypeDef TIM_OCInitStructrue;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);	//使能TIM3时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//使能GPIOC时钟
	
	
	GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽
	GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;//PC6->ENA;PC7->ENB;
	GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;//速度50Mhz
	GPIO_Init(GPIOC,&GPIO_InitStructrue);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//使能AFIO时钟
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//完全重映像（PA6->PC6;PA7->PC7）
	
	
	TIM_TimeBaseInitStructrue.TIM_Period = arr;	//自动装载值
	TIM_TimeBaseInitStructrue.TIM_Prescaler = psc;	//预分频系数
	TIM_TimeBaseInitStructrue.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式，向上计数
	TIM_TimeBaseInitStructrue.TIM_ClockDivision = TIM_CKD_DIV1;//时钟分频因子
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);//初始化定时器
	
	
	TIM_OCInitStructrue.TIM_OCMode = TIM_OCMode_PWM2;//CNT>CCR1为有效
	TIM_OCInitStructrue.TIM_OutputState = TIM_OutputState_Enable;//输出使能
	TIM_OCInitStructrue.TIM_OCPolarity = TIM_OCPolarity_High;//有效为高电平
	TIM_OC1Init(TIM3,&TIM_OCInitStructrue);//TIM3_CH1(PC6)
	
	
	TIM_OCInitStructrue.TIM_OCMode = TIM_OCMode_PWM2;//CNT>CCR2为有效
	TIM_OCInitStructrue.TIM_OutputState = TIM_OutputState_Enable;//输出使能
	TIM_OCInitStructrue.TIM_OCPolarity = TIM_OCPolarity_High;//有效为高电平
	TIM_OC2Init(TIM3,&TIM_OCInitStructrue);	//TIM3_CH2(PC7)
	
	
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);//使能预装载寄存器
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//使能预装载寄存器
	
	
	TIM_Cmd(TIM3,ENABLE);//使能定时器
	
}

