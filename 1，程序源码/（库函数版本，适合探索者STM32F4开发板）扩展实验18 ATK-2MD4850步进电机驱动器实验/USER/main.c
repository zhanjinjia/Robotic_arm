#include "sys.h"
#include "delay.h"  
#include "usart.h"  
#include "led.h"
#include "usmart.h"
#include "key.h"
#include "driver.h"
#include "adc3.h"
#include "angsens.h"
#include "string.h"
#include "pid.h"

//ALIENTEK 探索者STM32F407开发板 
//步进电机驱动器 测试代码  
//技术支持:www.openedv.com
//广州市星翼电子科技有限公司 
extern u16 dir;
int main(void)
{ 
	u8 i;
	int j;
	u8 keyval;
	u32 adcx;
	long RxData=0;
	long pul=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
//	usmart_dev.init(84); 	//初始化USMART			
	LED_Init();					  //初始化LED
 	KEY_Init();					//按键初始化
	Driver_Init();			//驱动器初始化
	TIM8_OPM_RCR_Init(999,168-1); //1MHz计数频率  单脉冲+重复计数模式  
	Angsens_Init(); 			//????????
	while(1) 
	{		 	  
//		Locate_Rle(100,500,CW);
//		if(USART_RX_STA&0x8000)//接收完成
//		{
//			RxData=arrtoi(USART_RX_BUF);
//			printf("RxData:%ld",RxData);	
//			Locate_Rle(RxData,500,dir);//
//			USART_RX_STA=0;
//			memset(USART_RX_BUF, 0, sizeof USART_RX_BUF); 
//			RxData=0;
//			
//		}
//		while(!(adcx>=2840&&adcx<=2850))
//		{
			adcx=Angsens_Get_Val();	
//			pul=Incremental_PI (adcx,2850);
//			if(pul<0)
//			{
//				dir=CCW;
//				pul = -pul;
//			}
//			else
//				dir=CW;
//			Locate_Rle(pul,500,dir);
			printf("adc:%d\r\n",adcx);
//		}
//		keyval=KEY_Scan(0);
//		if(keyval==WKUP_PRES)
//		{
//				
//			printf("adc:%d\r\n",adcx);
//			for(j=0;j<=3;j++)
//			{
//				printf("%d",USART_RX_BUF[j]);
//			}
//		}else if(keyval==KEY0_PRES)
//		{
//						
//			GPIO_ResetBits(GPIOE,GPIO_Pin_6);//PE6输出低 使能输出  DRIVER_OE
//		}//else if(keyval==KEY1_PRES)
////		{
////			Locate_Rle(400,500,CCW);//按下KEY1，以500Hz的频率 逆时针发400脉冲
////		}			
////		delay_ms(10);
////		i++;
////		if(i==50)	
////		{	
////			i=0;
////			LED1=!LED1;
//		//}			
//	}
	}
}
