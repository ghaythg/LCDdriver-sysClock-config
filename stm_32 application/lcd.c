/**   we use the module PCF8574 to connect lcd with i2c periph ****************/
/**
  ******************************************************************************
  * @file    LCD DRIVER /LCD.c
  * @author  AMRI GHAYTH
  * @mail    amrighayth74@gmail.com
  * @Tel     (+216)94.082.468
  * @date    19-06-2019
  *****************************************************************************/
 #include "lcd.h"
 #include <stdint.h>
#define SLAVE_ADRESS_LCD 0x4E ;
void send_cmmnd (char cmmnd )
{  
  char Data_h , Data_l ;
  uint8_t Data_t [4];
  Data_h = (cmmnd & 0x0f) ;
  Data_l =((cmmnd<<4)& 0x0f);
  Data_t [0] = Data_h|0x0C ; // en=1 rs=0//  enable without ligyth on //
  Data_t [1] = Data_h|0x08 ; //en=0 rs=0//  disable light off //
  Data_t [2] = Data_l|0x0C ;  // en=1 rs=0//    enable without ligyth on //
  Data_t [3] = Data_l|0x08 ; // en=0 rs=0//  disable light off //
  
}
void send_data (char data) 
{
char Data_h , Data_l ;
  uint8_t Data_t [4];
  Data_h = (data & 0x0f) ;
  Data_l =((data<<4)& 0x0f);
  Data_t [0] = Data_h|0x05 ; // en=1 rs=0//  ligyth on / enable /whrite operation //
  Data_t [1] = Data_h|0x04 ; //en=0 rs=0//  disable light off //
  Data_t [2] = Data_l|0x05 ;  // en=1 rs=0//    enable without ligyth on //
  Data_t [3] = Data_l|0x04 ; // only rs //

}
void lcd_int (void)
{
HAL_Delay(50);
send_cmmnd (0x30);
HAL_Delay(5);
send_cmmnd (0x30);
HAL_Delay(1);
send_cmmnd (0x30);
HAL_Delay(10);
send_cmmnd (0x30);
HAL_Delay(10);
send_cmmnd (0x28);
HAL_Delay(1);
send_cmmnd (0x08);
HAL_Delay(1);
send_cmmnd (0x01);
HAL_Delay(1);
send_cmmnd (0x06);
HAL_Delay(1);
send_cmmnd (0x0C);
}
void send_string(char *str) 
{
while(*str) 
send_data(*str++);

}
void lcd_clear (void)
{

send_cmmnd(0x80);
for (int i=0; i<70;i++)
{send_data('   ');}

}

void lcd_conf_curser (int hc ,int vc)
{
switch (hc)
{
    case 0 :
    vc |= 0x08 ;
    break;
    case 1 :
    vc|= 0xC0;
    break ;
    send_cmmnd(col);

}
send_cmmnd(col);


}