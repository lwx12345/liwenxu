#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	
delay_init();
LED_Init();

//库函数操作
while(1)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_5);			//PB.5高电平
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);		//PE.5低电平
	
	delay_ms(500);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);		//PB.5低电平
	GPIO_SetBits(GPIOE,GPIO_Pin_5);			//PE.5高电平
	
	delay_ms(500);
}
}


//寄存器操作
//while(1)
//{
// GPIOB->ODR |= 1<<5;			//PB.5高电平，赋值，或运算
// GPIOE->ODR &= ~(1<<5);		//PE.5低电平，赋值，与运算
// delay_ms(500);				//延时
//	
// GPIOB->ODR &= ~(1<<5);		//PB.5低电平
// GPIOE->ODR |= 1<<5;			//PE.5高电平
// delay_ms(500);				//延时
//}



//位操作
//while(1)
//{
//	PBout(5) = 1;				//PB.5高电平
//	PEout(5) = 0;				//PE.5低电平
//	
//	delay_ms(500);
//	
//	PBout(5) = 0;				//PB.5低电平
//	PEout(5) = 1;				//PE.5高电平
//	
//	delay_ms(500);
//}

