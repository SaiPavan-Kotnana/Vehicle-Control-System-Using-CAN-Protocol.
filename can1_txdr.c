#include<lpc21xx.h>

#include "header.h"

void can1_init(void)

{

PINSEL1|=0X14000;

VPBDIV=1;

C2MOD=1;

C2BTR=0x001C001D;

AFMR=2;

C2MOD=0;

}


#define TCS ((C2GSR>>3)&1)

void can1_tx(CAN1 v)

{

C2TID1=v.id;

C2TFI1=(v.dlc<<16);

if((v.rtr)==0)

{

C2TDA1=v.byteA;

C2TDB1=v.byteB;

}

C2CMR=0x21;

while(TCS==0);

}

