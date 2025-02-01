#include<lpc21xx.h>
#include"header.h"

//int c1,c2;


int flag,flag1,flag2;

//u8 cmd;

void EINT0_handler(void) __irq{

flag=flag^1;

EXTINT|=1;

VICVectAddr=0;

}


void EINT1_handler(void) __irq
{

flag1=flag1^1;


EXTINT|=2;

VICVectAddr=0;

}


void EINT2_handler(void) __irq{

flag2=flag2^1;

EXTINT|=4;

VICVectAddr=0;

}




void config_vic_for_eint0(void)	

{

VICIntSelect=0;

VICVectCntl0=14|(1<<5);//p0.16

VICVectCntl1=15|(1<<5);//p0.14

VICVectCntl2=16|(1<<5);//p0.15


VICVectAddr0=(int)EINT0_handler;

VICVectAddr1=(int)EINT1_handler;

VICVectAddr2=(int)EINT2_handler;


VICIntEnable|=(1<<14)|(1<<15)|(1<<16);

}

void config_eint0(void)

{

PINSEL0|=0XA0000000;

PINSEL1|=1;

EXTMODE|=(1<<0)|(1<<1)|(1<<2);

EXTPOLAR=0;

}

