#include<reg51.h>

#define GPIO_LED P0

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

//RAM,ROM
unsigned char code DIG_CODE[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Delay(unsigned int a)
{
	unsigned char b;
	for(;a>0;a--)
	{
		for(b=110;b>0;b--);
	}
}

void main(void)
{
		int i;
    LSA = 0;
    LSB = 0;
    LSC = 0;
		
		GPIO_LED = 0;
		
    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            LSA = i & 0x01;
            LSB = (i >> 1) & 0x01;
            LSC = (i >> 2) & 0x01;

            GPIO_LED = DIG_CODE[i];
            Delay(1);
        }
    }	
}