#include "stm32f10x.h"
#include "led.h"
#include "TIMER.h"

int main(void)
{
	
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ2
	
	
LED_Init();

	
//ARR <= 65535; PSC <= 65535;
//Tout�����ʱ�䣩=��ARR+1)(PSC+1)/Tclk		Tout(us);Tclk(Mhz);
//2s = 2000000us = (19999+1)(7199+1)/72
TIM3_Int_Init(19999,7199);					   //2s
	
	
while(1);
	
}

