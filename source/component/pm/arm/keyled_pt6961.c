
#include "base.h"
#include "gpio.h"
#include "keyled.h"

#ifdef KEYLED_PT6961

/************************************************************************* 
						2.3 keyled_pt6961 module
*************************************************************************/
/* 1 cfg param */
#define PT6961_CLK     (2)    /*CLK signal pin connected with GPIO5_2*/ /*CNcomment:时钟信号管脚与GPIO5_2相连*/
#define PT6961_STB     (3)    /*STB signal pin connected with GPIO5_3*/ /*CNcomment:片选信号管脚与GPIO5_3相连*/
#define PT6961_DIN     (4)    /*DIN signal pin connected with GPIO5_4*/ /*CNcomment:数据输出信号管脚与GPIO5_4相连*/
#define PT6961_DOUT    (5)    /*DOUT signal pin connected with GPIO5_5*/ /*CNcomment:数据输入信号管脚与GPIO5_5相连*/

/*pt6961 resource*/
#define PT6961_DISPLAY_REG_NUM  (10)
#define PT6961_KEY_REG_NUM      (2)

/*pt6961 command*/
#define CMD1_DISP_MODE_0   (0x0) /*Four LEDs*/ /*CNcomment:4位数码管*/
#define CMD1_LED_ADDR_BASE (0xc0)
#define CMD1_LED_WRITE_INC (0x40)
#define CMD1_KEY_READ      (0x42)
#define CMD1_DIP_ON        (0x8a)
#define CMD1_DIP_OFF       (0x80)

#define KEY_MACRO_NO 	(0xff)

/*variable*/
HI_U8 disp_reg[PT6961_DISPLAY_REG_NUM] = {0};
HI_U8 key_reg[PT6961_KEY_REG_NUM] = {0};
HI_U8 ledDisDot_pt6961[10] = {0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};
HI_U8 ledDisCode_pt6961[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

#define udelay_pt6961(x)  do{ \
	HI_U8 s; \
	for(s = 0; s < x; s++);\
}while(0)

void keyled_pt6961_tx_byte(HI_U8 val)
{
	HI_U8 i = 0;
	HI_U8 tmp = val;
	
	for (i = 0; i < 8; i++)
	{
		gpio5_write_bit(PT6961_CLK, 0);
		
		//LSB first, MSB later
		gpio5_write_bit(PT6961_DIN, tmp & 0x1);
		tmp = (tmp >> 1);
		
		gpio5_write_bit(PT6961_CLK, 1);		
	}
	
	return;
}

void keyled_pt6961_write(HI_U8 val)
{   
	/*send single commod byte*/ /*CNcomment:发送单个命令字节*/  
	gpio5_write_bit(PT6961_STB, 0);
	keyled_pt6961_tx_byte(val);
	gpio5_write_bit(PT6961_STB, 1);
	
	return ;
}

void keyled_pt6961_led_update(void)
{
	HI_U8 i = 0;

	/*command 1:set display mode */ /*CNcomment: command 1:设置显示模式 */
	keyled_pt6961_write(CMD1_DISP_MODE_0);
	
	/*command 2:set write commod  */ /*CNcomment: command 2:设置写命令*/
	keyled_pt6961_write(CMD1_LED_WRITE_INC);

	/*command 3:set the initialization address and send data */
	/*CNcomment: command 3:设置起始地址并发送数据*/
	gpio5_write_bit(PT6961_STB, 0);
	keyled_pt6961_tx_byte(CMD1_LED_ADDR_BASE);
	
	for (i = 0; i < PT6961_DISPLAY_REG_NUM; i++)
	{
		keyled_pt6961_tx_byte(disp_reg[i]);
	}
	gpio5_write_bit(PT6961_STB, 1);
	
	//command 4 :open LED display control
	keyled_pt6961_write(CMD1_DIP_ON);	

	return;
}

void keyled_pt6961_pin_config(void)
{ 
	/*Config the pin reuse, it will be effective before enter SLOW mode.*/
    /*CNcomment: 管脚复用配置，进入到SLOW模式前有效*/
	gpio5_bit_reuse(PT6961_STB);
	gpio5_bit_reuse(PT6961_CLK);
	gpio5_bit_reuse(PT6961_DIN);
	gpio5_bit_reuse(PT6961_DOUT);

	return;
}

void keyled_pt6961_gpio_dirset(void)
{    
    /*Set gpio direction*/ /*CNcomment:gpio方向设定*/
	gpio5_dirset_bit(PT6961_STB, 0);
	gpio5_dirset_bit(PT6961_CLK, 0);
	gpio5_dirset_bit(PT6961_DIN, 0);
	gpio5_dirset_bit(PT6961_DOUT, 1);

    return;
}

