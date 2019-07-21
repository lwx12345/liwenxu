#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"

#define maxtime 5000										//5ms
#define i 500

void LED_breath(void)
{
	unsigned int nowtime = 0;
	nowtime = maxtime;
	while(1)												//逐渐变亮
	{
		nowtime -= i;
		GPIO_SetBits(GPIOB,GPIO_Pin_5);						//PB5高电平
		delay_us(maxtime-nowtime);							//高电平时间
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);					//PB5低电平
		delay_us(nowtime);									//低电平时间
		if(nowtime <= 800)break;
	}
	nowtime = maxtime;
	while(1)												//逐渐变暗
	{
		nowtime -= i;
		GPIO_SetBits(GPIOB,GPIO_Pin_5);						//PB5高电平
		delay_us(nowtime);									//高电平时间
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);					//PB5低电平
		delay_us(maxtime-nowtime);							//低电平时间
		if(nowtime <= 800)break;
	}
}


 int main(void)
 {
 	vu8 key=0;												//volatile unsigned char	
	delay_init();	   	  
 	LED_Init();			 
	KEY_Init();         
	while(1)
	{
 		key=KEY_Scan(0);									//得到键值，不支持连按，返回值确定是否按下与按下哪个
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:								//跑马灯
					GPIO_SetBits(GPIOB,GPIO_Pin_5);			//PB.5高电平
					GPIO_ResetBits(GPIOE,GPIO_Pin_5);		//PE.5低电平
					delay_ms(500);
					GPIO_ResetBits(GPIOB,GPIO_Pin_5);		//PB.5低电平
					GPIO_SetBits(GPIOE,GPIO_Pin_5);			//PE.5高电平
					delay_ms(500);
					break;
				case KEY0_PRES:								//呼吸灯
					LED_breath();
					break;
				defalut:break;
			}
		}
	}	 
}
 

