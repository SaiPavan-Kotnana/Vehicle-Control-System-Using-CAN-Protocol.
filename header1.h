#include<lpc21xx.h>
typedef unsigned int  u32;
typedef struct CAN_MSG
{
unsigned int id,byteA,byteB;
unsigned char rtr,dlc;
}CAN1;

extern void config_vic_for_can(void);
extern void can_init(void);
extern void delay_ms(unsigned int ms);
