#include<reg51.h>
sbit SERVO_PIN=P2^0;

void msdelay(unsigned int time)
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}

void servo_delay(int times)
{
    int m;
    for(m=0;m<times;m++)
    {
        TH0=0xFF;
        TL0=0xD2;
        TR0=1;
        while(TF0==0);
        TF0=0;
        TR0=0;
    }
}

void main()
{
    int n;
    TMOD=0x01;                // Selecting Timer 0, Mode 1
    SERVO_PIN=0;
    while(1)
    {
        for(n=13;n<30;n=n+2)
        {
            SERVO_PIN=1;
            servo_delay(n);     
            SERVO_PIN=0;
            servo_delay(260);
            msdelay(200);
        }
    }
}