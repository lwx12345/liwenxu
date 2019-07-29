#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

								    
void KEY_Init(void)
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//ʹ��ʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3|GPIO_Pin_4;//PE3,PE4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //��������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);					

}


u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;	//keyup = 1��ʾ��һ״̬Ϊδ����
	if(mode)key_up=1;  //֧���������mode = 1֧��������mode = 0��֧������		  
	if(key_up&&(KEY0==0||KEY1==0))//����
	{
		delay_ms(10);//ȥ���� 
		key_up=0;//�Ѿ�����
		if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
	}else if(KEY0==1&&KEY1==1)key_up=1;	//�ް������� 	    
 	return 0;
}

