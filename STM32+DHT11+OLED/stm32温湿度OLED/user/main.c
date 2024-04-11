#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "dht11.h"
#include "FMQ.h"
#include "Serial.h"



//float leng;
u8 temp,humi;

int main(void)
{
	 uint32_t bufe[5];
	 OLED_Init();
	 DHT11_Init();
	 mfq_Init();
	 Serial_Init();
	
	 //OLED_ShowString(1,1,"Wendu:");
	 //OLED_ShowString(2,1,"Shidu:");
	OLED_ShowChinese(0, 0, "温度：");
	OLED_ShowChinese(94, 0, "℃");
	OLED_ShowChinese(0, 16, "湿度：");
	OLED_ShowString(94,16,"RH",OLED_8X16);
	/*OLED_ShowChinese(0, 32, "光照强度：");
	OLED_ShowString(112,32,"LX",OLED_8X16);
	OLED_ShowChinese(0, 47, "烟雾浓度：");
	OLED_ShowString(112,47,"%",OLED_8X16);*/
	
	OLED_Update();

	while(1)
	{
		
		DHT11_Read_Data(&temp,&humi);
	  bufe[0]=temp;
		bufe[1]=humi;
	
		/*bufe[2]=45;
		length = leng*100;
		OLED_ShowNum(2,4,length/1000,1);//bai
		OLED_ShowNum(2,5,length%1000/100,1);//shi
		OLED_ShowString(2,6,":");
		OLED_ShowNum(2,7,length%100/10,1);//
		OLED_ShowNum(2,8,length%10/1,1);
		
		OLED_ShowNum(1,8,bufe[0],2);
		OLED_ShowString(1,11,"C");
		OLED_ShowNum(2,8,bufe[1],2);
		OLED_ShowString(2,11,"%");*/
		
		OLED_ShowNum(47,0,bufe[0],2,OLED_8X16);
		OLED_ShowNum(47,16,bufe[1],2,OLED_8X16);
		OLED_Update();
		fmq(temp,humi);

		 printf("temp=%d  , humi=%d RH\r\n",temp,humi);

	}
}
