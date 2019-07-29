#include "stm32f10x.h"
#include "key.h"
#include "delay.h"
#include "TIMER.h"
#include "MOTOR.h"


#define IN1_ON		GPIO_SetBits(GPIOB,GPIO_Pin_3)
#define IN1_OFF		GPIO_ResetBits(GPIOB,GPIO_Pin_3)
#define IN2_ON		GPIO_SetBits(GPIOB,GPIO_Pin_4)
#define IN2_OFF		GPIO_ResetBits(GPIOB,GPIO_Pin_4)
#define IN3_ON		GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define IN3_OFF		GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define IN4_ON		GPIO_SetBits(GPIOB,GPIO_Pin_6)
#define IN4_OFF		GPIO_ResetBits(GPIOB,GPIO_Pin_6)

void zhengzhuan(void)//��ת
{
	u8 i = 0;
	while(1)
	{
		switch(i)
		{
			case 0:
				IN1_OFF; IN2_ON;  IN3_ON;  IN4_ON; //0111
			case 1:
				IN1_ON;  IN2_OFF; IN3_ON;  IN4_ON; //1011
			case 2:
				IN1_ON;  IN2_ON;  IN3_OFF; IN4_ON; //1101
			case 3:
				IN1_ON;  IN2_ON;  IN3_ON;  IN4_OFF;//1110
			default:break;
		}
		i++;
		if(i == 4)i = 0;
		delay_ms(4);
	}
}
void fanzhuan(void)//��ת
{
	u8 i = 0;
	while(1)
	{
		switch(i)
		{
			case 0:
				IN1_ON;  IN2_ON;  IN3_ON;  IN4_OFF;//1110
			case 1:
				IN1_ON;  IN2_ON;  IN3_OFF; IN4_ON; //1101
			case 2:
				IN1_ON;  IN2_OFF; IN3_ON;  IN4_ON; //1011
			case 3:
				IN1_OFF; IN2_ON;  IN3_ON;  IN4_ON; //0111
			default:break;
		}
		i++;
		if(i == 4)i = 0;
		delay_ms(4);
	}
}
int main(void)
{
	vu8 key = 0;
	KEY_Init();
	delay_init();
	motor_Init();
	TIM3_PWM_Init(1999,719);//PWMƵ��:72000000/((1999+1)(719+1)) = 50hz
	while(1)//��ת
	{
		key=KEY_Scan(0);//�õ���ֵ����֧������������ֵȷ���Ƿ����밴���ĸ�
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:	//��ת
					zhengzhuan();
					break;
				case KEY0_PRES:	//��ת
					fanzhuan();
					break;
				default:break;
			}
		}
	}
	
}

