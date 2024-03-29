#include "angsens.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//Angsens(光敏传感器)驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/7
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved										  
//////////////////////////////////////////////////////////////////////////////////
  
//初始化角度传感器
void Angsens_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//使能GPIOF时钟
	
  //先初始化ADC3通道7IO口
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//PF7 通道7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//模拟输入
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//不带上下拉
  GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化  
 
	Adc3_Init();//初始化ADC3
}
//读取Light Sens的值
//0~100:0,最暗;100,最亮 
u32 Angsens_Get_Val(void)
{
	u32 temp_val=0;	
	u8 i=0;
	for(;i<ANGSENS_READ_TIMES;i++)
	{
		temp_val+=Get_Adc3(ADC_Channel_5);	//读取ADC值,通道5
		delay_ms(5);
	}
	temp_val/=ANGSENS_READ_TIMES;
	return temp_val;
}












