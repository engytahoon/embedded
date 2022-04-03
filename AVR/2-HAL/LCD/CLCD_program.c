#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"


void CLCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
	/* RS = 0 */
	DIO_EnuSetPinValue (CLCD_RS_PORT , CLCD_RS_PIN , DIO_PIN_LOW);
	/* RW = 0 */
	DIO_EnuSetPinValue (CLCD_RW_PORT , CLCD_RW_PIN , DIO_PIN_LOW);

	/* write command */
#if (CLCD_MODE  == EIGHT_BIT_MODE)
	CLCD_voidSetValue(Copy_u8Cmnd);
#elif (CLCD_MODE == FOUR_BIT_MODE)
	CLCD_voidSetValue(Copy_u8Cmnd & 0xf0);
	/* Enable pulse = 1 */
	DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_HIGH);
	_delay_us(1);
	/* Enable pulse = 0 */
	DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_LOW);
	CLCD_voidSetValue((Copy_u8Cmnd<<4) & 0xf0);

#endif
	/* Enable pulse = 1 */
	DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_HIGH);
	_delay_us(1);
	/* Enable pulse = 0 */
	DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_LOW);
}

void LCD_Clear_Display(void)
{
	CLCD_voidSendCmnd(0x01);
}
void CLCD_voidInit()
{
	DIO_EnuSetPinDirection(CLCD_RS_PORT,CLCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_EnuSetPinDirection(CLCD_RW_PORT,CLCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_EnuSetPinDirection(CLCD_E_PORT,CLCD_E_PIN,DIO_PIN_OUTPUT);
	DIO_EnuSetPortDirection(CLCD_DATA_PORT,DIO_PORT_OUTPUT);

#if (CLCD_MODE == EIGHT_BIT_MODE)
	{
		_delay_ms(40);
		CLCD_voidSendCmnd(0x38);    //function set
		_delay_us(40);
	}
#elif (CLCD_MODE == FOUR_BIT_MODE)
	{
		_delay_ms(40);
		CLCD_voidSendCmnd(0x33);    //function set
		_delay_ms(2);
		CLCD_voidSendCmnd(0x32);    //function set
		_delay_ms(2);
		CLCD_voidSendCmnd(0x28);    //function set
		_delay_ms(2);
	}
#endif
	CLCD_voidSendCmnd(0x0c);    //display on/off control
	_delay_us(40);
	CLCD_voidSendCmnd(0x01);    //display clear
	_delay_ms(2);
	CLCD_voidSendCmnd(0x06);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* RS = 1 */
	DIO_EnuSetPinValue (CLCD_RS_PORT , CLCD_RS_PIN , DIO_PIN_HIGH);
	/* RW = 0 */
	DIO_EnuSetPinValue (CLCD_RW_PORT , CLCD_RW_PIN , DIO_PIN_LOW);

	/* write Data */
#if (CLCD_MODE == EIGHT_BIT_MODE)
	{
		CLCD_voidSetValue(Copy_u8Data);
	}
#elif
	{
		CLCD_voidSetValue(Copy_u8Data & 0xf0);
		_delay_us(100);
		/* Enable pulse = 1 */
		DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_HIGH);
		_delay_us(1);
		/* Enable pulse = 0 */
		DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_LOW);
		_delay_us(1);
		CLCD_voidSetValue(Copy_u8Data << 4);
	}
#endif
	/* Enable pulse = 1 */
	DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_HIGH);
	_delay_us(1);
	/* Enable pulse = 0 */
	DIO_EnuSetPinValue (CLCD_E_PORT , CLCD_E_PIN , DIO_PIN_LOW);

}

static void CLCD_voidSetValue(u8 Copy_u8Value)
{
	if (CLCD_MODE == EIGHT_BIT_MODE)
	{
		DIO_EnuSetPinValue (CLCD_D0_PORT , CLCD_D0_PIN , GET_BIT(Copy_u8Value , 0));
		DIO_EnuSetPinValue (CLCD_D1_PORT , CLCD_D1_PIN , GET_BIT(Copy_u8Value , 1));
		DIO_EnuSetPinValue (CLCD_D2_PORT , CLCD_D2_PIN , GET_BIT(Copy_u8Value , 2));
		DIO_EnuSetPinValue (CLCD_D3_PORT , CLCD_D3_PIN , GET_BIT(Copy_u8Value , 3));
		DIO_EnuSetPinValue (CLCD_D4_PORT , CLCD_D4_PIN , GET_BIT(Copy_u8Value , 4));
		DIO_EnuSetPinValue (CLCD_D5_PORT , CLCD_D5_PIN , GET_BIT(Copy_u8Value , 5));
		DIO_EnuSetPinValue (CLCD_D6_PORT , CLCD_D6_PIN , GET_BIT(Copy_u8Value , 6));
		DIO_EnuSetPinValue (CLCD_D7_PORT , CLCD_D7_PIN , GET_BIT(Copy_u8Value , 7));
	}
	else
	{
		DIO_EnuSetPinValue (CLCD_D4_PORT , CLCD_D4_PIN , GET_BIT(Copy_u8Value , 4));
		DIO_EnuSetPinValue (CLCD_D5_PORT , CLCD_D5_PIN , GET_BIT(Copy_u8Value , 5));
		DIO_EnuSetPinValue (CLCD_D6_PORT , CLCD_D6_PIN , GET_BIT(Copy_u8Value , 6));
		DIO_EnuSetPinValue (CLCD_D7_PORT , CLCD_D7_PIN , GET_BIT(Copy_u8Value , 7));
	}
}

