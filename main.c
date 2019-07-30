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


int main(void)
{
	vu8 key = 0;
	u8 dir = 1;
	u16 pwmval = 7190;
	KEY_Init();
	delay_init();
	motor_Init();
	TIM3_PWM_Init(7199,199);//PWM频率:72000000/((7199+1)(199+1)) = 50hz
	while(1)//正转
	{
		while(1)//正转,速度先增加后减小
		{
			if(dir)pwmval -= 10;
			else pwmval +=10;
			IN1_ON; IN2_OFF;//M1正转
			IN3_ON; IN4_OFF;//M2正转
			TIM_SetCompare1(TIM3,pwmval); //改变CCR1的值
			TIM_SetCompare2(TIM3,pwmval); //改变CCR2的值
			if(pwmval <= 100)dir--;
			if(dir == 0&&pwmval >= 7190)
			{
				dir++;
				break;
			}
		}
		delay_ms(10);
		while(1)//反转,速度先增加后减小
		{
			if(dir)pwmval -= 10;
			else pwmval +=10;
			IN1_OFF; IN2_ON;//M1反转
			IN3_OFF; IN4_ON;//M2反转
			TIM_SetCompare1(TIM3,pwmval); //改变CCR1的值
			TIM_SetCompare2(TIM3,pwmval); //改变CCR2的值
			if(pwmval <= 100)dir--;
			if(dir == 0&&pwmval >= 7190)
			{
				dir++;
				break;
			}
		}
		IN1_OFF;IN2_OFF;//停止
		IN3_OFF;IN4_OFF;
		delay_ms(500);
		
	}
	
}

