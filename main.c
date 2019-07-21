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
	while(1)												//�𽥱���
	{
		nowtime -= i;
		GPIO_SetBits(GPIOB,GPIO_Pin_5);						//PB5�ߵ�ƽ
		delay_us(maxtime-nowtime);							//�ߵ�ƽʱ��
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);					//PB5�͵�ƽ
		delay_us(nowtime);									//�͵�ƽʱ��
		if(nowtime <= 800)break;
	}
	nowtime = maxtime;
	while(1)												//�𽥱䰵
	{
		nowtime -= i;
		GPIO_SetBits(GPIOB,GPIO_Pin_5);						//PB5�ߵ�ƽ
		delay_us(nowtime);									//�ߵ�ƽʱ��
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);					//PB5�͵�ƽ
		delay_us(maxtime-nowtime);							//�͵�ƽʱ��
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
 		key=KEY_Scan(0);									//�õ���ֵ����֧������������ֵȷ���Ƿ����밴���ĸ�
	   	if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:								//�����
					GPIO_SetBits(GPIOB,GPIO_Pin_5);			//PB.5�ߵ�ƽ
					GPIO_ResetBits(GPIOE,GPIO_Pin_5);		//PE.5�͵�ƽ
					delay_ms(500);
					GPIO_ResetBits(GPIOB,GPIO_Pin_5);		//PB.5�͵�ƽ
					GPIO_SetBits(GPIOE,GPIO_Pin_5);			//PE.5�ߵ�ƽ
					delay_ms(500);
					break;
				case KEY0_PRES:								//������
					LED_breath();
					break;
				defalut:break;
			}
		}
	}	 
}
 

