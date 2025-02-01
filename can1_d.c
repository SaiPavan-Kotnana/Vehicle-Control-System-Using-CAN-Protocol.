
#include "header1.h"
u32 *ptr=(u32*)0xE0038000;
void can_init(void)
{

PINSEL1|=0X14000;

VPBDIV=1;

C2MOD=1;
ptr[0]=0x41204121;
ptr[1]=0x4122;
SFF_sa=0;

	SFF_GRP_sa=0x8;

	EFF_sa=EFF_GRP_sa=0x8;

	ENDofTable=0x08;



C2BTR=0X001C001D;

AFMR=0;

C2MOD=0;

}

extern CAN1 r;

extern int flag;

void can_rx_handler(void)__irq

{

r.id=C2RID;

r.dlc=(C2RFS>>16)&0x0f;

r.rtr=(C2RFS>>30)&1;

if(r.rtr==0)

{

r.byteA=C2RDA;

r.byteB=C2RDB;

flag=1;

}

C2CMR=1<<2;

VICVectAddr=0;

}


void config_vic_for_can(void)

{

VICIntSelect=0;

VICVectAddr0=(unsigned int)can_rx_handler;

VICVectCntl0=27|(1<<5);

VICIntEnable=(1<<27);

C2IER=1;

}

