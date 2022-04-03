
#ifndef _LCD_INT_H_ 
#define _LCD_INT_H_

#define  CMD    SHIFT_R
#define  LCD_DATA   DIO_U8_PORT_A
#define  LCD_CONTROL   DIO_U8_PORT_B
#define  RS_PIN        DIO_U8_PIN0
#define  RW_PIN        DIO_U8_PIN1
#define  EN_PIN        DIO_U8_PIN4
#define LCD_CLEAR_SCREEN  0X01
ErrorStatus    LCD_enuInit(void);
ErrorStatus    LCD_enuSendCMD(u8 copy_u8CMD);
ErrorStatus    LCD_enuSendData(u8 copy_u8Data);
void LCD_vidWriteString (u8* Au8_String);
void Go_to_PosWriteStr(u8 positin,u8 line,u8* Au8_String);
void lcd_gotoxy(u8 x,u8 y);
void lcd_gotox_y( u8 line,u8 position);
void LCD_voidGoToPosition (u8 Copy_u8Row , u8 Copy_u8Col);
void SinwaveWriteStr(u8* Au8_String);
void LCD_WriteshiftString (u8* Au8_String);
void tostring(char str[], u32 num);
void LCD_Num(int num);
#endif    
