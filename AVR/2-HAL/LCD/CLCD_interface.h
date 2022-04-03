#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H




void CLCD_voidInit();

void CLCD_voidSendCmnd(u8 Copy_u8Cmnd);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidWriteString(u8 *Copy_pu8Data);

void CLCD_GoToXY(u8 CopyRowNb , u8 CopyColNb);

void LCD_Clear_Display(void);
void LCD_Num(u16 num);

void LCD_Hamoksha (char num);

void LCD_Game1(void);
void LCD_Game2(void);

#endif