void no_display_usr()
{
	disp_reg[0] = 0x0;
	disp_reg[2] = 0x0;
	disp_reg[4] = 0x0;
	disp_reg[6] = 0x0;

	keyled_pt6961_led_update();

	return;
}

void keyled_reset_usr(void)
{	
	keyled_pt6961_pin_config();
	keyled_pt6961_gpio_dirset();
	no_display_usr();
	
	return;
}

void keyled_disable_usr(void)
{		
	no_display_usr();
	
	return;
}

void pt6961_rx_byte(HI_U8 *u8data)
{
	HI_U8 u8val = 0;
	HI_U8 j = 0;
	HI_U8 tmp = 0;

	gpio5_dirset_bit(PT6961_DIN, 1);
	gpio5_write_bit(PT6961_DIN, 1); 
	
	for (j = 0; j < 8; j++)
	{
		gpio5_write_bit(PT6961_CLK, 0);   
		gpio5_write_bit(PT6961_CLK, 1);   

		gpio5_read_bit(PT6961_DOUT, &tmp);
		if (tmp)
		{
		    /*LSB first, MSB later */ /*CNcomment:先接收低位，再接收高位 */
			u8val |= 0x80; 
		}

		/*Last Bit received, bits need not to be moved*/
		/*CNcomment:当接收最高位后，不需要再移位了*/
		if (j < 7)
		{
			u8val >>= 1;  
		}
	}

	/*Save the received data*/ /*CNcomment:保存接收数据*/
	*u8data = u8val; 
	
	gpio5_dirset_bit(PT6961_DIN, 0);
		
	return;
}

/*Get the value of keypad register*/ /*CNcomment:按键寄存器获取函数 */
void  pt6961_read()
{	  
	HI_U8 i = 0;
	
	gpio5_write_bit(PT6961_STB, 1);
	gpio5_write_bit(PT6961_CLK, 1);
	gpio5_write_bit(PT6961_STB, 0);
	keyled_pt6961_tx_byte(CMD1_KEY_READ);
	
	udelay_pt6961(2); //twait
	
	for (i = 0; i < 2; i++)
	{
		pt6961_rx_byte(&key_reg[i]);
	}
	gpio5_write_bit(PT6961_STB, 1);

	return;
}

void keyled_isr_usr()
{
	HI_U8 i,j;
	HI_U8 key;

	pt6961_read();
	
	key = 0xff;
	for (i = 0; i < 2; i++) 
	{
		if (0 == (key_reg[i] & 0x3f))
	    {
	    	continue;
		}		 
		for (j = 0; j < 6; j++)
	    {
	  		if (key_reg[i] & (0x1 << j))
			{
				key = i * 6 + j;
				goto check;
			}
		}
	}

check:
	if (key == klPmocVal)
	{
		pmocType = 1;
		pmocflag = 1;
	}
	
	return;
}

void timer_display_usr() 
{
	HI_U8 index = 0;
	
	index = time_hour / 10;
	disp_reg[0] = ledDisCode_pt6961[index];
	
	index = time_hour % 10;
	if (time_dot)
	{
		disp_reg[2] = ledDisDot_pt6961[index];
	}
	else
	{
		disp_reg[2] = ledDisCode_pt6961[index];
	}
	
	index = time_minute / 10;
	disp_reg[4] = ledDisCode_pt6961[index];
	
	index = time_minute % 10;
	disp_reg[6] = ledDisCode_pt6961[index];

	keyled_pt6961_led_update();
	
	return ;
}

void chan_display_usr()
{
	HI_U8 index;
  
	index = (channum >> 24) & 0xff;  
	disp_reg[0] = ledDisCode_pt6961[index];
	
	index = (channum >> 16) & 0xff;
	disp_reg[2] = ledDisCode_pt6961[index];

	index = (channum >> 8) & 0xff;
	disp_reg[4] = ledDisCode_pt6961[index];

	index = (channum) & 0xff;
	disp_reg[6] = ledDisCode_pt6961[index];

	keyled_pt6961_led_update();

	return;
}

void dbg_display_usr(HI_U16 val)
{
	HI_U16 tmp;
	HI_U16 index;

	if(val > 9999)
	{
		return;
	}

	tmp = val / 10;  
	index = (val - tmp * 10); 
	disp_reg[0] = ledDisCode_pt6961[index];

	val = tmp;
	tmp = val / 10;  
	index = (val - tmp * 10); 
	disp_reg[2] = ledDisCode_pt6961[index];

	val = tmp;
	tmp = val / 10;  
	index = (val - tmp * 10); 
	disp_reg[4] = ledDisCode_pt6961[index];

	val = tmp;
	tmp = val / 10;  
	index = (val - tmp * 10); 
	disp_reg[6] = ledDisCode_pt6961[index];

	keyled_pt6961_led_update();
	
	return;
}
#endif

