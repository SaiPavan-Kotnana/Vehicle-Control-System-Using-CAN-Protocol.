#include <LPC21xx.H>
#include"header1.h"

int flag;

CAN1 r;

#define Hl (1<<17)

#define LI (1<<18)

#define RI (1<<19)

int LF,RF;
int main()

{
IODIR0|=7<<17;

IOSET0=7<<17;

//PINSEL0|=0;

can_init();

config_vic_for_can();


while(1)

{

if(flag==1)

{


switch(r.byteA&0XFF)

{

case 0x10:IOCLR0|=Hl;break;

case 0x11:IOSET0|=Hl;break;

case 0x12:LF=1;RF=0; IOSET0=RI;break;

case 0x13:LF=0; IOSET0=LI;break;

case 0x14:RF=1;LF=0;IOSET0=LI;break;

case 0x15:RF=0; IOSET0=RI;break;

}
flag=0;
}

 


if(RF==1){
IOCLR0|=RI;

delay_ms(50);

IOSET0|=RI;

delay_ms(50);

}

 if(LF==1){
IOCLR0|=LI;

delay_ms(50);

IOSET0|=LI;

delay_ms(50);

 

}

}

}

