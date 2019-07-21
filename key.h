#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//读取按键0，返回值为高低电平
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1

//位操作
//#define KEY0 PEin(4)   							 //KEY0,PE4
//#define KEY1 PEin(3)								 //KEY1,PE3 
 

#define KEY0_PRES 	1								 //KEY0按下
#define KEY1_PRES	2								 //KEY1按下


void KEY_Init(void);
u8 KEY_Scan(u8);

#endif
