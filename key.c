#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

								    
void KEY_Init(void)
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//使能时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_4;//PE3,PE4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
 	GPIO_Init(GPIOE, &GPIO_InitStructure);					

}


u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;	//keyup = 1表示上一状态为未按下
	if(mode)key_up=1;  //支持连按与否，mode = 1支持连按，mode = 0不支持连按		  
	if(key_up&&(KEY0==0||KEY1==0))//按下
	{
		delay_ms(10);//去抖动 
		key_up=0;//已经按下
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
	}else if(KEY0==1&&KEY1==1)key_up=1;	//无按键按下 	    
 	return 0;
}

