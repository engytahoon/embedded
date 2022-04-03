#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
#include "DELAY.h"
#include"DIO_interface.h"
#include "lcd_inter.h"
#include "lcd_priv.h"
#include "lcd_conf.h"

#define LCD_8MODE  _8_BITS
ErrorStatus    LCD_enuInit(void)
{
	ErrorStatus error =ES_NOK;
	Delay_ms(15);

#if  LCD_8MODE == _8_BITS

	LCD_enuSendCMD(0x80);
	Delay_ms(15);

	LCD_enuSendCMD(0x38);

	Delay_ms(1);

	LCD_enuSendCMD(0x0C);

	Delay_ms(1);

	LCD_enuSendCMD(0x01);

	Delay_ms(2);

	LCD_enuSendCMD(0x06);

	Delay_ms(1);
	LCD_enuSendCMD(0x14);

	error = ES_OK;

#elif  LCD_4MODE == _4_BITS

	error = ES_OK;
#else
#error  "Wrong LCD MODE"
#endif
	return error;
}
ErrorStatus    LCD_enuSendCMD(u8 copy_u8CMD)
{
	ErrorStatus error= ES_NOK;

	DIO_enumSetPinValue(LCD_CONTROL,RS_PIN,DIO_U8_LOW);
	DIO_enumSetPinValue(LCD_CONTROL,RW_PIN,DIO_U8_LOW);

	DIO_enumSetPortValue(LCD_DATA,copy_u8CMD);

	DIO_enumSetPinValue(LCD_CONTROL,EN_PIN,DIO_U8_HIGH);
	Delay_ms(2);
	DIO_enumSetPinValue(LCD_CONTROL,EN_PIN,DIO_U8_LOW);
	error=ES_OK;
	//_delay_ms(100);
	return error;

}
ErrorStatus    LCD_enuSendData(u8 copy_u8Data)
{
	ErrorStatus error= ES_NOK;
	DIO_enumSetPinValue(LCD_CONTROL,RS_PIN,DIO_U8_HIGH);
	DIO_enumSetPinValue(LCD_CONTROL,RW_PIN,DIO_U8_LOW);

	DIO_enumSetPortValue(LCD_DATA,copy_u8Data);

	DIO_enumSetPinValue(LCD_CONTROL,EN_PIN,DIO_U8_HIGH);
	Delay_ms(2);
	DIO_enumSetPinValue(LCD_CONTROL,EN_PIN,DIO_U8_LOW);
	error=ES_OK;
	//_delay_ms(100);
	return error;


}
void LCD_vidWriteString (u8* Au8_String)
{
	u8 index = 0;
	while (Au8_String[index] != '\0')
	{
		//if(Au8_String[index]<'0')
		//{
		//continue;
		//}
		LCD_enuSendData (Au8_String[index]);
		index++;

	}
}
/*************************************************************************************/
/*      Descriotion       : This Function  Used To Write string in position          */
/*      Inputs            : Position,Line and String                                 */
/*      outputs           :  Void                                                    */
/*************************************************************************************/
void Go_to_PosWriteStr(u8 position,u8 line,u8* Au8_String)
{
	u8 index=0;// counter of count num of char in the string
	if (line== 0&&position<=16)
	{
		LCD_enuSendCMD (0x80+position);
		while (Au8_String[index] != '\0')
		{
			LCD_enuSendData (Au8_String[index]);
			index++;
			Delay_ms(5);
		}
	}
	else if (line==1&&position<=15)
	{
		LCD_enuSendCMD (0xc0+position);
		while (Au8_String[index] != '\0')
		{
			LCD_enuSendData (Au8_String[index]);
			index++;
			Delay_ms(5);
		}
	}
}




/*void lcd_clear_screen()
{
	LCD_enuSendCMD(LCD_CLEAR_SCREEN);
	}*/
void lcd_gotox_y( u8 line,u8 position)
{
	if(line==0)
	{
		if(position<=15&&position>=0)

			LCD_enuSendCMD (0x80+position);

	}
	else if(line==1)
	{
		if(position<=15&&position>=0)

			LCD_enuSendCMD (0xc0+position);

	}
}
void LCD_voidGoToPosition (u8 Copy_u8Row , u8 Copy_u8Col)
{
	u8 Local_u8RowLocation [] = {0x80 , 0xc0};

	LCD_enuSendCMD (Local_u8RowLocation [Copy_u8Row-1]+(Copy_u8Col-1));
}
/*void SinwaveWriteStr(u8* Au8_String) // passing line num & position of pixel>>position (value el user byd5alha)
{
	u8 index = 0; // counter of count num of char in the string

		while (Au8_String[index] )
		{
			LCD_enuSendCMD(0x80 + index);
			while (Au8_String[index] !=' ' ) {

				LCD_enuSendData(Au8_String[index]);
				index++;
				_delay_ms(5);
			}
			LCD_enuSendCMD(0xc0 + index); //go to new line starting with the end of the previous line
			index++; //declaring space from index and compare index to the max size we can write in 2 rows
			while (Au8_String[index] != ' ') {
				LCD_enuSendData(Au8_String[index]);
				index++;
				//_delay_ms(5);
			}
			index++;
		}


}*/
/*************************************************************************************/
/*      Descriotion       : This Function  Used To Write string in Sine Wave         */
/*      Inputs            :  String                                                  */
/*      outputs           :  Void                                                    */
/*************************************************************************************/
void SinwaveWriteStr(u8* Au8_String)
{
	u8 index = 0,flag=0; // counter of count num of char in the string

	while (Au8_String[index] )
	{
		if(!flag){
			LCD_enuSendCMD(0x80 + index);
			flag=1;
		}
		else if (flag){
			LCD_enuSendCMD(0xc0 + index);
			flag=0;

		}
		while (Au8_String[index] !=' ' ) {

			LCD_enuSendData(Au8_String[index]);
			index++;
			Delay_ms(5);
		}
		index++; //declaring space from index and compare index to the max size we can write in 2 rows
	}


}
void tostring(char str[], u32 num)
{
    u32 i, rem, len = 0, n;

    n = num;
    if(num==0)
    {str[0]='0';
    str[1]='\0';
     return ; }
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void LCD_Num(int num)
{
	u8 arr[16]={0};
	tostring(arr,num);
	LCD_vidWriteString(arr);

//   int buff[16]; /* String to hold the ascii result */
//   itoa(buff ,num,10); /* 10 for decimal */
//   LCD_vidWriteString(buff);

}

