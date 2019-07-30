#include "TIMER.h"


void TIM3_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructrue;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	TIM_OCInitTypeDef TIM_OCInitStructrue;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);	//ʹ��TIM3ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//ʹ��GPIOCʱ��
	
	
	GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;	//��������
	GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;//PC6->ENA;PC7->ENB;
	GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50Mhz
	GPIO_Init(GPIOC,&GPIO_InitStructrue);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//ʹ��AFIOʱ��
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//��ȫ��ӳ��PA6->PC6;PA7->PC7��
	
	
	TIM_TimeBaseInitStructrue.TIM_Period = arr;	//�Զ�װ��ֵ
	TIM_TimeBaseInitStructrue.TIM_Prescaler = psc;	//Ԥ��Ƶϵ��
	TIM_TimeBaseInitStructrue.TIM_CounterMode = TIM_CounterMode_Up;	//����ģʽ�����ϼ���
	TIM_TimeBaseInitStructrue.TIM_ClockDivision = TIM_CKD_DIV1;//ʱ�ӷ�Ƶ����
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructrue);//��ʼ����ʱ��
	
	
	TIM_OCInitStructrue.TIM_OCMode = TIM_OCMode_PWM2;//CNT>CCR1Ϊ��Ч
	TIM_OCInitStructrue.TIM_OutputState = TIM_OutputState_Enable;//���ʹ��
	TIM_OCInitStructrue.TIM_OCPolarity = TIM_OCPolarity_High;//��ЧΪ�ߵ�ƽ
	TIM_OC1Init(TIM3,&TIM_OCInitStructrue);//TIM3_CH1(PC6)
	
	
	TIM_OCInitStructrue.TIM_OCMode = TIM_OCMode_PWM2;//CNT>CCR2Ϊ��Ч
	TIM_OCInitStructrue.TIM_OutputState = TIM_OutputState_Enable;//���ʹ��
	TIM_OCInitStructrue.TIM_OCPolarity = TIM_OCPolarity_High;//��ЧΪ�ߵ�ƽ
	TIM_OC2Init(TIM3,&TIM_OCInitStructrue);	//TIM3_CH2(PC7)
	
	
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);//ʹ��Ԥװ�ؼĴ���
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//ʹ��Ԥװ�ؼĴ���
	
	
	TIM_Cmd(TIM3,ENABLE);//ʹ�ܶ�ʱ��
	
}

