extern void delay_ms(unsigned int ms);

extern void delay_sec(unsigned int sec);


extern void uart0_tx(unsigned char data);

extern void uart0_init(unsigned  int baud);

extern void uart0_tx_string(char *ptr);

extern unsigned char uart0_rx(void);

extern void uart0_tx_float(float f);

extern void uart0_tx_integer(int n);




extern void lcd_data(unsigned char data);

extern void lcd_cmd(unsigned char cmd);

extern void lcd_init(void);

extern void lcd_string(char *ptr);

extern void lcd_integer(int num);

extern void  lcd_cgram(void);	


typedef unsigned int u32;

typedef signed int s32;

typedef unsigned char u8;

typedef signed char s8;


extern void adc_init(void);

extern u32 adc_read(u8 ch_num);


extern void config_vic_for_eint0(void);

extern void config_eint0(void);

extern void config_vic_for_uart0(void);

extern void config_uart0_intr(void);




extern void spi0_init(void);

extern unsigned char spi0(unsigned char data);

extern unsigned int read_mcp3204(unsigned char);


extern u8 i2c_byte_read_frame(u8 sa,u8 mr);

extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);

extern void i2c_init(void);


extern void config_eint0(void);

extern void config_vic_for_eint0(void);



typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u32 byteB;

	u8 rtr;

	u8 dlc;

}CAN1;


extern void can1_init(void);

extern void can1_tx(CAN1 v);

extern void can1_rx(CAN1 *ptr);


