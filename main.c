#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	
delay_init();
LED_Init();

//�⺯������
while(1)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);			//PB.5�ߵ�ƽ
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);		//PE.5�͵�ƽ
	
	delay_ms(500);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);		//PB.5�͵�ƽ
	GPIO_SetBits(GPIOE,GPIO_Pin_5);			//PE.5�ߵ�ƽ
	
	delay_ms(500);
}
}


//�Ĵ�������
//while(1)
//{
// GPIOB->ODR |= 1<<5;			//PB.5�ߵ�ƽ����ֵ��������
// GPIOE->ODR &= ~(1<<5);		//PE.5�͵�ƽ����ֵ��������
// delay_ms(500);				//��ʱ
//	
// GPIOB->ODR &= ~(1<<5);		//PB.5�͵�ƽ
// GPIOE->ODR |= 1<<5;			//PE.5�ߵ�ƽ
// delay_ms(500);				//��ʱ
//}



//λ����
//while(1)
//{
//	PBout(5) = 1;				//PB.5�ߵ�ƽ
//	PEout(5) = 0;				//PE.5�͵�ƽ
//	
//	delay_ms(500);
//	
//	PBout(5) = 0;				//PB.5�͵�ƽ
//	PEout(5) = 1;				//PE.5�ߵ�ƽ
//	
//	delay_ms(500);
//}