void CLCD_voidWriteString(u8 *Copy_pu8Data)
{
	u8 i=0 ;
	while (Copy_pu8Data[i] != '\0')
	{
		CLCD_voidSendData(Copy_pu8Data[i]);
		i++;
	}

}
/* location of cursor */
void CLCD_GoToXY (u8 CopyRowNb , u8 CopyColNb)
{
	/*u8 arr[5]={0x80,0xc0};
	CLCD_voidSendCmnd(arr[CopyRowNb-1] + CopyColNb -1);
	_delay_us(100);*/
	switch (CopyRowNb)
	{
	case(0):
			{
		CLCD_voidSendCmnd(CopyColNb | 0x80);
		break;
			}
	case(1):
	    	{
		CLCD_voidSendCmnd((CopyColNb + 0x40)|0x80);
		break;
	    	}
	}
}
void LCD_Num(u16 num)
{
/*	u16  rev=0, rev1=0 ;
//u8 arrn[5]={0};
while(num= 0)

//for(i=0;i<4;i++)
	{
		rev = rev*10 + (num % 10);
		//arrn[i]=rev;
		num=num/10;
	}
while(rev != 0)
//for(j=4;j>0;j--)
{
	rev1=rev1 % 10;
		CLCD_voidSendData(rev1+48);
		rev=rev / 10;


}*/

u8 buff[20];
itoa(num,buff,10);
CLCD_voidWriteString(buff);

}










void LCD_Hamoksha (char num)
{
	if (num==1)
	{
		/*set CGRAM address */
		CLCD_voidSendCmnd(0b01000000);
		CLCD_voidSendData(0b00001110);
		CLCD_voidSendData(0b00001110);
		CLCD_voidSendData(0b00000100);
		CLCD_voidSendData(0b00011110);
		CLCD_voidSendData(0b00010110);
		CLCD_voidSendData(0b00000100);
		CLCD_voidSendData(0b00001010);
		CLCD_voidSendData(0b00010001);

		/*set address of DDRAM */
		CLCD_voidSendCmnd(0xc5);
		CLCD_voidSendData(0);
	}
	else if (num==0)
	{
		/*set CGRAM address */
		CLCD_voidSendCmnd(0b01000000);
		CLCD_voidSendData(0b00001110);
		CLCD_voidSendData(0b00001110);
		CLCD_voidSendData(0b00010100);
		CLCD_voidSendData(0b00011110);
		CLCD_voidSendData(0b00000110);
		CLCD_voidSendData(0b00000100);
		CLCD_voidSendData(0b00001010);
		CLCD_voidSendData(0b00010001);

		/*set address of DDRAM */
		CLCD_voidSendCmnd(0xc8);
		CLCD_voidSendData(0);
	}
	else if(num ==2)
	{
		/*set CGRAM address */
		CLCD_voidSendCmnd(0b01000000);
		CLCD_voidSendData(0b00010001);
		CLCD_voidSendData(0b00011111);
		CLCD_voidSendData(0b00011111);
		CLCD_voidSendData(0b00010101);
		CLCD_voidSendData(0b00011111);
		CLCD_voidSendData(0b00000100);
		CLCD_voidSendData(0b00001010);
		CLCD_voidSendData(0b00010001);
		/*set address of DDRAM */
		CLCD_voidSendCmnd(0xc9);
		CLCD_voidSendData(8);
		_delay_ms(200);
	}
}

void LCD_Game1(void)
{
	/*set CGRAM address */
	CLCD_voidSendCmnd(0b01000000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	CLCD_voidSendData(0b00011000);
	/*set address of DDRAM */
	CLCD_voidSendCmnd(0x80);
	CLCD_voidSendData(0);
}
void LCD_Game2(void)
{
	/*set CGRAM address */
	CLCD_voidSendCmnd(0b01000000);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	CLCD_voidSendData(0b00000110);
	/*set address of DDRAM */
	CLCD_voidSendCmnd(0x8F);
	CLCD_voidSendData(0);
}

void LCD_Gameball(u8 add)
{
	// if (x==1)
	// {
	/*set CGRAM address */
	CLCD_voidSendCmnd(0b01000000);
	CLCD_voidSendData(0b00000000);
	CLCD_voidSendData(0b00000100);
	CLCD_voidSendData(0b00001110);
	CLCD_voidSendData(0b00001110);
	CLCD_voidSendData(0b00001110);
	CLCD_voidSendData(0b00001110);
	CLCD_voidSendData(0b00000100);
	CLCD_voidSendData(0b00000000);
	/*set address of DDRAM */
	CLCD_voidSendCmnd(add);
	CLCD_voidSendData(0);
	//}
	/* else
	 {
		 CLCD_voidSendCmnd(0b01000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);
		 			CLCD_voidSendData(0b00000000);*/
	/*set address of DDRAM */
	/*CLCD_voidSendCmnd(add);
		 			CLCD_voidSendData(0);
	 }*/
}
