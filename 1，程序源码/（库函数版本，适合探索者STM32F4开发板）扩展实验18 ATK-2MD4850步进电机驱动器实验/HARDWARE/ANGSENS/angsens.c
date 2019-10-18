#include "angsens.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//Angsens(����������)��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/7
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved										  
//////////////////////////////////////////////////////////////////////////////////
  
//��ʼ���Ƕȴ�����
void Angsens_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ��GPIOFʱ��
	
  //�ȳ�ʼ��ADC3ͨ��7IO��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//PF7 ͨ��7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;//ģ������
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;//����������
  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��  
 
	Adc3_Init();//��ʼ��ADC3
}
//��ȡLight Sens��ֵ
//0~100:0,�;100,���� 
u32 Angsens_Get_Val(void)
{
	u32 temp_val=0;	
	u8 i=0;
	for(;i<ANGSENS_READ_TIMES;i++)
	{
		temp_val+=Get_Adc3(ADC_Channel_5);	//��ȡADCֵ,ͨ��5
		delay_ms(5);
	}
	temp_val/=ANGSENS_READ_TIMES;
	return temp_val;
}












