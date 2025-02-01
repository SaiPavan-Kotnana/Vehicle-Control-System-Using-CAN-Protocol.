#include<lpc21xx.h>

#include"header.h"

CAN1 v;
extern int flag,flag1,flag2;

int main()

{

int HF=0,RF=0,LF=0;

can1_init();
config_vic_for_eint0();
config_eint0();

v.dlc=1;

v.rtr=0;

while(1)

    {

//    if(HL==0)

//    {

//           while(HL==0);
if(flag1)
{
flag1=0;

           HF^=1;

           v.id=0x120;

           if(v.rtr==0)

           {

           if(HF)

           v.byteA=0x10;

           else

           v.byteA=0x11;

           can1_tx(v);

           }

	}

//    if(LI==0)

//    {

//           while(LI==0);
if(flag2)
{
flag2=0;

           LF^=1;

           v.id=0x121;

           if(v.rtr==0)

           {

           if(LF)

           v.byteA=0x12;

           else

           v.byteA=0x13;

           can1_tx(v);

           }

	}

//    if(RI==0)

//     {

//           while(RI==0);
if(flag)
{
flag=0;

           RF^=1;

           v.id=0x122;

           if(v.rtr==0)

           {

           if(RF)

           v.byteA=0x14;

          else

          v.byteA=0x15;

           can1_tx(v);

          }

     }

}

}


