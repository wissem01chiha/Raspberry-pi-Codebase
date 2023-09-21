#include <wiringPi.h>
#include <wiringShift.h>
int dataPin = 23; //define three pins
int latchPin = 24;
int clockPin = 25;
int a[8]={
1,2,4,8,16,32,64,128};   //���幦�����飬��������Ϊ����ܵö���
int b[8]={
254,253,251,247,239,223,191,127};   //���幦�����飬��������Ϊ����ܵö���
int c[16]={
1,3,7,15,31,63,127,255,1,2,4,8,16,32,64,128};   //���幦�����飬��������Ϊ����ܵö���
int d[16]={
254,253,251,247,239,223,191,127,1,3,7,15,31,63,127,255};   //���幦�����飬��������Ϊ����ܵö���
int x;
int y;
int z;
int main()
{
  wiringPiSetup();
 
  {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //three pins as output
  }
  
  while(1)
  { 
   for(x=0; x<8 ;x++ )                        //˳������ѭ��
   for(y=0; y<8 ;y++ )                        //˳������ѭ��
   {
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,a[x]);     //��ʾ����a[x]
    shiftOut(dataPin,clockPin,MSBFIRST,b[y]);     //��ʾ����b[y]
    digitalWrite(latchPin,HIGH);
    delay(80);
   }
    for(z=0; z<16 ;z++ )                        //˳������ѭ��
  {
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,c[z]);     //��ʾ����c[z]
    shiftOut(dataPin,clockPin,MSBFIRST,d[z]);     //��ʾ����d[z]
    digitalWrite(latchPin,HIGH);
    delay(80);
  }  
 }	
}

