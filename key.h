#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//��ȡ����0������ֵΪ�ߵ͵�ƽ
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����1

//λ����
//#define KEY0 PEin(4)   							 //KEY0,PE4
//#define KEY1 PEin(3)								 //KEY1,PE3 
 

#define KEY0_PRES 	1								 //KEY0����
#define KEY1_PRES	2								 //KEY1����


void KEY_Init(void);
u8 KEY_Scan(u8);

#endif
