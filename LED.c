#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{

 GPIO_InitTypeDef GPIO_InitStructure;					//����
	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	//GPIOBʹ��ʱ��
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);	//GPIOEʹ��ʱ��
	
	
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//�������
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				//PB.5
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
 GPIO_Init(GPIOB,&GPIO_InitStructure);
	
 GPIO_SetBits(GPIOB,GPIO_Pin_5);						//GPIOB.5��ʼ�ߵ�ƽ
	
	
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//�������
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				//PE.5
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
 GPIO_Init(GPIOE,&GPIO_InitStructure);
	
 GPIO_SetBits(GPIOE,GPIO_Pin_5);						//GPIOE.5��ʼ�ߵ�ƽ

}

