#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define Address 0x48         //pcf8591������ַ
#define BASE 64
#define A0 BASE+0           //A0�˿������ַ
#define A1 BASE+1           //A1�˿������ַ
#define A2 BASE+2           //A2�˿������ַ
#define A3 BASE+3           //A3�˿������ַ

int main(void)
{
    unsigned char value;
	wiringPiSetup();
	pcf8591Setup(BASE,Address);        //����pcf8591
	
	while(1)
	{
               value=analogRead(A0);     // ��ȡA0�˿ڵ�ֵ          
               printf("A0:%d\n",value);  // �ն˴�ӡ��A0�˿ڵ�ֵ
               delay(100);	
	}
}
