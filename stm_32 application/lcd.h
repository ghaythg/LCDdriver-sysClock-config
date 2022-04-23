/**   we use the module PCF8574 to connect lcd with i2c periph ****************/
/**
  ******************************************************************************
  * @file    LCD DRIVER /LCD.h 
  * @author  AMRI GHAYTH
  * @mail    amrighayth74@gmail.com
  * @Tel     (+216)94.082.468
  * @date    19-06-2019
  *****************************************************************************/
 //#include"stm32f1xx_hal.h"// 
void lcd_int (void) ;                                 // inicialitier lcd //
void send_cmmnd (char cmmnd );                        // to send command to lcd //
void send_data (char data) ;                          // to send data //
void send_string(char *str) ;                          //to send string to lcd // 
void lcd_conf_curser (int hc ,int vc);      // put the curser vertical (0/1) or horizental (0/15)
void lcd_clear (void);



